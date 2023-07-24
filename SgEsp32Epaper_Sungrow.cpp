#include "Arduino.h"
#include "SgEsp32Epaper_Sungrow.h"
#include "SgEsp32Epaper_Cfg.h"
#include "SgEsp32Epaper_Eeprom.h"


SgEsp32Epaper_Sungrow::SgEsp32Epaper_Sungrow()
 : _Remote(MODBUS_SERVER_IP_1_OCT, MODBUS_SERVER_IP_2_OCT, MODBUS_SERVER_IP_3_OCT, MODBUS_SERVER_IP_4_OCT)
{
  _Modbus.client();
  delay(300);
  _Modbus.connect(_Remote);
  delay(300);

  if( !_Modbus.isConnected(_Remote) )
  {
    Serial.println("Connection to MODBUS server failed!");
  }
}

long SgEsp32Epaper_Sungrow::ReadPowerFromPv()
{
  uint16_t res[2];
  uint16_t trans;

  Serial.println("ReadPowerFromPv - Holding Register 13033");

  trans = _Modbus.readIreg(_Remote, 13033, res, 2, nullptr, 0x1);  // Initiate Read from Modbus Server
  while(_Modbus.isTransaction(trans)) 
  {  // Check if transaction is active
    _Modbus.task();
    delay(250);
  }
  Serial.print( res[0] + (res[1]<<16) );
  Serial.println(" W");

  return (long)( res[0] + (res[1]<<16) );
}


unsigned long SgEsp32Epaper_Sungrow::ReadPowerFromPvToHome()
{
  uint16_t res[2];
  uint16_t trans;

  Serial.println("ReadPowerFromPvToHome - Holding Register 13007");

  trans = _Modbus.readIreg(_Remote, 13007, res, 2, nullptr, 0x1);  // Initiate Read from Modbus Server
  while(_Modbus.isTransaction(trans)) 
  {  // Check if transaction is active
    _Modbus.task();
    delay(250);
  }
  Serial.print( res[0] + (res[1]<<16) );
  Serial.println(" W");

  return (unsigned long)( res[0] + (res[1]<<16) );
}


long SgEsp32Epaper_Sungrow::ReadPowerFromPvToGrid()
{
  uint16_t res[2];
  uint16_t trans;

  Serial.println("ReadPowerFromPvToGrid - Holding Register 13009");

  trans = _Modbus.readIreg(_Remote, 13009, res, 2, nullptr, 0x1);  // Initiate Read from Modbus Server
  while(_Modbus.isTransaction(trans)) 
  {  // Check if transaction is active
    _Modbus.task();
    delay(250);
  }
  Serial.print( res[0] + (res[1]<<16) );
  Serial.println(" W");

  return (long)( res[0] + (res[1]<<16) );
}


bool SgEsp32Epaper_Sungrow::IsPvGenerating()
{
  uint16_t res;
  uint16_t trans;
  bool isGenerating;

  Serial.println("IsPvGenerating - Holding Register 13009");

  trans = _Modbus.readIreg(_Remote, 13000, &res, 1, nullptr, 0x1);  // Initiate Read from Modbus Server
  while(_Modbus.isTransaction(trans)) 
  {  // Check if transaction is active
    _Modbus.task();
    delay(250);
  }

  if( ( res & 0x1 ) == 0 )
  {
    isGenerating = false;
    Serial.println("not generating");
  }
  else
  {
    isGenerating = true;
    Serial.println("generating");
  }

  return isGenerating;
}


bool SgEsp32Epaper_Sungrow::IsPvAvailable()
{
  uint16_t res;
  uint16_t trans;
  uint16_t timeout;
  bool isActive;

  isActive = true;
  timeout = 100; /* 100 * 100ms = 10s */

  trans = _Modbus.readIreg(_Remote, 13000, &res, 1, nullptr, 0x1);  // Initiate Read from Modbus Server
  while(_Modbus.isTransaction(trans)) 
  {  // Check if transaction is active
    _Modbus.task();
    delay(100);

    timeout--;
    if(timeout==0)
    {
      isActive = false;
      Serial.println("Modbus Timeout");
      break;
    }
  }

  return isActive;
}


double SgEsp32Epaper_Sungrow::ReadPowerString1()
{
  uint16_t res_V;
  uint16_t res_A;
  uint16_t trans;

  Serial.println("ReadPowerString1 - Holding Register 5010");

  trans = _Modbus.readIreg(_Remote, 5010, &res_V, 1, nullptr, 0x1);  // Initiate Read from Modbus Server
  while(_Modbus.isTransaction(trans)) 
  {  // Check if transaction is active
    _Modbus.task();
    delay(250);
  }

  Serial.println("ReadPowerString1 - Holding Register 5011");

  trans = _Modbus.readIreg(_Remote, 5011, &res_A, 1, nullptr, 0x1);  // Initiate Read from Modbus Server
  while(_Modbus.isTransaction(trans)) 
  {  // Check if transaction is active
    _Modbus.task();
    delay(250);
  }

  Serial.print( (res_V * 0.1) * (res_A * 0.1) );
  Serial.println(" W");

  return ( ((double)res_V * 0.1) * ((double)res_A * 0.1) );
}



double SgEsp32Epaper_Sungrow::ReadPowerString2()
{
  uint16_t res_V;
  uint16_t res_A;
  uint16_t trans;

  Serial.println("ReadPowerString1 - Holding Register 5012");

  trans = _Modbus.readIreg(_Remote, 5012, &res_V, 1, nullptr, 0x1);  // Initiate Read from Modbus Server
  while(_Modbus.isTransaction(trans)) 
  {  // Check if transaction is active
    _Modbus.task();
    delay(250);
  }

  Serial.println("ReadPowerString1 - Holding Register 5013");

  trans = _Modbus.readIreg(_Remote, 5013, &res_A, 1, nullptr, 0x1);  // Initiate Read from Modbus Server
  while(_Modbus.isTransaction(trans)) 
  {  // Check if transaction is active
    _Modbus.task();
    delay(250);
  }

  Serial.print( (res_V * 0.1) * (res_A * 0.1) );
  Serial.println(" W");

  return ( ((double)res_V * 0.1) * ((double)res_A * 0.1) );
}

double SgEsp32Epaper_Sungrow::ReadDailyUsedEnergy()
{
  uint16_t res;
  uint16_t trans;

  Serial.println("ReadDailyUsedEnergy - Holding Register 13016");

  trans = _Modbus.readIreg(_Remote, 13016, &res, 1, nullptr, 0x1);  // Initiate Read from Modbus Server
  while(_Modbus.isTransaction(trans)) 
  {  // Check if transaction is active
    _Modbus.task();
    delay(250);
  }
  Serial.print( res * 0.1 );
  Serial.println(" kW/h");

  return (double)( res * 0.1 );
}

double SgEsp32Epaper_Sungrow::ReadDailyExportedEnergy()
{
  uint16_t res;
  uint16_t trans;

  Serial.println("ReadDailyExportedEnergy - Holding Register 13004");

  trans = _Modbus.readIreg(_Remote, 13004, &res, 1, nullptr, 0x1);  // Initiate Read from Modbus Server
  while(_Modbus.isTransaction(trans)) 
  {  // Check if transaction is active
    _Modbus.task();
    delay(250);
  }
  Serial.print( res * 0.1 );
  Serial.println(" kW/h");

  return (double)( res * 0.1 );
}

double SgEsp32Epaper_Sungrow::ReadDailyImportedEnergy()
{
  uint16_t res;
  uint16_t trans;

  Serial.println("ReadDailyImportedEnergy - Holding Register 13035");

  trans = _Modbus.readIreg(_Remote, 13035, &res, 1, nullptr, 0x1);  // Initiate Read from Modbus Server
  while(_Modbus.isTransaction(trans)) 
  {  // Check if transaction is active
    _Modbus.task();
    delay(250);
  }
  Serial.print( res * 0.1 );
  Serial.println(" kW/h");

  return (double)( res * 0.1 );
}

double SgEsp32Epaper_Sungrow::ReadTotalUsedEnergy()
{
  uint16_t res[2];
  uint16_t trans;

  Serial.println("ReadTotalUsedEnergy - Holding Register 13017");

  trans = _Modbus.readIreg(_Remote, 13017, res, 2, nullptr, 0x1);  // Initiate Read from Modbus Server
  while(_Modbus.isTransaction(trans)) 
  {  // Check if transaction is active
    _Modbus.task();
    delay(250);
  }
  Serial.print( ( res[0] + (res[1]<<16) ) * 0.1 );
  Serial.println(" kW/h");

  return (double)( ( res[0] + (res[1]<<16) ) * 0.1 );
}


double SgEsp32Epaper_Sungrow::ReadTotalExportedEnergy()
{
  uint16_t res[2];
  uint16_t trans;

  Serial.println("ReadTotalExportedEnergy - Holding Register 13005");

  trans = _Modbus.readIreg(_Remote, 13005, res, 2, nullptr, 0x1);  // Initiate Read from Modbus Server
  while(_Modbus.isTransaction(trans)) 
  {  // Check if transaction is active
    _Modbus.task();
    delay(250);
  }
  Serial.print( ( res[0] + (res[1]<<16) ) * 0.1 );
  Serial.println(" kW/h");

  return (double)( ( res[0] + (res[1]<<16) ) * 0.1 );
}

void SgEsp32Epaper_Sungrow::Disconnect()
{
  _Modbus.disconnect(_Remote);

  while( _Modbus.isConnected(_Remote) )
  {
    delay(100);
  }

  Serial.println("Connection to MODBUS server closed!");
}
