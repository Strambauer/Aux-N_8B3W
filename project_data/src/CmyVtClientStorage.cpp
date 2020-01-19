/*
 * CmyVtClientStorage.cpp
 *
 *  Created on: Nov 24, 2018
 *      Author: georg
 */

#include "CmyVtClientStorage.hpp"


CmyVtClientStorage::CmyVtClientStorage()
{

}
CmyVtClientStorage::~CmyVtClientStorage()
{

}

void CmyVtClientStorage::loadPreferredVt( IsoAgLib::iIsoName_c &arc_isoname, uint8_t &arui8_boottime_s )
{
    printf("loade Preferred Vt\r\n");
}

void CmyVtClientStorage::storePreferredVt( const IsoAgLib::iIsoName_c &arc_isoname, uint8_t aui8_bootTime)
{
    printf("store preferred Vt\r\n");
}

void CmyVtClientStorage::loadPreferredAux2Assignment( IsoAgLib::iAux2Assignment_c& assignment )
{
    printf("loade Aux2 Assignment\r\n");
}

void CmyVtClientStorage::storePreferredAux2Assignment( uint16_t a_functionUid, const STL_NAMESPACE::list<IsoAgLib::iAux2InputData>& a_ref_preferred_assignment )
{
    printf("store Aux2 Assignment\r\n");
    printf("Function UID: %i\r\n", a_functionUid);
    printf("input List has %i Elements.\r\n", a_ref_preferred_assignment.size());
}



