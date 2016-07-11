
#include <Stepper.h>
#include  <SoftwareSerial.h>
#include <Servo.h>

Servo myservo;
SoftwareSerial BTSerial(10, 11); 

int pos = 0;
//motor & fan
int in1 = 5;
int in2 = 6;
int in3 = 9;
int in4 = 7;
int en1 = 12;
int en2 = 1;
String prev = "";

Stepper myStepper(200, 13, 3, 2, 4);

void setup() {
  // put your setup code here, to run once:
  pinMode(8, OUTPUT);  // this pin will pull the HC-05 pin 34 (key pin) HIGH to switch module to AT mode
  digitalWrite(8, HIGH);
  myStepper.setSpeed(80);
  Serial.begin(9600);
  myservo.attach(11);
  Serial.println("Enter AT commands:");
  BTSerial.begin(9600);  // HC-05 default speed in AT command more
  pinMode(en1, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  analogWrite(en1, 80);
}

void loop() {
  // put your main code here, to run repeatedly:
    //happy();
    //fan();
    lift();
    delay(2000);
//    unsigned long starttime;
//    unsigned long endtime;
//    starttime = millis();
//      endtime = starttime;
//    while ((endtime - starttime) <=10000) // do this loop for up to 1000mS
//    {
//      // code here
//        fan();
//       endtime = millis();
//    }
//
//    fan();
    drop();
    delay(2000);
    //serv();
    if (BTSerial.available()){
       String a = BTSerial.readString();
       //Serial.write(a);
       if(a == "1"){//lift
          lift();
       }
       else if(a == "2"){//drop
         drop();
       }
       else if(a == "3"){//fan
          fan();  
       }
      prev = a;
    }
    if(prev == "3")
        fan();
    
}

void stepper(){
  myStepper.step(-400);
  delay(200);
}
void fan()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  delay(1000);
}
void happy()
{
  digitalWrite(in3, HIGH); // sets pin 12 HIGH
  delay(200);   // waits for t1 uS (high time)
  digitalWrite(in3, LOW);  // sets pin 12 LOW
  delay(1000);
}
void vib(){
  digitalWrite(in3, HIGH); // sets pin 12 HIGH
  delay(10);   // waits for t1 uS (high time)
  digitalWrite(in3, LOW);  // sets pin 12 LOW
  delay(5000); 
}

void lift(){
  for (pos = 0; pos <= 180; pos += 5) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
void drop(){
    for (pos = 180; pos >= 0; pos -= 5) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }}
