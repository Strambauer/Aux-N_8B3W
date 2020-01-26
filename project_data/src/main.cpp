
#include <unistd.h>
#include <stdio.h>
#include <time.h>

#include "IsoAgLib/comm/iisobus_c.h"
#include "IsoAgLib/scheduler/ischeduler_c.h"
#include "IsoAgLib/comm/Part5_NetworkManagement/iisomonitor_c.h"
#include "IsoAgLib/comm/Part5_NetworkManagement/iidentitem_c.h"

#include "CmyIdentDataStorage.hpp"
#include "CmyObjectpool.hpp"
#include "CmyVtClientStorage.hpp"
#include "CmyObjectpool.hpp"

#include "CwiringPiInput.hpp"

int main() {

    IsoAgLib::iIdentItem_c* item_mc;
    const IsoAgLib::iIsoName_c* iso_name_mc;

    const IsoAgLib::iIsoName_c iso_name_list[265];

    IsoAgLib::iIsoName_c test_iso_name;


    CmyIdentDataStorage* identDataStorage;

    CmyVtClientStorage* vtClientStorage;


    MyVtDisplay* objectPool;

    identDataStorage = new CmyIdentDataStorage();
    vtClientStorage = new CmyVtClientStorage();

    objectPool = new MyVtDisplay();

    item_mc = new IsoAgLib::iIdentItem_c();

    iso_name_mc = new IsoAgLib::iIsoName_c(true, 2, 0, 0, 66, 0x7FF, 0x004, 1, 1);


    IsoAgLib::getIIsoBusInstance(0).init(0);

    item_mc->init(*iso_name_mc, *identDataStorage, (int8_t) 1, iso_name_list, false);

    item_mc->setEcuIdentification("PartNr D", "Serial 0x001", "Cabin", "Aux_N","Strambauer","01");
    item_mc->setSwIdentification("Test AuxN");
    item_mc->setCertificationData(2018,
                                  IsoAgLib::CertificationRevisionNotAvailable,
                                  IsoAgLib::CertificationLabTypeNotAvailable,
                                  42,
                                  8
                                  );
    item_mc->setProductIdentification("PBS", "Strambauer", "Aux-N_8B3W");



    uint8_t monitorCnt = 0;
    uint8_t monitorCntOld = 0;

    uint8_t address_claimed_mc = false;


    if (! IsoAgLib::getIisoMonitorInstance(0).registerIdentItem(*item_mc))
    {
        printf("failed to register item!\r\n");
        return 0;
    }



    objectPool->init(*item_mc, *vtClientStorage);


    //IsoAgLib::getITractorInstance(0).registerImplement(*item);


    //IsoAgLib::getIsystemInstance().switchedOn();

    wiringPiSetup();

    CwiringPiInput inputButton1(27,20);
    CwiringPiInput inputButton2(28,20);
    CwiringPiInput inputButton3(24,20);
    CwiringPiInput inputButton4(22,20);
    CwiringPiInput inputButton5(4,20);
    CwiringPiInput inputButton6(6,20);
    CwiringPiInput inputButton7(2,20);
    CwiringPiInput inputButton8(0,20);
    CwiringPiInput inputWippe1links(29,20);
    CwiringPiInput inputWippe1rechts(25,20);
    CwiringPiInput inputWippe2oben(26,20);
    CwiringPiInput inputWippe2unten(5,20);
    CwiringPiInput inputWippe3links(3,20);
    CwiringPiInput inputwippe3rechts(1,20);

    volatile int i = 0;

    while (1) {
        i++;
        IsoAgLib::getISchedulerInstance().timeEvent();
        usleep(1000);

        monitorCnt = IsoAgLib::getIisoMonitorInstance(0).isoMemberCnt(true);

        if (monitorCnt != monitorCntOld) {
            monitorCntOld = monitorCnt;
            printf("Found %i IsoBus Nodes\r\n", monitorCnt);
            for(int j=0;j<monitorCnt;j++)
            {


                test_iso_name = IsoAgLib::getIisoMonitorInstance(0).isoMemberInd(j).isoName();

                printf("IsoBus Instacne %i\r\n", j);
                printf("OutputString: %s | ", test_iso_name.outputString());
                printf("Device Class %i | ", test_iso_name.devClass());
                printf("Function %i | ", test_iso_name.func());
                printf("Industrial Group %i \r\n", test_iso_name.indGroup());
            }
        }

        if(objectPool->isVtActive())
        {

            objectPool->setAuxBoolState(0,inputButton1.getState());
            objectPool->setAuxBoolState(1,inputButton2.getState());
            objectPool->setAuxBoolState(2,inputButton3.getState());
            objectPool->setAuxBoolState(3,inputButton4.getState());
            objectPool->setAuxBoolState(4,inputButton5.getState());
            objectPool->setAuxBoolState(5,inputButton6.getState());
            objectPool->setAuxBoolState(6,inputButton7.getState());
            objectPool->setAuxBoolState(7,inputButton8.getState());
            objectPool->setAuxBoolState(8,inputWippe1links.getState());
            objectPool->setAuxBoolState(9,inputWippe1rechts.getState());
            objectPool->setAuxBoolState(10,inputWippe2oben.getState());
            objectPool->setAuxBoolState(11,inputWippe2unten.getState());
            objectPool->setAuxBoolState(12,inputWippe3links.getState());
            objectPool->setAuxBoolState(13,inputwippe3rechts.getState());

        }

        if(address_claimed_mc != item_mc->isClaimedAddress())
        {
            address_claimed_mc = item_mc->isClaimedAddress();
            printf("address of MC Item is claimed!\r\n");
        }

        fflush(stdout);
    }
    return 0;
}
