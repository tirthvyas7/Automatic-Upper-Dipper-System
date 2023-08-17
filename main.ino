#include<Servo.h>
#include <dht.h>

dht DHT;

#define DHT11_PIN 7

int LDR1= A0; 
int LDR2= A1;
int LED_1 = 6;    
int LED_2 = 9;                  // LED is connected to PWM Pin 3.
int LDRReading1 = 0;
int LDRReading2 = 0;                          // to store input value of LDR
int lEDBrightness1 = 0;   // to store the value of LED Brightness
int lEDBrightness2 = 0; 
int threshold_val1 = 650; // Check your threshold and modify i
int threshold_val2 = 850;
int threshold_ask1=  550;
int threshold_ask2=  650;
Servo myservo1;
Servo myservo2;
int pos=0;
int LED = 13; // Use the onboard Uno LED

int isObstaclePin = 2; // This is our input pin

int isObstacle = HIGH; // HIGH MEANS NO OBSTACLE

void setup(){
  Serial.begin(9600);     // initializing serail communication.
  pinMode(LED_1, OUTPUT);   // Defining LED pin as output.
  
  pinMode(LED_2,OUTPUT);
  pinMode(LDR1,INPUT);
  pinMode(LDR2,INPUT);
  pinMode(LED, OUTPUT);
  pinMode(isObstaclePin, INPUT);
  myservo1.attach(3);
  myservo2.attach(7);
  myservo1.write(pos);
  myservo2.write(pos);
  digitalWrite(LED_1, HIGH);
  digitalWrite(LED_2, HIGH); 
}

void loop(){
  LDRReading1 = analogRead(LDR1);    // Reading LDR Input.
  LDRReading2= analogRead(LDR2);
  Serial.println("LDR1:");
  Serial.println(LDRReading1);      // Printing LDR input value.
  Serial.println("LDR2:");
  Serial.println(LDRReading2);
  if (LDRReading1 >threshold_val1 && LDRReading2> threshold_val2){                   // Condition to make LED ON. // Converting LDR to LED Brightness.
analogWrite(LED_1, 50);
  }
  else{
  digitalWrite(LED_1,HIGH);             // If LDR is below threshold make LED OFF.
  }

isObstacle = digitalRead(isObstaclePin);

if (isObstacle == LOW)
{
     analogWrite(LED_1,5);
    delay(100);
    analogWrite(LED_1,100);
    delay(100);
}


else

{

return;


}




}
