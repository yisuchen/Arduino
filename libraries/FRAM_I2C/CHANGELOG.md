# Change Log FRAM_I2C
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](http://keepachangelog.com/)
and this project adheres to [Semantic Versioning](http://semver.org/).


## [0.5.0] - 2023-02-15
- add FRAM11 - 11 bit addresses
- add FRAM9 - 9 bit addresses
- update readme.md
- add example **FRAM9_test.ino**
- add example **FRAM11_test.ino**

----

## [0.4.3] - 2022-12-28
- add writeFloat(), readFloat()
- refactor
- add nano_every to build-ci  (test)
- update readme.md
- update license
- update Github actions to v3  (test)
- simplified changelog

## [0.4.2] - 2022-10-03
- FRAM_RINGBUFFER class - see FRAM_RINGBUFFER.md
- build-ci support for RP2040 pico
- updated documentation
- moved code from FRAM.h to FRAM.cpp

## [0.4.1] - 2022-09-24
- changed ESP32 **begin()** parameters to **int** to prevent link error.
  see https://github.com/RobTillaart/PCA9635/issues/17
- updated documentation

## [0.4.0] - 2022-05-02
- add **FRAM32** derived class to support the MB85RC1MT as it need 32 bits addressing. 
  This class uses 4 byte memory addresses internally.
  Note **FRAM32** can also address 16 bit FRAM devices.
- updated documentation

----

## [0.3.6] - 2022-05-02
- add **void sleep()** experimental.
- add **bool wakeup(trec = 400)** experimental. wakeup time of 400us. returns true if connected after call.
- add example **FRAM_sleep.ino**
- updated readme.md
- updated keywords.txt
- minor edits

## [0.3.5] - 2022-03-23
- add **uint32_t clear(uint8_t value = 0)**
- add **void setSizeBytes(uint32_t value)**
- added defines for size of known types for e.g. **void setSizeBytes(uint32_t value)**
- add \_sizeinBytes private var. Needed in clear a.o.
- **getSize()** automatically called in **begin()**
- updated example **FRAM_clear.ino**
- renamed private functions with \_
- updated readme.md

## [0.3.4] - 2022-03-16
- add **uint16_t writeObject(memaddr, &obj)** see #13
- add **uint16_t readObject(memaddr, &obj)** see #13
- add examples for write- and readObject()
- renamed releaseNotes.md => CHANGELOG.md
- some edits in readme.md

## [0.3.3] - 2022-02-08
- added **getSizeBytes()**
- created releaseNotes.md
- updated readme.md
- add example FRAM_logging.ino

## [0.3.2] - 2021-12-18
- update Arduino-CI,
- add badges in readme.md
- update library.json,
- update license,
- minor edits

## [0.3.1] - 2021-02-05
- fix #7 typo in .cpp

## [0.3.0] - 2021-01-13
- fix #2 ESP32
- add WireN support

----

## [0.2.3] - 2021-01-11
- fix getMetaData (kudos to PraxisSoft)

## [0.2.2] - 2020-12-23
- add Arduino-CI + unit test
- add **getWriteProtect()**

## [0.2.1] - 2020-06-10
- fix library.json

## [0.2.0] - 2020-04-30
- refactor,
- add writeProtectPin code

## [0.1.1] - 2019-07-31
- added support for Fujitsu 64Kbit MB85RC64T (kudos to ysoyipek)

## [0.1.0] - 2018-01-24
- initial version

