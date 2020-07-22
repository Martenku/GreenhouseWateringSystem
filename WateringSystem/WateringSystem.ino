  #include <Wire.h>


#include <DS3231.h>
int Relay = 4;
DS3231  rtc(SDA, SCL);
Time t;
//kastmisaeg
const int tundOnHommik = 8;
const int minutOnHommik = 00;
const int tundOnPaeval = 15;
const int minutOnPaeval = 00;
const int buttonPin = 2;
int  buttonState= 0;
int greenLed = 7;
int redLed = 6;




void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
  // Uncomment the next line if you are using an Arduino Leonardo
  //while (!Serial) {}
  pinMode(Relay, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  digitalWrite(Relay, LOW);
  // Initialize the rtc object
  rtc.begin();
 // rtc.setDOW(SATURDAY);     // Set Day-of-Week
  //rtc.setTime(12, 18, 00);     // Set the time  (24hr format)
  //rtc.setDate(05, 05, 2020);   // Set the date 
  

}

void loop() {
  
  buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);
  
  t = rtc.getTime();
  Serial.print(t.hour);
  Serial.print(":");
  Serial.print(t.min);
  Serial.print(":");
  Serial.println(t.sec);
  if(t.hour == tundOnHommik && t.min == minutOnHommik || (t.hour == tundOnPaeval && t.min == minutOnPaeval) || (buttonState == HIGH)){
    Serial.print("Sees");
    digitalWrite(greenLed,HIGH);
    digitalWrite(redLed,LOW);
    digitalWrite(Relay, HIGH);
    delay(480000);
  }
  digitalWrite(greenLed,LOW);
  digitalWrite(redLed,HIGH);
  digitalWrite(Relay, LOW);
  delay (1000);
  
}
