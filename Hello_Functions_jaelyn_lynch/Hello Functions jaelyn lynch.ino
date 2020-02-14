#include <Servo.h> 
const int trigPin = 9;
const int echoPin = 10;
long dst;
Servo left;
Servo right;
int servo = 11;
int servo2 = 12;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
   left.attach(11);
   right.attach(12);

}

void loop() {
  dst = getDist();
  Serial.print("Distance: ");
  Serial.println(dst);
  delay(100);
     if(getDist() > 20){
          left.write(70);
          right.write(161);
     }
     else  {
          left.write(161);
          right.write(161);
     }
    
 
}

long getDist() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  return distance;

}