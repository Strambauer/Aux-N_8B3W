#include "CwiringPiInput.hpp"

CwiringPiInput::CwiringPiInput(int id, int debounceCnt)
    :state(false),
      stateOld(false),
      cntOn(0),
      cntOff(0),
      m_debounceCnt(debounceCnt),
      m_id(id)
{
    pinMode(m_id,INPUT);
    pullUpDnControl(m_id, PUD_UP);
}

CwiringPiInput::edge CwiringPiInput::readStateChange()
{
    edge ret = none;
    this->uptdateInput();
    if(state && !stateOld)
    {
        ret = rising;
    }
    else if (!state && stateOld)
    {
        ret = falling;
    }
    else
    {
        ret = none;
    }
    stateOld = state;
    return ret;
}

bool CwiringPiInput::getState()
{
    this->uptdateInput();
    return state;
}

void CwiringPiInput::uptdateInput()
{
    bool in = !digitalRead(m_id);
    if(in)
    {
        if(cntOn <= m_debounceCnt)
        {
        cntOn++;
        }
    }
    else
    {
        cntOn = 0;
    }
    if(!in)
    {
        if(cntOff <= m_debounceCnt)
        {
            cntOff++;
        }
    }
    else
    {
        cntOff = 0;
    }

    if(cntOn > m_debounceCnt)
    {
        state = true;
    }
    if(cntOff > m_debounceCnt)
    {
        state = false;
    }
}
