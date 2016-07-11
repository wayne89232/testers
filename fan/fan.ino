int in1 = 5;
int in2 = 6;
int in3 = 9;
int in4 = 10;
int en1 = 12;
int en2 = 13;
// motor two
void setup()
{
  // set all the motor control pins to outputs
  pinMode(en1, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
   analogWrite(en1, 80);
}
void demoOne()
{
  // this function will run the motors in both directions at a fixed speed
  // turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // set speed to 200 out of possible range 0~255
 
  // now change motor directions
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  delay(100);
  // now turn off motors
  //digitalWrite(in1, LOW);
  //digitalWrite(in2, LOW);  
}

void loop() {
  // put your main code here, to run repeatedly:
 demoOne();
  //vib();
  delay(100);
}

void servo(){
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);  
  delay(10000);
}

