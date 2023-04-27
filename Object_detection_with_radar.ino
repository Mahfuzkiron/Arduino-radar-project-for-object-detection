// Arduino radar project and alarm system 2023

#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#define trigPin 9
#define echoPin 8
#define ledGreen 7
#define ledRed 6
#define buzzer 5  
int pos = 0;
long duration;
int distance;
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myservo;

void setup() {
  Serial.begin(9600);
  lcd.init();               
  lcd.backlight();
  myservo.attach(4); 
  lcd.begin(16,2); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);
  noTone(buzzer);
  }


void loop() {
  // motor rotates from 0 to 180degress
  
  for (pos = 0; pos <= 180; pos += 1) 
    { 
    myservo.write(pos); 
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
     
    duration = pulseIn(echoPin, HIGH);
    distance= duration*0.017;
    
    lcd.setCursor(0,0); 
    lcd.print("Distance: "); 
    lcd.print(distance); 
    lcd.print("cm "); 
    lcd.setCursor(0,1);
    lcd.print("Angle : ");
    lcd.print(pos);
    lcd.print(" deg ");
    Serial.print(pos);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
   
    if(distance <10)
      {
      lcd.clear();
      digitalWrite(ledRed, HIGH);
      delay(700);
      lcd.print("  WARNING!!");
      lcd.setCursor(0, 1);
      lcd.print("OBSTACKLE DETECTED!");
      delay(700);
      tone(buzzer, 300);
      delay(700);
      digitalWrite(ledGreen, LOW); 
      delay(750);
      noTone(buzzer);
      }
    else
      {
      digitalWrite(ledGreen, HIGH);
      digitalWrite(ledRed, LOW);
      }
      }
 //motor rotates from 180 to 0 degress
  for (pos = 180; pos>= 0; pos -= 1) 
    { 
    myservo.write(pos); 
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
     
    duration = pulseIn(echoPin, HIGH);
    distance= duration*0.017;
    
    lcd.setCursor(0,0); 
    lcd.print("Distance: "); 
    lcd.print(distance); 
    lcd.print("cm "); 
    lcd.setCursor(0,1);
    lcd.print("Angle : ");
    lcd.print(pos);
    lcd.print(" deg ");
    Serial.print(pos);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
   
    if(distance <10)
      {
      lcd.clear();
      digitalWrite(ledRed, HIGH);
      delay(700);
      lcd.print("  WARNING!!");
      lcd.setCursor(0, 1);
      lcd.print("OBSTACKLE DETECTED!");
      delay(700);
      tone(buzzer, 300);
      delay(700);
      digitalWrite(ledGreen, LOW); 
      delay(750);
      noTone(buzzer);
      }
    else
      {
      digitalWrite(ledGreen, HIGH);
      digitalWrite(ledRed, LOW);
      }
      }
    }
