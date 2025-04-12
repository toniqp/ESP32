#include <Arduino.h>
#include "BluetoothSerial.h"
#include "esp_bt_device.h"

#define BIN_1 4
#define BTN_2 12
#define BTN_3 13
#define BTN_4 14
#define BTN_5 27
#define BTN_6 32
#define BTN_7 33

#define threshold 40

BluetoothSerial SerialBT;

volatile unsigned long startTime = 0;
volatile uint32_t button_time1 = 0;
volatile uint32_t button_time2 = 0;
volatile uint32_t button_time3 = 0;
volatile uint32_t button_time4 = 0;
volatile uint32_t button_time5 = 0;
volatile uint32_t button_time6 = 0;
volatile uint32_t button_time7 = 0;

void printDeviceAddress();
void callback(esp_spp_cb_event_t event, esp_spp_cb_param_t *param);
void getTouch1();
void getTouch2();
void getTouch3();
void getTouch4();
void getTouch5();
void getTouch6();
void getTouch7();

void setup() {
  Serial.begin(115200);

  if (!SerialBT.begin("ESP32")) {
    Serial.println("Bluetooth init failed");
  } else {
    Serial.println("Bluetooth initialized");
  }

  printDeviceAddress();
  SerialBT.register_callback(callback);
}

void loop() {
  if (digitalRead(BTN_2) == HIGH) getTouch1();
  if (digitalRead(BTN_3) == HIGH) getTouch2();
  if (digitalRead(BTN_4) == HIGH) getTouch3();
  if (digitalRead(BTN_5) == HIGH) getTouch4();
  if (digitalRead(BTN_6) == HIGH) getTouch5();
  if (digitalRead(BTN_7) == HIGH) getTouch6();
}

void printDeviceAddress() {
  const uint8_t* address = esp_bt_dev_get_address();
  String macStr = "";
  for (int i = 0; i < 6; i++) {
    char str[3];
    sprintf(str, "%02X", (int)address[i]);
    macStr += str;
    if (i < 5) macStr += ":";
  }
  Serial.println(macStr);
  SerialBT.println("Device MAC: " + macStr);
}

void callback(esp_spp_cb_event_t event, esp_spp_cb_param_t *param) {
  if (event == ESP_SPP_SRV_OPEN_EVT) {
    Serial.println("Client Connected");
  }
}

void getTouch1() {
  if (millis() - button_time1 > threshold) {
    SerialBT.println("1");
    button_time1 = millis();
  }
}

void getTouch2() {
  if (millis() - button_time2 > threshold) {
    SerialBT.println("2");
    button_time2 = millis();
  }
}

void getTouch3() {
  if (millis() - button_time3 > threshold) {
    SerialBT.println("3");
    button_time3 = millis();
  }
}

void getTouch4() {
  if (millis() - button_time4 > threshold) {
    SerialBT.println("4");
    button_time4 = millis();
  }
}

void getTouch5() {
  if (millis() - button_time5 > threshold) {
    SerialBT.println("5");
    button_time5 = millis();
  }
}

void getTouch6() {
  if (millis() - button_time6 > threshold) {
    SerialBT.println("6");
    button_time6 = millis();
  }
}

void getTouch7() {
  if (millis() - button_time7 > threshold) {
    SerialBT.println("7");
    button_time7 = millis();
  }
}
