# Motor Controller Firmware

- Enforces **hardware RPM ceiling** and **watchdog**.
- Requires a **normally-closed E-stop** on `ESTOP_PIN` (default D7).
- Streams telemetry JSON lines: `{"rpm": <float>, "angle": <float>, "fault": <bool|string>}`

## Flashing
- Open `main.ino` in Arduino IDE / PlatformIO.
- Select your board (Uno/Teensy/etc.) and flash.

## Safety
- Test E-stop first (should cut output immediately).
- Verify direction, stall behavior, and ramp limits before mounting a person.
