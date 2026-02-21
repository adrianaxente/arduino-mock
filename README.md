# Arduino Mock Library for PlatformIO

A simple, header-only mock library for the core Arduino API. This library is intended to be used with the [PlatformIO](https://platformio.org/) `native` development platform and the [Google Test](https://github.com/google/googletest) framework.

It allows you to compile and run unit tests for your Arduino source code on your host machine, without needing to upload to physical hardware.

## Features

This library provides mock implementations for the following Arduino components:
- `Arduino.h` (digitalRead, digitalWrite, pinMode, etc.)
- `Serial.h`
- `SPI.h`
- `Wire.h` (I2C)
- `EEPROM.h`
- `WiFi.h`
- `Spark.h`
- `Stream.h`
- `Print.h`

## How to Use

To use this library for your unit tests, you need to configure your `platformio.ini` to use the `native` platform and Google Test.

### 1. Configure `platformio.ini`

Add a test environment to your `platformio.ini` file that specifies the `native` platform and sets `googletest` as the test framework.

```ini
[env:test_native]
platform = native
framework = googletest
lib_deps =
    adrianaxente/arduino-mock
    google/googletest
```

### 2. Write Your Tests

Create your test files in the `test` directory. Your test code should include `gtest/gtest.h` and the specific Arduino headers your code uses. The PlatformIO build system will automatically use the mock versions from this library when building for the `native` platform.

**Example (`test/test_my_code.cpp`):**

```cpp
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Arduino.h"

using ::testing::Return;

TEST(digitalRead, 2)
{
  ArduinoMock *arduinoMock = arduinoMockInstance();
  EXPECT_CALL(*arduinoMock, digitalRead(2)).WillOnce(Return(1));
  digitalRead(2);
  releaseArduinoMock();
}

TEST(delay, normal)
{
  ArduinoMock *arduinoMock = arduinoMockInstance();
  EXPECT_CALL(*arduinoMock, delay(1));
  delay(1);
  releaseArduinoMock();
}

int main(int argc, char **argv)
{
    // 1. Initialize GoogleTest
    ::testing::InitGoogleTest(&argc, argv);

    // 2. Initialize GoogleMock (Critical for arduino-mock to work)
    ::testing::InitGoogleMock(&argc, argv);

    // 3. Run all tests found in your files
    return RUN_ALL_TESTS();
}

```

### 3. Run the Tests

Execute the tests from your terminal using the PlatformIO CLI:

```shell
platformio test -e test_native
```

This command will compile your source code and the tests using your native compiler (e.g., GCC, Clang) and run the resulting executable.