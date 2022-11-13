//
//    FILE: I2CKeyPad8x8.cpp
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.1
// PURPOSE: Arduino library for 8x8 or smaller KeyPad connected to an I2C PCF8575.
//     URL: https://github.com/RobTillaart/I2CKeyPad8x8
//
// HISTORY: see changelog.md


#include "I2CKeyPad8x8.h"


I2CKeyPad8x8::I2CKeyPad8x8(const uint8_t deviceAddress, TwoWire *wire)
{
  _lastKey = I2C_KEYPAD8x8_NOKEY;
  _address = deviceAddress;
  _wire    = wire;
}


#if defined(ESP8266) || defined(ESP32)
bool I2CKeyPad8x8::begin(uint8_t sda, uint8_t scl)
{
  _wire->begin(sda, scl);
  //  enable interrupts
  _read(0xFF00);
  return isConnected();
}
#endif


bool I2CKeyPad8x8::begin()
{
  _wire->begin();
  //  enable interrupts
  _read(0xFF00);
  return isConnected();
}


uint8_t I2CKeyPad8x8::getKey()
{
  //  key = row + 8 x col
  uint8_t key = 0;

  //  mask = 8 rows as input pull up, 8 columns as output
  uint16_t rows = _read(0xFF00);

  //  check if single line has gone low.
  if (rows == 0xFF00)      return I2C_KEYPAD8x8_NOKEY;
  else if (rows == 0xFE00) key = 0;
  else if (rows == 0xFD00) key = 1;
  else if (rows == 0xFB00) key = 2;
  else if (rows == 0xF700) key = 3;
  else if (rows == 0xEF00) key = 4;
  else if (rows == 0xDF00) key = 5;
  else if (rows == 0xBF00) key = 6;
  else if (rows == 0x7F00) key = 7;
  else return I2C_KEYPAD8x8_FAIL;

  // 8 columns as input pull up, 8 rows as output
  uint16_t cols = _read(0x00FF);
  // check if single line has gone low.
  if (cols == 0x00FF)      return I2C_KEYPAD8x8_NOKEY;
  else if (cols == 0x00FE) key += 0;
  else if (cols == 0x00FD) key += 8;
  else if (cols == 0x00FB) key += 16;
  else if (cols == 0x00F7) key += 24;
  else if (cols == 0x00EF) key += 32;
  else if (cols == 0x00DF) key += 40;
  else if (cols == 0x00BF) key += 48;
  else if (cols == 0x007F) key += 56;
  else return I2C_KEYPAD8x8_FAIL;

  _lastKey = key;

  return key;   // 0..65
}


uint8_t I2CKeyPad8x8::getLastKey()   
{ 
  return _lastKey;
};


//  to check "press any key"
bool I2CKeyPad8x8::isPressed()
{
  uint16_t a = _read(0xFF00);
  if (a == 0xFF00) return false;
  return (a != 0xFF00);
}


bool I2CKeyPad8x8::isConnected()
{
  _wire->beginTransmission(_address);
  return (_wire->endTransmission() == 0);
}


uint8_t I2CKeyPad8x8::getChar()
{ 
  return _keyMap[getKey()]; 
};


uint8_t I2CKeyPad8x8::getLastChar()
{ 
  return _keyMap[_lastKey]; 
};


void I2CKeyPad8x8::loadKeyMap(char * keyMap)
{
  _keyMap = keyMap;
}


//////////////////////////////////////////////////////
//
//  PROTECTED
//
uint16_t I2CKeyPad8x8::_read(uint16_t mask)
{
  //  improve the odds that IO will not interrupted.
  yield();

  _wire->beginTransmission(_address);
  _wire->write(mask >> 8);
  _wire->write(mask & 0xFF);
  if (_wire->endTransmission() != 0)
  {
    //  set communication error
    return 0xFFFF;
  }
  _wire->requestFrom(_address, (uint8_t)2);
  uint16_t value = _wire->read() << 8;
  value += _wire->read();
  return value;
}


// -- END OF FILE --

