//All Credit Technic 1510
//
//
//
//
#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>
#include <RTClib.h> // for the RTC
#define SS_PIN 10
#define RST_PIN 9


// Instance of the class for RTC
RTC_DS1307 rtc;
MFRC522 mfrc522(SS_PIN, RST_PIN);   
LiquidCrystal lcd(6 , 7, 5, 4, 3, 2);
// Define check in time
const int checkInHour =22;
const int checkInMinute = 5;
int userCheckInHour;
int userCheckInMinute;
const int redLED = 6;
const int greenLED = 7;
const int buzzer = 5;

 
void setup() 
{
  
  SPI.begin();     
  mfrc522.PCD_Init();   
   DateTime now = rtc.now();
  userCheckInHour = now.hour();
  userCheckInMinute = now.minute();
  lcd.begin(16, 2);
  lcd.print("Scan RFID Card");
    // Setup for the RTC  
  if(!rtc.begin()) 
  {
    lcd.print("Couldn't find RTC");
    Serial.println("Couldn't find RTC");
    while(1);
  }
  else {
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
  if(!rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    }
  
  

}
void loop() 
{

  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }

  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }

  lcd.clear();
  lcd.begin(16, 2);
  lcd.print("Place your id card:");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
    lcd.setCursor(0, 1);
     lcd.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     lcd.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
lcd.clear();
lcd.begin(16, 2);
 lcd.print(" ");
 content.toUpperCase();
  if (content.substring(1) == "0E D4 4C 75") //Plz change to your cards UID
  {   DateTime now = rtc.now();
     userCheckInHour = now.hour();
     userCheckInMinute = now.minute();
     lcd.print("time:");
     lcd.print(userCheckInHour);
     lcd.print(":");
     lcd.print(userCheckInMinute);
     if((userCheckInHour < checkInHour)||((userCheckInHour==checkInHour) && (userCheckInMinute <= checkInMinute)))
     {   lcd.setCursor(0,1);
         lcd.print("Welcome Abhigna");
         digitalWrite(greenLED, HIGH);
         delay(2000);
         digitalWrite(greenLED,LOW);
        
     }
      else{
    digitalWrite(redLED, HIGH);
    delay(2000);
    digitalWrite(redLED,LOW);
    //Serial.println("You are late...");
       lcd.setCursor(0,1);
    lcd.print("You are Late");
  }
  
  
    delay(3000);
   lcd.clear();
    setup();
  }
 
 else   {
  lcd.setCursor(0, 1);
    lcd.print(" Access denied");
    delay(3000);
    lcd.clear();
      setup();
      }}
