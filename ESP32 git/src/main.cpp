#include <Arduino.h>
#include <BluetoothSerial.h>
#include <esp_bt_device.h>

BluetoothSerial SerialBT;

void printDeviceAddress();
void callback(esp_spp_cb_event_t event, esp_spp_cb_param_t *param);

void setup() {
  Serial.begin(115200);
  
  if (!SerialBT.begin("ESP32")) {
    Serial.println("An error occurred during Bluetooth initialization!");
  } else {
    Serial.println("Bluetooth initialized.");
  }
  printDeviceAddress();
  SerialBT.register_callback(callback);
}

void loop() {
  
}

void printDeviceAddress() {
  const uint8_t* address = esp_bt_dev_get_address();
  
  for (int i = 0; i < 6; i++) {
    char str[3];
    sprintf(str, "%02X", (int)address[i]);
    Serial.print(str);
    
    if (i < 5) {
      Serial.print(":");
    } else {
      Serial.println();
    }
  }
}

void callback(esp_spp_cb_event_t event, esp_spp_cb_event_t *param){
  if(event == ESP_SPP_SRV_OPEN_EVT){
    Serial.println("Client Connected");
  }
}