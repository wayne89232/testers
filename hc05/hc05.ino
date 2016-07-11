#include  <SoftwareSerial.h>
#include <String.h>
SoftwareSerial BTSerial(10,11); // RX | TX
void setup()
{
  pinMode(8, OUTPUT);  // this pin will pull the HC-05 pin 34 (key pin) HIGH to switch module to AT mode
  digitalWrite(8, HIGH);  
  Serial.begin(9600);
  Serial.println("Enter AT commands:");
  BTSerial.begin(9600);  // HC-05 default speed in AT command more
}
void loop()
{
  // Keep reading from HC-05 and send to Arduino Serial Monitor
  
  if (BTSerial.available()){
    //BTSerial.read();
    int a = BTSerial.read();
    Serial.write(a);
    delay(10);
    BTSerial.write(a);
    //BTSerial.write(BTSerial.read());
  }
  // Keep reading from Arduino Serial Monitor and send to HC-05
  if (Serial.available())
    BTSerial.write(Serial.read());
}

