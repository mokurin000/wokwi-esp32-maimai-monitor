// Learn about the ESP32 WiFi simulation in
// https://docs.wokwi.com/guides/esp32-wifi

#include <esp32-hal.h>
#include <HardwareSerial.h>

#include <Wire.h>
#include <Adafruit_SSD1306.h>

const u_int8_t SCREEN_HEIGHT(128);
const u_int8_t SCREEN_WIDTH(64);

TwoWire wire(0);
Adafruit_SSD1306 oled_screen(SCREEN_HEIGHT, SCREEN_WIDTH, &wire);

void setup()
{

  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");

  wire.setPins(21, 22);
  if (!oled_screen.begin(SSD1306_EXTERNALVCC, 0x3C))
  {
    Serial.println("initial failed!");
    return;
  }
  Serial.println("initial succeed!");

  oled_screen.clearDisplay();
  oled_screen.setCursor(0, 0);

  oled_screen.dim(false);

  oled_screen.fillCircle(64, 32, 20, 0xffcc);
  oled_screen.display();
}

void loop()
{

  delay(10); // this speeds up the simulation
}
