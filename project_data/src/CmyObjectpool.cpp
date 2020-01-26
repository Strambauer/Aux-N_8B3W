/*
 * CmyObjectpool.cpp
 *
 *  Created on: Nov 24, 2018
 *      Author: georg
 */

#include "CmyObjectpool.hpp"
#include "AuxN_8B3W_derived-cpp.h"



MyVtDisplay::MyVtDisplay()
    : mp_srcIdent (0)
    , mp_srcHandle (0)
    , pool_uploaded (0)
    , mui_activeMaskId (0xFFFF)
{

}

MyVtDisplay::~MyVtDisplay()
{
    if (mp_srcIdent)
    { // registered, so we need to deregister
        IsoAgLib::getIvtClientInstance(0).deregisterObjectPool(*mp_srcIdent);
        //IsoAgLib::getIisoTerminalInstance().deregisterIsoObjectPool( *mp_srcIdent );
    }
}

void MyVtDisplay::init(IsoAgLib::iIdentItem_c& ar_ident, IsoAgLib::iVtClientDataStorage_c& dataStorage)
{
    const char version[] ="00003";
    mp_srcHandle = IsoAgLib::getIvtClientInstance(0).initAndRegisterObjectPool( ar_ident, *this, version, dataStorage, RegisterPoolMode_MasterToAnyVt );
    if (mp_srcHandle)
    { // registering succeeded, store IdentItem for deregistration
        mp_srcIdent = &ar_ident;
    }
}

void MyVtDisplay::eventKeyCode (uint8_t aui8_keyActivationCode, uint16_t aui16_objId, uint16_t aui16_objIdMask, uint8_t aui8_keyCode, bool ab_wasButton)
{

}

void MyVtDisplay::eventNumericValue (uint16_t aui16_objId, uint8_t aui8_value, uint32_t aui32_value)
{

}

void MyVtDisplay::eventStringValue (uint16_t aui16_objId, uint8_t aui8_length, StreamInput_c &rc_streaminput, uint8_t aui8_unparsedBytes, bool b_isFirst, bool b_isLast)
{

}

void MyVtDisplay::eventObjectPoolUploadedSuccessfully (bool ab_wasLanguageUpdate, int8_t ai8_languageIndex, uint16_t aui16_languageCode)
{
    printf("upload of Object Pool successfull!\r\n");
    pool_uploaded = 1;
}

void MyVtDisplay::eventEnterSafeState()
{

}

void MyVtDisplay::aux2AssignmentChanged(IsoAgLib::iVtObjectAuxiliaryFunction2_c & funct)
{
    printf("AUX-N Assignmetn changed!!\r\n");
}




void MyVtDisplay::UploadError(UploadErrorData  a_errorData )
{
    printf("Upload error!\r\n");
}

void MyVtDisplay::eventVtStatusMsg()
{
    if ( 0 != mp_srcHandle ) {
        const uint16_t amId = mp_srcHandle->getVtServerInst().getVtState().dataAlarmMask;
        if ( amId != mui_activeMaskId )
        { // a (macro-triggered) mask change has been detected
            maskChanged( amId );
        }
    }
}

void MyVtDisplay::maskChanged( uint16_t aui_activeMaskId )
{
    mui_activeMaskId = aui_activeMaskId;
}

bool MyVtDisplay::isVtActive()
{
    return mp_srcHandle->isVtActive() && pool_uploaded;
}

void MyVtDisplay::setAuxBoolState(uint8_t aux_Id, bool state)
{
    switch(aux_Id)
    {
    case 0:
        iVtObjectButton1.setValue(state);
        if(state && state != old_B1_state)
        {
            printf("Button 1 presse!\r\n");
        }
        else if(!state && state != old_B1_state)
        {
            printf("Button 1 released!\r\n");
        }
        old_B1_state = state;
        break;
    case 1:
        iVtObjectButton2.setValue(state);
        if(state && state != old_B2_state)
        {
            printf("Button 2 presse!\r\n");
        }
        else if(!state && state != old_B2_state)
        {
            printf("Button 2 released!\r\n");
        }
        old_B2_state = state;
        break;
    case 2:
        iVtObjectButton3.setValue(state);
        if(state && state != old_B3_state)
        {
            printf("Button 3 presse!\r\n");
        }
        else if(!state && state != old_B3_state)
        {
            printf("Button 3 released!\r\n");
        }
        old_B3_state = state;
        break;
    case 3:
        iVtObjectButton4.setValue(state);
        if(state && state != old_B4_state)
        {
            printf("Button 4 presse!\r\n");
        }
        else if(!state && state != old_B4_state)
        {
            printf("Button 4 released!\r\n");
        }
        old_B4_state = state;
        break;
    case 4:
        if(state && state != old_B5_state)
        {
            printf("Button 5 presse!\r\n");
        }
        else if(!state && state != old_B5_state)
        {
            printf("Button 5 released!\r\n");
        }
        old_B5_state = state;
        break;
    case 5:
        iVtObjectButton6.setValue(state);
        if(state && state != old_B6_state)
        {
            printf("Button 6 presse!\r\n");
        }
        else if(!state && state != old_B6_state)
        {
            printf("Button 6 released!\r\n");
        }
        old_B6_state = state;
        break;
    case 6:
        iVtObjectButton7.setValue(state);
        if(state && state != old_B7_state)
        {
            printf("Button 7 presse!\r\n");
        }
        else if(!state && state != old_B7_state)
        {
            printf("Button 7 released!\r\n");
        }
        old_B7_state = state;
        break;
    case 7:
        iVtObjectButton8.setValue(state);
        if(state && state != old_B8_state)
        {
            printf("Button 8 presse!\r\n");
        }
        else if(!state && state != old_B8_state)
        {
            printf("Button 8 released!\r\n");
        }
        old_B8_state = state;
        break;
    case 8:
        iVtObjectWippe1links.setValue(state);
        if(state && state != old_W1l_state)
        {
            printf("Wippe 1 links presse!\r\n");
        }
        else if(!state && state != old_W1l_state)
        {
            printf("Wippe 1 links released!\r\n");
        }
        old_W1l_state = state;
        break;
    case 9:
        iVtObjectWippe1rechts.setValue(state);
        if(state && state != old_W1r_state)
        {
            printf("Wippe 1 rechts presse!\r\n");
        }
        else if(!state && state != old_W1r_state)
        {
            printf("Wippe 1 rechts released!\r\n");
        }
        old_W1r_state = state;
        break;
    case 10:
        iVtObjectWippe2oben.setValue(state);
        if(state && state != old_W2o_state)
        {
            printf("Wippe 2 oben presse!\r\n");
        }
        else if(!state && state != old_W2o_state)
        {
            printf("Wippe 2 oben released!\r\n");
        }
        old_W2o_state = state;
        break;
    case 11:
        iVtObjectWippe2unten.setValue(state);
        if(state && state != old_W2u_state)
        {
            printf("Wippe 2 unten presse!\r\n");
        }
        else if(!state && state != old_W2u_state)
        {
            printf("Wippe 2 unten released!\r\n");
        }
        old_W2u_state = state;
        break;
    case 12:
        iVtObjectWippe3links.setValue(state);
        if(state && state != old_W3l_state)
        {
            printf("Wippe 3 links presse!\r\n");
        }
        else if(!state && state != old_W3l_state)
        {
            printf("Wippe 3 links released!\r\n");
        }
        old_W3l_state = state;
        break;
    case 13:
        iVtObjectWippe3rechts.setValue(state);
        if(state && state != old_W3r_state)
        {
            printf("Wippe 3 rechts presse!\r\n");
        }
        else if(!state && state != old_W3r_state)
        {
            printf("Wippe 3 rechts released!\r\n");
        }
        old_W3r_state = state;
        break;
    }
}

