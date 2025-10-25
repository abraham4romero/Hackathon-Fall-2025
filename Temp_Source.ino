#include "DHT.h"
#include "SoftwareSerial.h"

#define DHTPIN 13
#define DHTTYPE DHT11

SoftwareSerial bt(10,11);

DHT dht(DHTPIN, DHTTYPE);
const int trigPin = 4;
const int echoPin = 6;

float duration, distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  bt.begin(9600);
  dht.begin();
  

}

void loop() {
  // put your main code here, to run repeatedly:

   digitalWrite(trigPin, LOW);
   delayMicroseconds(2);
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);

   duration = pulseIn(echoPin, HIGH);
   distance = (duration * .001125) / 2;  
  
  float t = dht.readTemperature();
  float fahrenheit = t * 1.8 + 32;

 
  
  Serial.print("Temperature: ");
  Serial.print(fahrenheit);
  Serial.println(" F   ");
  Serial.print(" | Distance: ");
  Serial.print(distance);
  Serial.print(" ft");
  Serial.print("\n");

  bt.print("Temperature: ");
  bt.print(fahrenheit);
  bt.print(" F   ");
  bt.print(" | Distance: ");
  bt.print(distance);
  bt.print(" ft");
  bt.print("\n");


  delay(4000);
  
}
