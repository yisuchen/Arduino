#pragma once
//
//    FILE: printHelpers.h
//  AUTHOR: Rob Tillaart
//    DATE: 2018-01-21
// VERSION: 0.4.0
// PUPROSE: Arduino library to help formatting for printing.
//     URL: https://github.com/RobTillaart/printHelpers


#include "Arduino.h"
#include "stdlib.h"


#define PRINTHELPERS_VERSION      (F("0.4.0"))


//  global buffer used by all functions so no static buffer in every function
//  is needed ==> results need to be printed/copied asap
//  not usable in multi-threading environments (use with care)
//
//  24 is a pretty safe minimum
//
#ifndef PRINTBUFFERSIZE
#define PRINTBUFFERSIZE       66
#endif



////////////////////////////////////////////////////////////
//
//  print64()
//
//  print64 note
//  buffer size 66 will work for base 2 -36
//  buffer size 34 will work for base 4 -36
//  buffer size 24 will work for base 8 -36
//  buffer size 22 will work for base 10 - 36

char * print64(int64_t value, uint8_t base = 10);

char * print64(uint64_t value, uint8_t base = 10);


////////////////////////////////////////////////////////////
//
//  Scientific + Engineering notation
//
//  typical buffer size for 8 byte double is 22 bytes
//  15 bytes mantissa, sign dot E-xxx
//  em = exponentMultiple.
char * scieng(double value, uint8_t decimals, uint8_t em);

char * eng(double value, uint8_t decimals);  //  em == 3

char * sci(double value, uint8_t decimals);  //  em == 1

void sci(Stream &str, double value, uint8_t decimals);


////////////////////////////////////////////////////////////
//
//  toBytes()
//
//  official support to UDA == 1024^12
//  kilo mega giga tera peta exa (1024^6)
//  zetta yotta xona weka vunda uda (1024^12)
//
//  (treda Byte == TDB is the next one and it is 2 char
//  so code wise difficult and as it is seldom used, support stops there.
//
//  To have some support the code uses lowercase for the next 8 levels
//  treda sorta rinta quexa pepta ocha nena minga luma (1024 ^21 ~~ 10^63)
char * toBytes(double value, uint8_t decimals = 2);


////////////////////////////////////////////////////////////
//
//  hex()
//
//  always leading zero's - no prefix - no separators
//  cast if needed.
char * hex(uint64_t value, uint8_t digits = 16);
char * hex(uint32_t value, uint8_t digits = 8);
char * hex(uint16_t value, uint8_t digits = 4);
char * hex(uint8_t value, uint8_t digits = 2);


////////////////////////////////////////////////////////////
//
//  BIN
//
//  always leading zero's - no prefix - no separators
//  cast if needed.
char * bin(uint64_t value, uint8_t digits = 64);
char * bin(uint32_t value, uint8_t digits = 32);
char * bin(uint16_t value, uint8_t digits = 16);
char * bin(uint8_t value, uint8_t digits = 8);


////////////////////////////////////////////////////////////
//
//  toRoman()
//
//  value should be in range 1..9999
//  values 10K-100M are experimental (see readme.md)
char * toRoman(uint32_t value);


//  -- END OF FILE --

