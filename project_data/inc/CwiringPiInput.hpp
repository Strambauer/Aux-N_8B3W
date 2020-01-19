#ifndef CWIRINGPIINPUT_HPP
#define CWIRINGPIINPUT_HPP

#include "wiringPi.h"

class CwiringPiInput
{


public:
    enum edge
    {
        none = 0,
        rising = 1,
        falling = 2
    };

    CwiringPiInput(int id, int debounceCnt);

    //these functions have to be called cyclic
    edge readStateChange();      // returns state change since last call
    bool getState();            // true = state low, high = state pulled up

private:
    bool state;
    bool stateOld;
    int cntOn;
    int cntOff;
    int m_debounceCnt;
    int m_id;

    void uptdateInput();


};

#endif // CWIRINGPIINPUT_HPP

