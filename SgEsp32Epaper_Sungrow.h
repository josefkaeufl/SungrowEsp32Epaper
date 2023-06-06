#ifndef SGESP32EPAPER_SUNGROW
#define SGESP32EPAPER_SUNGROW

#include "Arduino.h"
#include <WiFi.h>
#include <ModbusIP_ESP8266.h>



class SgEsp32Epaper_Sungrow
{
  public:
    SgEsp32Epaper_Sungrow();
    long          ReadPowerFromPv();
    unsigned long ReadPowerFromPvToHome();
    long          ReadPowerFromPvToGrid();
    double ReadPowerString1();
    double ReadPowerString2();
    bool IsPvGenerating();
    bool IsPvAvailable();
    double ReadDailyUsedEnergy();
    double ReadDailyExportedEnergy();
    double ReadDailyImportedEnergy();
    double ReadTotalUsedEnergy();
    double ReadTotalExportedEnergy();
  private:
    bool _ConnectWifi();
    IPAddress _Remote;
    ModbusTCP _Modbus;
    
};

#endif
