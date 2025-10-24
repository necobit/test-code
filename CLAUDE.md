# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is a PlatformIO-based embedded project for the M5Stack StampS3 board (ESP32-S3 microcontroller). The project uses the Arduino framework and M5Unified library.

## Build System

This project uses PlatformIO, not Arduino IDE. Commands must be run through PlatformIO CLI or VS Code PlatformIO extension.

### Common Commands

Build the project:
```bash
platformio run
```

Build and upload to device:
```bash
platformio run --target upload
```

Open serial monitor (115200 baud):
```bash
platformio device monitor
```

Build, upload, and monitor in one command:
```bash
platformio run --target upload && platformio device monitor
```

Clean build artifacts:
```bash
platformio run --target clean
```

## Hardware Configuration

**Target Board:** M5Stack StampS3 (ESP32-S3)
**Platform:** espressif32
**Framework:** Arduino

### Key Board Features
- USB CDC enabled on boot (for serial communication over USB)
- PSRAM available
- Partition scheme: huge_app.csv (for larger applications)
- Filesystem: SPIFFS
- Flash mode: QIO with OPI PSRAM

## Dependencies

Primary library:
- **M5Unified** (v0.2.7+): Unified library for M5Stack devices, provides display, button, and sensor abstractions

The M5Unified library automatically pulls in M5GFX for graphics operations.

## Code Structure

**src/main.cpp**: Entry point with Arduino setup() and loop() functions. Currently includes SPIFFS and M5Unified headers.

## Development Notes

- Serial monitor baud rate is set to 115200
- The board has PSRAM available, useful for graphics buffers or large data structures
- SPIFFS filesystem is available for storing files on flash memory
- USB CDC is enabled, so serial communication works over USB without separate USB-to-serial adapter
