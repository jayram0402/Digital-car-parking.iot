// c++
// iot based car parking System

#define Green 5
#define Yellow 3
#define Red 2
#define buzzer 4


const int trigPin = 1;
const int echoPin = 0;
long duration;
int distance;


void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT);  // Sets the echoPin as an Input
pinMode(Green, OUTPUT);
pinMode(Yellow, OUTPUT);
pinMode(Red, OUTPUT);
pinMode(buzzer, OUTPUT);
}
void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
  if(distance > 200) { 
    digitalWrite(Green, HIGH);
    digitalWrite(buzzer, LOW);
    digitalWrite(Yellow, LOW);
    digitalWrite(Red, LOW);
  }
  if(distance <= 200 && distance >100) {
    digitalWrite(Green, LOW);
    digitalWrite(buzzer, LOW);
    digitalWrite(Yellow, HIGH);
    digitalWrite(Red, LOW);
  }
  if(distance < 100) {
    digitalWrite(Green, LOW);
    digitalWrite(buzzer, HIGH);
    digitalWrite(Yellow, LOW);
    digitalWrite(Red, HIGH);
    //tone(buzzer, 100, 100);
  
  }
}
