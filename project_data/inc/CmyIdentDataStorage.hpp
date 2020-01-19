/*
 * CmyIdentDataStorage.hpp
 *
 *  Created on: Nov 21, 2018
 *      Author: georg
 */

#ifndef SRC_CMYIDENTDATASTORAGE_HPP_
#define SRC_CMYIDENTDATASTORAGE_HPP_

#include "IsoAgLib/comm/Part5_NetworkManagement/iidentitem_c.h"

class CmyIdentDataStorage : public IsoAgLib::iIdentDataStorage_c
{
	public:

	CmyIdentDataStorage();

	virtual ~CmyIdentDataStorage();

    uint8_t loadSa();

    void storeSa( const uint8_t a_sa );

    void loadDtcs( IsoAgLib::iDtcContainer_c &arc_dtcContainer );

    void storeDtcs( const IsoAgLib::iDtcContainer_c &arc_dtcContainer );

};



#endif /* SRC_CMYIDENTDATASTORAGE_HPP_ */
