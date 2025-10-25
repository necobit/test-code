#include <Arduino.h>
#include <M5Unified.h>

constexpr int PIN_SERIAL2_RX = 2; // Serial2 RX
constexpr int PIN_SERIAL2_TX = 4; // Serial2 TX

void setup()
{
  delay(3000);
  auto cfg = M5.config();
  M5.begin(cfg);
  delay(500);
  Serial.begin(115200);
  delay(500);
  pinMode(PIN_SERIAL2_TX, INPUT_PULLUP);
  pinMode(PIN_SERIAL2_RX, INPUT_PULLUP);
  Serial2.begin(9600, SERIAL_8N1, PIN_SERIAL2_RX, PIN_SERIAL2_TX);
  delay(500);
}

void loop()
{
  M5.update();
  Serial.println(millis());
  Serial2.println(millis());
  delay(100);
}
