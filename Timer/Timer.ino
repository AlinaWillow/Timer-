//*************Liabrary******************//
#include "Wire.h"
#include "SPI.h"  // not used here, but needed to prevent a RTClib compile error
#include "RTClib.h"
#include <Key.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
//*************************************//
RTC_DS3231 RTC;
LiquidCrystal_I2C lcd(0x27,20,4);

//********Keypad*********************//
const byte ROWS = 4; 
const byte COLS = 3; 
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {9,8,7,6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5,4,3}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

//*************Botton***************//
int P1=6; // Button SET MENU'
int P2=7; // Button +
int P3=9; // Button -

//**********Variable*************//
int menu=0;
int Rhour;
int Rmin;
int Rsec;

void setup(){
  
  pinMode(P1,INPUT_PULLUP);
  pinMode(P2,INPUT_PULLUP);
  pinMode(P3,INPUT_PULLUP);

  lcd.begin();
  
}

void loop(){

  if(digitalRead(P1)==0)
  {
   menu=menu+1;
  }
  if(menu==0){
    Menu();
  }
  if(menu==1){
    
   sethour(); 
   }
  if(menu==2){
    
   setmin();
   }
  if(menu ==3){
    
   setsec();
   }
   if(menu==4){
    timeDisplay();
   }
   if(menu==5){
     menu=0;
   }
    delay(100);
}

void Menu(){
  lcd.clear();
  lcd.setCursor(7,0);
  lcd.print("Timer");
  lcd.setCursor(0,1);
  lcd.print("1.hour");
  lcd.setCursor(0,2);
  lcd.print("2.miniute");
  lcd.setCursor(0,3);
  lcd.print("3.second");

 }
 void timeDisplay(){
  lcd.clear();
  lcd.setCursor(4,2);
  lcd.print(Rhour);
  lcd.print(":");
  lcd.print(Rmin);
  lcd.print(":");
  lcd.print(Rsec);
  delay(100);
}
void sethour(){
  lcd.clear();
    lcd.setCursor(7,0);
    lcd.print("hour");

  if(digitalRead(P2)==HIGH)
  {
    if(Rhour==0)
    {
      Rhour=23;
    }
    else
    {
      Rhour=Rhour-1;
    }
  }

  if(digitalRead(P3)==HIGH)
  {
    if(Rhour==23)
    {
      Rhour=0;
    }
    else
    {
      Rhour=Rhour+1;
    }
  }
  lcd.setCursor(0,1);
  lcd.print(Rhour);
  delay(100);
 }
void setmin(){
  lcd.clear();
    lcd.setCursor(7,0);
    lcd.print("minute");
    if(digitalRead(P2)==HIGH)
  {
    if(Rmin==0)
    {
      Rmin=59;
    }
    else
    {
      Rmin=Rmin-1;
    }
  }

  if(digitalRead(P3)==HIGH)
  {
    if(Rmin==59)
    {
      Rmin=0;
    }
    else
    {
      Rmin=Rmin+1;
    }
  }
  lcd.setCursor(0,1);
  lcd.print(Rmin);
  delay(100);
}
void setsec(){
  lcd.clear();
    lcd.setCursor(7,0);
    lcd.print("second");
    if(digitalRead(P2)==HIGH)
  {
    if(Rsec==0)
    {
      Rsec=59;
    }
    else
    {
      Rsec=Rsec-1;
    }
  }

  if(digitalRead(P3)==HIGH)
  {
    if(Rsec==59)
    {
      Rsec=0;
    }
    else
    {
      Rsec=Rsec+1;
    }
  }
  lcd.setCursor(0,1);
  lcd.print(Rsec);
  delay(100);
}
