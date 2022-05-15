#include <M5StickC.h>
#include "BLEDevice.h"
#include "BLEUtils.h"
#include "BLEServer.h"
#include "BLEBeacon.h"

BLEAdvertising *pAdvertising;   // BLE Advertisement type
struct timeval now;
#define GPIO_DEEP_SLEEP_DURATION     1  // sleep x seconds and then wake up
RTC_DATA_ATTR static time_t last;        // remember last boot in RTC Memory
RTC_DATA_ATTR static uint32_t bootcount; // remember number of boots in RTC Memory
#define BEACON_UUID "87b99b2c-90fd-11e9-bc42-526af7764f64" // UUID 1 128-Bit (may use linux tool uuidgen or random numbers via https://www.uuidgenerator.net/)
void setBeacon()
{

  BLEBeacon oBeacon = BLEBeacon();
  oBeacon.setManufacturerId(0x4C00); 
  oBeacon.setProximityUUID(BLEUUID(BEACON_UUID));
  oBeacon.setMajor((bootcount & 0xFFFF0000) >> 16);
  oBeacon.setMinor(bootcount & 0xFFFF);
  BLEAdvertisementData oAdvertisementData = BLEAdvertisementData();
  BLEAdvertisementData oScanResponseData = BLEAdvertisementData();

  oAdvertisementData.setFlags(0x04); // BR_EDR_NOT_SUPPORTED 0x04

  std::string strServiceData = "";

  strServiceData += (char)26;     // Len
  strServiceData += (char)0xFF;   // Type
  strServiceData += oBeacon.getData();
  oAdvertisementData.addData(strServiceData);

  pAdvertising->setAdvertisementData(oAdvertisementData);
  pAdvertising->setScanResponseData(oScanResponseData);
}

void setup() {
  M5.begin();
  Serial.begin(115200);
  M5.Lcd.setTextColor(YELLOW);  //Set the font color to yellow.  设置字体颜色为黄色
  M5.Lcd.setRotation(3);
  M5.Axp.ScreenBreath(10);
  M5.Lcd.setTextColor(RED);
  M5.Lcd.setCursor(3, 10);
  M5.Lcd.setTextSize(2);
}

void loop() {

  M5.update();
  M5.Lcd.setCursor(3, 10);
  if (M5.BtnA.wasReleased()) {
    M5.Lcd.setTextColor(GREEN);
    M5.Lcd.println("Triggred");
    Serial.println("Trigger mode");
    // Create the BLE Device
    BLEDevice::init("BLE Receiver 01");
    // Create the BLE Server
    BLEServer *pServer = BLEDevice::createServer(); // <-- no longer required to instantiate BLEServer, less flash and ram usage
    pAdvertising = BLEDevice::getAdvertising();
    BLEDevice::startAdvertising();
    setBeacon();
    // Start advertising
    pAdvertising->start();
    Serial.println("Advertizing started...");
    delay(1000);
    pAdvertising->stop();
    M5.Lcd.fillScreen(BLACK);  
    M5.Lcd.setCursor(3, 10);
  } 
  }
