# Change Log PCA9634

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](http://keepachangelog.com/)
and this project adheres to [Semantic Versioning](http://semver.org/).


## [0.2.5] - 2023-01-19
- fix #22 update readme.md
- update GitHub actions
- update license
- minor edits (comments)


## [0.2.4] - 2022-11-19
- add RP2040 in build-CI
- add changelog.md

## [0.2.3] - 2022-09-11
- update documentation
- fix begin() for ESP32 ambiguity - See PCA9635 #17

## [0.2.2] - 2022-09-02
- add static I2C_SoftwareReset()

## [0.2.1] - 2022-05-30
- add mode parameters to begin()

## [0.2.0] - 2022-05-29
- breaking changes
- rename reset() to configure()
- add mode1 and mode2 parameter to configure.
- add SUB CALL and ALL CALL functions.
- update documentation.
- renamed PCA9634_MODE2_STOP to PCA9634_MODE2_ACK

----

## [0.1.2] - 2022-04-13
- issue #7 add constants and functions for mode registers.

## [0.1.1] - 2022-01-04
- minor fixes

## [0.1.0] - 2022-01-03
- initial version -- based upon 0.3.2 PCA9635

