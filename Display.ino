void titleCard()
{
  display.clearDisplay();
  display.setTextSize(2);      
  display.setTextColor(WHITE);
  display.setCursor(34,0);
  display.print("GREEN");
  display.setCursor(30,20);
  display.print("BROOKS");

  display.setTextSize(1);
  display.setCursor(24,42);
  display.print("M2M GREEN FARM");
  display.setCursor(14,55);
  display.print("AUTOMATION SYSTEM");
  display.display();
  delay(2000); 
}
void loading_graphics()
{
  display.clearDisplay();
  display.setTextSize(1);            
  display.setTextColor(WHITE);
  display.setCursor(7,25); 

  display.print("S");
  display.display();
  delay(loading);

  display.print("Y");
  display.display();
  delay(loading);

  display.print("S");
  display.display();
  delay(loading);

  display.print("T");
  display.display();
  delay(loading);

  display.print("E");
  display.display();
  delay(loading);

  display.print("M");
  display.display();
  delay(loading);
  
  display.print(" I");
  display.display();
  delay(loading);
  
  display.print("N");
  display.display();
  delay(loading);
  

  display.print("I");
  display.display();
  delay(loading);

  display.print("T");
  display.display();
  delay(loading);

  display.print("I");
  display.display();
  delay(loading);

  display.print("A");
  display.display();
  delay(loading);

  display.print("L");
  display.display();
  delay(loading);

  display.print("I");
  display.display();
  delay(loading);
  
  display.print("Z");
  display.display();
  delay(loading);
  
  display.print("I");
  display.display();
  delay(loading);

  display.print("N");
  display.display();
  delay(loading);

  display.print("G");
  display.display();
  delay(loading);
  
  display.drawRect(10, 45,108,10, WHITE);
  for(int i=0;i<109;i++)
  {
    display.fillRect(10,45,i,10,WHITE);
    display.display();
    delay(1);
  }
  delay(2000); 
}
void frameNode1()
{
  display.clearDisplay();
  display.fillRect(0,0,128,15,WHITE);
  display.setTextSize(1); 
  display.setTextColor(BLACK,WHITE); 
  display.setCursor(15,3);
  display.print("NODE 1");
  display.display();
}
void Screen1()
{
  display.fillRect(0, 18, 128, 45, BLACK);
  display.setTextSize(1);
  display.setTextColor(WHITE); 
  display.setCursor(10,18);
  display.println("Temper : ");
  display.setCursor(65,18);
  display.println(temp);
  display.setCursor(80,18);
  display.println("dC");

  display.setCursor(10,30);
  display.println("Humidi : ");
  display.setCursor(65,30);
  display.println(hum);
  display.setCursor(80,30);
  display.println("RH");

  display.setCursor(10,42);
  display.println("SoilMo : ");
  display.setCursor(65,42);
  display.println(soil1);
  display.setCursor(80,42);
  display.println("ADC");

  display.setCursor(10,54);
  display.println("Status : ");
  if(status1 == "0")
  {
    display.setCursor(65,54);
    display.println("INACTIVE");
  }
  else if(status1 == "1")
  {
    display.setCursor(65,54);
    display.println("ACTIVE");
  }  
  display.display();
}
void frameNode2()
{
  display.clearDisplay();
  display.fillRect(0,0,128,15,WHITE);
  display.setTextSize(1); 
  display.setTextColor(BLACK,WHITE); 
  display.setCursor(15,3);
  display.print("NODE 2");
  display.display();
}
void Screen2()
{
  display.fillRect(0, 18, 128, 45, BLACK);
  display.setTextSize(1);
  display.setTextColor(WHITE); 
  display.setCursor(10,18);
  display.println("LightI : ");
  display.setCursor(65,18);
  display.println(light);
  display.setCursor(80,18);
  display.println("ADC");

  display.setCursor(10,30);
  display.println("SoilMo : ");
  display.setCursor(65,30);
  display.println(soil2);
  display.setCursor(80,30);
  display.println("ADC");

  display.setCursor(10,42);
  display.println("Status : ");
  if(status2 == "0")
  {
    display.setCursor(65,42);
    display.println("INACTIVE");
  }
  else if(status2 == "1")
  {
    display.setCursor(65,42);
    display.println("ACTIVE");
  }
  display.display();
}
void frameNode3()
{
  display.clearDisplay();
  display.fillRect(0,0,128,15,WHITE);
  display.setTextSize(1); 
  display.setTextColor(BLACK,WHITE); 
  display.setCursor(15,3);
  display.print("THIS NODE");
  display.display();
}
void Screen3()
{
  display.fillRect(0, 18, 128, 45, BLACK);
  display.setTextSize(1);
  display.setTextColor(WHITE); 
  display.setCursor(10,18);
  display.println("Exhaust : ");
  if(exhaust == "0")
  {
    display.setCursor(65,18);
    display.println("INACTIVE");
  }
  else if(exhaust == "1")
  {
    display.setCursor(65,18);
    display.println("ACTIVE");
  }

  display.setCursor(10,30);
  display.println("GrowthL : ");
  if(growth == "0")
  {
    display.setCursor(65,30);
    display.println("INACTIVE");
  }
  else if(growth == "1")
  {
    display.setCursor(65,30);
    display.println("ACTIVE");
  }

  display.setCursor(10,42);
  display.println(" Pump 1 : ");
  if(pump1 == "0")
  {
    display.setCursor(65,42);
    display.println("INACTIVE");
  }
  else if(pump1 == "1")
  {
    display.setCursor(65,42);
    display.println("ACTIVE");
  }

  display.setCursor(10,54);
  display.println(" Pump 2 : ");
  if(pump2 == "0")
  {
    display.setCursor(65,54);
    display.println("INACTIVE");
  }
  else if(pump2 == "1")
  {
    display.setCursor(65,54);
    display.println("ACTIVE");
  }
  display.display();
}
void screenChange()
{
  if(page == 3)
  {
    page = 0;
  }
  page += 1;
  switch(page)
  {
    case 1: 
      frameNode1();
      break;
    case 2: 
      frameNode2();
      break;
    case 3: 
      frameNode3();
      break;
  }

}
void setScreen()
{
  Firebase.RTDB.setInt(&fbdo, F("/Node1/Online"), 0);
  Firebase.RTDB.setInt(&fbdo, F("/Node2/Online"), 0);
  Firebase.RTDB.setInt(&fbdo, F("/Node3/Online"), 1); 
  switch(page)
  {
    case 1: 
      Screen1();
      break;
    case 2: 
      Screen2();
      break;
    case 3: 
      Screen3();
      break;
  }
}