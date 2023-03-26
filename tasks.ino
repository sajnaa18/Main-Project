void beep()
{
  tone(buzzer,1400);
  delay(100);
  noTone(buzzer);
}
void connectWifi()
{
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("WiFi connecting to ");
  display.println(WIFI_SSID);

  WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
 
  display.println("\nConnecting");
  display.display();

  while( WiFi.status() != WL_CONNECTED )
  {
      delay(500);
      display.print("."); 
      display.display();       
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(10,20);
  display.println("WiFi connected to ");
  display.setCursor(30,40);
  display.println(WIFI_SSID);
  display.display();
  delay(1000);
}
void readDatabase()
{
  if(Firebase.RTDB.getInt(&fbdo, F("/Node2/Online")) == 1)
  {
    String newStatus2 = fbdo.to<const char *>();
    if(newStatus2 != status2)
    {
      beep();
      status2 = newStatus2;
    }
  }
  if(Firebase.RTDB.getInt(&fbdo, F("/Node2/SoilMoisture")) == 1)
  {
    String newSoil2 = fbdo.to<const char *>();
    if(newSoil2 != soil2)
    {
      beep();
      soil2 = newSoil2;
    }
  }
  if(Firebase.RTDB.getInt(&fbdo, F("/Node2/LightIntensity")) == 1)
  {
    String newLight = fbdo.to<const char *>();
    if(newLight != light)
    {
      beep();
      light = newLight;
    }
  }
  if(Firebase.RTDB.getInt(&fbdo, F("/Node3/Online")) == 1)
  {
    String newStatus3 = fbdo.to<const char *>();
    if(newStatus3 != status3)
    {
      beep();
      status3 = newStatus3;
    }
  }
  if(Firebase.RTDB.getInt(&fbdo, F("/Node3/Exhaust")) == 1)
  {
    String newExhaust = fbdo.to<const char *>();
    if(newExhaust != exhaust)
    {
      beep();
      exhaust = newExhaust;
    }    
  }
   if(Firebase.RTDB.getInt(&fbdo, F("/Node3/Growth")) == 1)
  {
    String newGrowth = fbdo.to<const char *>();
    if(newGrowth != growth)
    {
      beep();
      growth = newGrowth;
    }
  }
  if(Firebase.RTDB.getInt(&fbdo, F("/Node3/Pump1")) == 1)
  {
    String newPump1 = fbdo.to<const char *>();
    if(newPump1 != pump1)
    {
      beep();
      pump1 = newPump1;
    }
  }
  if(Firebase.RTDB.getInt(&fbdo, F("/Node3/Pump2")) == 1)
  {
    String newPump2 = fbdo.to<const char *>();
    if(newPump2 != pump2)
    {
      beep();
      pump2 = newPump2;
    }
  }
}
void checkSensors()
{
  int soilMoisture = analogRead(soilSensor);
  if(soilMoisture > soilTreshold)
  {
    Firebase.RTDB.setString(&fbdo, F("/Node3/Pump1"), 1);
  }
  else
  {
    Firebase.RTDB.setString(&fbdo, F("/Node3/Pump1"), 0);
  }
  soil1 = String(soilMoisture);
  Firebase.RTDB.setString(&fbdo, F("/Node1/SoilMoisture"), soil1);

  float humidity = dht.getHumidity();
  hum = String(humidity);
  Firebase.RTDB.setString(&fbdo, F("/Node1/Humidity"), hum);

  float temperature = dht.getTemperature();
  if(temperature > tempTreshold)
  {
    Firebase.RTDB.setString(&fbdo, F("/Node3/Exhaust"), 1);
  }
  else
  {
    Firebase.RTDB.setString(&fbdo, F("/Node3/Exhaust"), 0);
  }
  temp = String(temperature);
  Firebase.RTDB.setString(&fbdo, F("/Node1/Temperature"), temp);

  if(status2 == "0")
  {
    digitalWrite(node2LED,LOW);
  }
  else if(status2 == "1")
  {
    digitalWrite(node2LED,HIGH);
  }
  if(status3 == "0")
  {
    digitalWrite(node3LED,LOW);
  }
  else if(status3 == "1")
  {
    digitalWrite(node3LED,HIGH);
  }
}