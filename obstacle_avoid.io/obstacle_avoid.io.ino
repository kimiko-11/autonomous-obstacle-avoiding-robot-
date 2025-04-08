include<Servo.h>
Servo myservo; 
const int LMotor_1 = 2;
const int LMotor_2 = 3;
const int RMotor_1 = 4;
const int RMotor_2 = 5;


// 2. Define ultrasonic sensor pins
const int trig = 8;
const int echo = 7;
// 3. Variables for calculating distances
int distance;
long t;
int d;
int leftd;
int rightd;
int ld;
int rd;
// 4. Function to stop both motors
void Stop() {
  digitalWrite(LMotor_1, LOW);
  digitalWrite(LMotor_2, LOW);
  digitalWrite(RMotor_1, LOW);
  digitalWrite(RMotor_2, LOW);
}
// 5. Function to move both motors forward
void forward() {
  digitalWrite(LMotor_1, HIGH);
  digitalWrite(LMotor_2, LOW);
  digitalWrite(RMotor_1, HIGH);
  digitalWrite(RMotor_2, LOW);
}
// 6. Function to turn left
void left() {
  digitalWrite(LMotor_1, LOW);
  digitalWrite(LMotor_2, LOW);
  digitalWrite(RMotor_1, HIGH);
  digitalWrite(RMotor_2, LOW);
}
// 7. Function to turn right
void right() {
  digitalWrite(LMotor_1, HIGH);
  digitalWrite(LMotor_2, LOW);
  digitalWrite(RMotor_1, LOW);
  digitalWrite(RMotor_2, LOW);
}
int sleft() 
{
 myservo.write(175);
  delay(1000);
  ld = getdistance();
  myservo.write(90);
  delay(1000);
  return ld;
}
int sright() 
{
  myservo.write(5);
  delay(1000);
  rd = getdistance();
  myservo.write(90);
  delay(1000);
  return rd;
}

  int getdistance() 
  {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  t = pulseIn(echo, HIGH);
  d = t *0.034 / 2;
  return d;
  }
  
  void setup() {
  Serial.begin(9600);
  // 8. Set motor pins as outputs
  pinMode(LMotor_1, OUTPUT);
  pinMode(LMotor_2, OUTPUT);
  pinMode(RMotor_1, OUTPUT);
  pinMode(RMotor_2, OUTPUT);
 // 9. Set ultrasonic sensor pins
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  myservo.attach(9);
}
 void loop()
  {
 distance= getdistance();
  Serial.println(d);

  if (d <= 20) {
    Stop();
    delay(1000);
    leftd = sleft();
    rightd = sright();
             if (leftd >= rightd) {
                     left();
                    delay(1500);
                     forward(); }
             else {
                    right();
                   delay(1500);
                   forward();
                   }
  } 
  else 
  {
      forward();
    Serial.println("forward");
  }
  }
