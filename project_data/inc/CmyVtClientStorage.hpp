/*
 * CmyVtClientStorage.hpp
 *
 *  Created on: Nov 24, 2018
 *      Author: georg
 */

#ifndef INC_CMYVTCLIENTSTORAGE_HPP_
#define INC_CMYVTCLIENTSTORAGE_HPP_

#include <IsoAgLib/comm/iisobus_c.h>
#include <IsoAgLib/comm/Part6_VirtualTerminal_Client/ivtclient_c.h>
#include <IsoAgLib/comm/Part6_VirtualTerminal_Client/ivttypes.h>

#include <list>

class CmyVtClientStorage : public IsoAgLib::iVtClientDataStorage_c
{
public:
	CmyVtClientStorage();
	virtual ~CmyVtClientStorage();

	void loadPreferredVt( IsoAgLib::iIsoName_c &arc_isoname, uint8_t &arui8_boottime_s );

    void storePreferredVt( const IsoAgLib::iIsoName_c &arc_isoname, uint8_t aui8_bootTime);

    void loadPreferredAux2Assignment( IsoAgLib::iAux2Assignment_c& assignment );

    void storePreferredAux2Assignment( uint16_t a_functionUid, const STL_NAMESPACE::list<IsoAgLib::iAux2InputData>& a_ref_preferred_assignment );
};



#endif /* INC_CMYVTCLIENTSTORAGE_HPP_ */
