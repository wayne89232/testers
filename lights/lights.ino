int led[4] = {3,5,6,9};


void setup() {
  // nothing happens in setup
}

void loop() {
  for(int i = 0; i < 4; i++){
      fade(i);
  }

}

void fade(int in){
  int led1 = led[in];
  int led2;
  if(in - 1 < 0)
     led2 = led[3];
  else
    led2 = led[in - 1];
  for (int f1 = 0,  f2 = 255 ; f1 <= 255 || f2 >= 0 ; ) {
    analogWrite(led1, f1);
    analogWrite(led2, f2);
    delay(30);
    f1+=5;
    f2-=5;
  }
}
