#include <Arduino.h>
#include <ArduinoJson.h>

const float MAX_RPM = 40.0;
const uint8_t ESTOP_PIN = 7;
unsigned long lastCmdMs = 0;

void setup() {
  Serial.begin(115200);
  pinMode(ESTOP_PIN, INPUT_PULLUP);
  // TODO: init motor driver (pins, PWM, etc.)
}

void applyRPM(float rpm) {
  // TODO: implement driver control mapping + ramp limit
}

void loop() {
  // 1) E-Stop
  if (digitalRead(ESTOP_PIN) == HIGH) {
    applyRPM(0);
    StaticJsonDocument<128> jb; jb["fault"]="ESTOP";
    serializeJson(jb, Serial); Serial.println();
    delay(10);
    return;
  }

  // 2) Watchdog (300ms)
  if (millis() - lastCmdMs > 300) applyRPM(0);

  // 3) Telemetry
  StaticJsonDocument<128> jt;
  jt["rpm"] = 0;    // TODO: read encoder
  jt["angle"] = 0;  // TODO: compute angle
  jt["fault"] = false;
  serializeJson(jt, Serial); Serial.println();

  // 4) Command in
  if (Serial.available()) {
    String line = Serial.readStringUntil('\n');
    StaticJsonDocument<128> jd;
    if (deserializeJson(jd, line) == DeserializationError::Ok) {
      float rpm = jd["rpm"] | 0.0;
      rpm = constrain(rpm, -MAX_RPM, MAX_RPM);
      applyRPM(rpm);
      lastCmdMs = millis();
    }
  }
  delay(10);
}
