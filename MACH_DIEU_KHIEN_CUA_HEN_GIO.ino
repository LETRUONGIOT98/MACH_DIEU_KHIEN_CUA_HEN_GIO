#define IN1 4
#define IN2 5
#include <virtuabotixRTC.h> //Libraries needed
#include <LiquidCrystal_I2C.h>
 LiquidCrystal_I2C lcd(0x27,16,2);
//Wiring SCLK -> 6, I/O -> 7, CE -> 8
//Or CLK -> 6 , DAT -> 7, Reset -> 8
 
virtuabotixRTC myRTC(6, 7, 8); //If you change the wiring change the pins here also
int giobat = 04;
int phutbat = 00;

int giotat =19;
int phuttat = 00;


void setup() {
  dung();
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
 lcd.home ();
 //myRTC.setDS1302Time(14, 30, 15, 3,18, 7, 2023); 
 ///////////////////giây,phút, giờ,thứ,  Ngày,Tháng, Năm
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
}
void thuan(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
}
void nguoc(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}
void dung(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}
void loop() {
  lcd.clear(); //Here after clearing the LCD we take the time from the module and print it on the screen with usual LCD functions
 myRTC.updateTime();
 lcd.setCursor(0,0);
 lcd.print("NOW: ");
 lcd.print(myRTC.hours);
 lcd.print(":");
 lcd.print(myRTC.minutes);
 lcd.print(":");
 lcd.print(myRTC.seconds);


 lcd.setCursor(0,1);
 lcd.print("B:");
 lcd.print(giobat);
 lcd.print(":");
 lcd.print(phutbat);

 lcd.print(" T:");
 lcd.print(giotat);
 lcd.print(":");
 lcd.print(phuttat);
 if(myRTC.hours >= giotat && myRTC.minutes >= phuttat){
  nguoc();
 }
else if(myRTC.hours >= giobat && myRTC.minutes >= phutbat ){
  thuan();
 }

 
 delay(1000);
}
