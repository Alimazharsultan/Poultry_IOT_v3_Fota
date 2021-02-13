//SD Card Library
#include <mySD.h>
//DHT Library
#include "DHTesp.h"
//RTC library
#include "RTClib.h"
//TM1638 Display Libary
#include <TM1638plus_Model2.h>
//Wifi&Blynk Libraries
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
bool WifiStatus = true;
//Fota Library
#include <HTTPClient.h>
#include <HTTPUpdate.h>
#include <WiFiClientSecure.h>
#include "cert.h"

//DHT Setting
DHTesp dht, dht2;

//RTC Setting
RTC_DS3231 rtc;

//TM1638 Setting
TM1638plus_Model2 tm(4, 16 , 17, false, false);
uint8_t readkey;

//SD Card Setting
File root;

//Wifi&Blynk Settings
char auth[] = "oWr2ymRcuaYa8bLwiDIHCEA3e4O9ARX5";       // You should get Auth Token in the Blynk App.
char ssid[] = "Ali";                    // Your Wi-Fi Credentials
char pass[] = "Pakistan";

//Relay Settings
bool Feedstatus=false;
bool Lightstatus=false;
bool Heaterstatus=false;
bool Fanstatus=false;
#define FEED 33
#define LIGHT 32
#define HEATER 12
#define FAN 25

//Delay Settings
int DisplayDelay = 0;
uint16_t DisplayNumber = 0;

//FOTA Setting
String FirmwareVer = {
  "3.0"
};
struct Button {
  const uint8_t PIN;
  uint32_t numberKeyPresses;
  bool pressed;
};

Button button_boot = {
  0,
  0,
  false
};
#define URL_fw_Version "https://raw.githubusercontent.com/khirds/powertalkz/main/bin_version.txt"
#define URL_fw_Bin "https://raw.githubusercontent.com/khirds/powertalkz/main/fw.bin"
void IRAM_ATTR isr() {
  button_boot.numberKeyPresses += 1;
  button_boot.pressed = true;
}


void setup() {
  Serial.begin(115200);
  //rtc.adjust(DateTime(2020, 12, 8, 16, 0, 0));
  
  
  //TM1638 Display Setup
  tm.displayBegin();
  tm.DisplayStr("POU LTry",0);
  
  //DHT Setup
  dht.setup(19, DHTesp::DHT11);
  dht2.setup(23, DHTesp::DHT11);
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
  }

  //Wifi&Blynk Setup
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
    if(millis()>10000){
      WifiStatus = false;
      Serial.println("WiFi Not connected"); 
      break;
      }
  }
    Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);  
    

    //Relay Setting
      pinMode(FEED, OUTPUT);
      pinMode(LIGHT, OUTPUT);
      pinMode(HEATER, OUTPUT);
      pinMode(FAN, OUTPUT);
  
   //SD Card Setup
  if (!SD.begin(26, 14, 13, 27)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
  /* open "Poultry.txt" for writing */
  root = SD.open("Poultry.txt", FILE_WRITE);
  /* if open succesfully -> root != NULL 
    then write string "Hello world!" to it
  */
  if (root) {
    root.println("Start: ");
    root.flush();
   /* close the file */
    root.close();
  } else {
    /* if the file open error, print an error */
    Serial.println("error opening Poultry.txt");
  }

  //Fota Setup

  pinMode(button_boot.PIN, INPUT);
  attachInterrupt(button_boot.PIN, isr, RISING);
  Serial.print("Active firmware version:");
  Serial.println(FirmwareVer);
  pinMode(2, OUTPUT);
  Serial.println(URL_fw_Version);
  Serial.println(URL_fw_Bin);
}

void loop() {
  // put your main code here, to run repeatedly:
    DisplayDelay = millis() % 4000;
 
    if(DisplayDelay <= 10){
      delay(15);
      Serial.print("Display Change: ");
      Serial.print(DisplayDelay); Serial.print(" #: "); Serial.println(DisplayNumber);
      DisplayNumber++;
      if(DisplayNumber==9){
        DisplayNumber = 0;
        }
        getTemperaturee();  
        getTemperaturee2();
        Time_day();  
        display_relay_status();
       if(WiFi.status() != WL_CONNECTED){
        Serial.print("Connecting to ");
        Serial.println(ssid);
        WiFi.begin(ssid, pass);
        WifiStatus = false;
        Serial.println("WiFi Not connected"); 
        Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
         }else{
          WifiStatus = true;
          }
          }  
    
get_relay_status();
set_relay_status();
if(WifiStatus){
  Blynk.run(); 
  }
if (button_boot.pressed) { //to connect wifi via Android esp touch app 
    Serial.println("Firmware update Starting..");
    firmwareUpdate();
    button_boot.pressed = false;
  }
  repeatedCall();
  
}
