# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https.keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https.semver.org/spec/v2.0.0.html).

## [1.1.0] - 2026-02-27

### Added

- Support for `delayMicroseconds`
- Support for NiceMock<> (added arduinoMockInstanceNice() function)
- Support for StrictMock<> (added arduinoMockInstanceStrict() function)


## [1.0.0] - 2026-02-21

### Added

- Initial release of the arduino-mock library.
- Mocks for core Arduino functionalities:
    - Arduino.h
    - EEPROM.h
    - pgmspace.h
    - Print.h
    - Serial.h
    - serialHelper.h
    - Spark.h
    - SPI.h
    - Stream.h
    - WiFi.h
    - Wire.h
- Unit tests for all mocked functionalities.
