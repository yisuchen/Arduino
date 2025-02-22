# Change Log PCA9685

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](http://keepachangelog.com/)
and this project adheres to [Semantic Versioning](http://semver.org/).

## [0.4.1] - 2022-11-19
- add RP2040 in build-CI
- add changelog.md


## [0.4.0] - 2022-06-09
- breaking changes (sync with pca9634)
- rename reset() to configure()
- add mode1 and mode2 parameter to configure.
- add SUB CALL and ALL CALL functions.
- update documentation.
- renamed PCA9685_MODE2_STOP to PCA9685_MODE2_ACK
- add mode parameters to begin()

----

## [0.3.4] - 2022-01-03
- add channelCount()

## [0.3.3] - 2021-12-23
- update library.json
- license
- readme
- minor edits

## [0.3.2] - 2021-01-14
- WireN support

## [0.3.1] - 2021-01-05
- Arduino-CI + unit test

## [0.3.0] - 2020-11-22
- fix setting frequency

----

## [0.2.3] - 2020-11-21
- fix digitalWrite (internal version only)

## [0.2.2] - 2020-09-21
- fix #1
- add getFrequency()

## [0.2.1] - 2020-06-19
- fix library.json

## [0.2.0] - 2020-05-25
- refactor; ESP32 begin(sda,scl)

----

## [0.1.1] - 2019-01-30
- testing && fixing

## [0.1.0] - 2021-12-02
- initial BETA version

