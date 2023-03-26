#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ESP8266WiFi.h>
#include <Firebase_ESP_Client.h>
#include <addons/RTDBHelper.h>
#include <TickTwo.h>

#define WIFI_SSID "VIRUS ALERT"
#define WIFI_PASSWORD "asdf1234ASDF!@#$"
#define DATABASE_URL "greenbrooks-lbs-default-rtdb.firebaseio.com"


FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

void screenChange();
void setScreen();
void readDatabase();
void checkRelay();

TickTwo switchScreen(screenChange,5000);
TickTwo refreshScreen(setScreen,10);
TickTwo firebaseDB(readDatabase,1000);
TickTwo outputLoad(checkRelay,10);

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET     -1
#define loading 150

#define buzzer D5
#define WaterPump1 D0
#define WaterPump2 D6
#define growthLight D7
#define exhaustFan D3

#define node1LED D4
#define node2LED D8


String temp = "0", hum = "0", soil1 = "0", status1 = "0", light = "0", soil2 = "0", status2 = "0";
String exhaust = "0", growth = "0", pump1 = "0", pump2 = "0"; 

int page = 0;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


void setup() 
{
  //Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
  pinMode(WaterPump1,OUTPUT);
  pinMode(WaterPump2,OUTPUT);
  pinMode(growthLight,OUTPUT);
  pinMode(exhaustFan,OUTPUT);
  pinMode(node1LED,OUTPUT);


  //Turn off all relay controls
  digitalWrite(WaterPump1,HIGH);
  digitalWrite(WaterPump2,HIGH);
  digitalWrite(growthLight,HIGH);
  digitalWrite(exhaustFan,HIGH);

  beep();
  delay(100);
  beep();

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  loading_graphics();
  titleCard();

  switchScreen.start();
  refreshScreen.start();
  firebaseDB.start();
  outputLoad.start();

  connectWifi();
  config.database_url = DATABASE_URL;
  config.signer.test_mode = true;
  Firebase.reconnectWiFi(true);
  Firebase.begin(&config, &auth);
}
void loop()
{
  firebaseDB.update();
  switchScreen.update();
  refreshScreen.update();
  outputLoad.update();
}