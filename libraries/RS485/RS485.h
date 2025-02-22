#pragma once
//
//    FILE: RS485.h
//  AUTHOR: Rob Tillaart
//    DATE: 30-okt-2017
// VERSION: 0.2.4
// PURPOSE: Arduino library for RS485 modules
//     URL: https://github.com/RobTillaart/RS485


#include "Arduino.h"
#include "ASCII_CONTROL.h"

#define RS485_LIB_VERSION        (F("0.2.4"))


class RS485 : public Stream
{
public:
  RS485(Stream * stream, uint8_t sendPin, uint8_t deviceID = 0);

  //  baudRate must match Serial baudRate
  //  micros are needed before RS485 stream may be reset
  //  to (default) receiving mode.
  void     setMicrosPerByte(uint32_t baudRate);
  uint32_t getMicrosPerByte() { return _microsPerByte; };

  uint8_t  getDeviceID()      { return _deviceID; };

  //      Stream interface
  int     available();
  int     read();
  int     peek();
  void    flush();

  //      Write
  size_t  write(uint8_t c);
  size_t  write(char * array, uint8_t length);  //  wrapper
  size_t  write(uint8_t * array, uint8_t length);

  //      Mode functions
  inline void setTXmode() { digitalWrite(_sendPin, HIGH); };
  inline void setRXmode() { digitalWrite(_sendPin, LOW); };
  uint8_t     getMode()   { return digitalRead(_sendPin) == HIGH; };


  //  0.3.0  EXPERIMENTAL
  //  send ASCII encoded messages from one master to multiple clients.
  //       msg[] = 32..127
  //       len = 1..48 ?
  //
  //  should be a p2p network option.
  void    send(uint8_t receiverID, uint8_t msg[], uint8_t len);
  bool    receive(uint8_t &senderID, uint8_t msg[], uint8_t &len);


private:
  Stream   * _stream;
  uint8_t  _sendPin       = 0;
  uint8_t  _deviceID      = 0;
  uint16_t _microsPerByte = 1000;

  //  0.3.0
  uint8_t _bidx = 0;
  uint8_t _buffer[50];  // internal receive buffer
};


//  -- END OF FILE --

