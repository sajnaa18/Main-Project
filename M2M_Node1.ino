#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ESP8266WiFi.h>
#include <Firebase_ESP_Client.h>
#include <addons/RTDBHelper.h>
#include <TickTwo.h>
#include "DHTesp.h"

#define WIFI_SSID "VIRUS ALERT"
#define WIFI_PASSWORD "asdf1234ASDF!@#$"
#define DATABASE_URL "greenbrooks-lbs-default-rtdb.firebaseio.com"

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

void screenChange();
void setScreen();
void readDatabase();
void checkSensors();

TickTwo switchScreen(screenChange,5000);
TickTwo refreshScreen(setScreen,10);
TickTwo firebaseDB(readDatabase,1000);
TickTwo sensorReading(checkSensors,1000);

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET     -1
#define loading 150

#define buzzer D5
#define node1LED D8
#define node2LED D7
#define node3LED D4
#define DHTSensor D6
#define soilSensor A0

String temp = "0", hum = "0", soil1 = "0", status2 = "0", light = "0", soil2 = "0", status3 = "0";
String exhaust = "0", growth = "0", pump1 = "0", pump2 = "0"; 

#define tempTreshold 35
#define soilTreshold 600

int page = 0;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

DHTesp dht;

void setup()
{
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
  pinMode(soilSensor,INPUT);
  pinMode(node1LED,OUTPUT);
  pinMode(node2LED,OUTPUT);
  pinMode(node3LED,OUTPUT);
  dht.setup(12, DHTesp::DHT11);

  analogWrite(node1LED,20);

  beep();
  delay(100);
  beep();

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  loading_graphics();
  titleCard();

  switchScreen.start();
  refreshScreen.start();
  firebaseDB.start();
  sensorReading.start();

  connectWifi();
  config.database_url = DATABASE_URL;
  config.signer.test_mode = true;
  Firebase.reconnectWiFi(true);
  Firebase.begin(&config, &auth);
  frameNode1();
}
void loop()
{
  switchScreen.update();
  refreshScreen.update();
  firebaseDB.update();
  sensorReading.update();
}