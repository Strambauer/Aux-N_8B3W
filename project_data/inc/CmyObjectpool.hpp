/*
 * CmyObjectpool.hpp
 *
 *  Created on: Nov 24, 2018
 *      Author: georg
 */

#ifndef INC_CMYOBJECTPOOL_HPP_
#define INC_CMYOBJECTPOOL_HPP_

#include <IsoAgLib/comm/iisobus_c.h>

#include <IsoAgLib/comm/Part6_VirtualTerminal_Client/ivtclientconnection_c.h>
#include <IsoAgLib/comm/Part6_VirtualTerminal_Client/ivtobjectauxiliaryfunction2_c.h>

#include "AuxN_8B3W_derived-h.h"


class MyVtDisplay : public iObjectPool_AuxN_8B3W_c
{
public:
	MyVtDisplay();
	~MyVtDisplay();

	void init(IsoAgLib::iIdentItem_c& ar_ident, IsoAgLib::iVtClientDataStorage_c& dataStorage);

	  void eventKeyCode (uint8_t aui8_keyActivationCode, uint16_t aui16_objId, uint16_t aui16_objIdMask, uint8_t aui8_keyCode, bool ab_wasButton);

	  void eventNumericValue (uint16_t aui16_objId, uint8_t aui8_value, uint32_t aui32_value);

	  void eventStringValue (uint16_t aui16_objId, uint8_t aui8_length, StreamInput_c &rc_streaminput, uint8_t aui8_unparsedBytes, bool b_isFirst, bool b_isLast);

	  void eventObjectPoolUploadedSuccessfully (bool ab_wasLanguageUpdate, int8_t ai8_languageIndex, uint16_t aui16_languageCode);

	  void eventEnterSafeState();

	  void UploadError(UploadErrorData /* a_errorData */);

	  void eventVtStatusMsg();

      void aux2AssignmentChanged(IsoAgLib::iVtObjectAuxiliaryFunction2_c &);

	  bool isVtActive();

	  void handleNewTimeValues( uint8_t aui_h, uint8_t aui_m, uint8_t aui_s );

	  void maskChanged( uint16_t aui_activeMaskId );

	  void setMetaInfo();

      void setAuxBoolState(uint8_t aux_Id, bool state);


private:
    IsoAgLib::iVtClientConnection_c* mp_srcHandle;
    IsoAgLib::iIdentItem_c* mp_srcIdent;

    uint16_t mui_activeMaskId;
    uint8_t pool_uploaded;

    bool old_B1_state;
    bool old_B2_state;
    bool old_B3_state;
    bool old_B4_state;
    bool old_B5_state;
    bool old_B6_state;
    bool old_B7_state;
    bool old_B8_state;

    bool old_W1l_state;
    bool old_W1r_state;
    bool old_W2o_state;
    bool old_W2u_state;
    bool old_W3l_state;
    bool old_W3r_state;

};


#endif /* INC_CMYOBJECTPOOL_HPP_ */
