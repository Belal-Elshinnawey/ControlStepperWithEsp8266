int blueCoil   = 5 ;
int pinkCoil   = 6 ;
int yellowCoil = 7 ;
int orangeCoil = 8 ;
int ledPin     = 9 ;

int RightInd = 10;
int LeftInd  = 11;


void setup() {
  pinMode(blueCoil   , OUTPUT) ;
  pinMode(pinkCoil   , OUTPUT) ;
  pinMode(yellowCoil , OUTPUT) ;
  pinMode(orangeCoil , OUTPUT) ;
  pinMode(ledPin     , OUTPUT) ;
  pinMode(RightInd   , INPUT)  ;
  pinMode(LeftInd    , INPUT) ;
}

void loop() {
  int  RightState = digitalRead(RightInd);
  int LeftState  = digitalRead(LeftInd) ;
  if (RightState == 1 && LeftState == 0) {
    stepCounterClock();
  } else if (RightState == 0 && LeftState == 1) {
    stepClock();
  }

}

void stepCounterClock() {
  digitalWrite(ledPin, HIGH);
  step1() ;
  delay(2) ;
  step2() ;
  delay(2) ;
  step3() ;
  delay(2) ;
  step4() ;
  delay(2) ;
  step5() ;
  delay(2) ;
  step6() ;
  delay(2) ;
  step7() ;
  delay(2) ;
  step8() ;
  delay(2) ;
  digitalWrite(ledPin, LOW);
  delay(32);
}

void stepClock() {
  digitalWrite(ledPin, HIGH);
  step8() ;
  delay(2) ;
  step7() ;
  delay(2) ;
  step6() ;
  delay(2) ;
  step5() ;
  delay(2) ;
  step4() ;
  delay(2) ;
  step3() ;
  delay(2) ;
  step2() ;
  delay(2) ;
  step1() ;
  delay(2) ;
  digitalWrite(ledPin, LOW);
  delay(32);
}

void step1() {
  digitalWrite(orangeCoil, LOW) ;
  digitalWrite(yellowCoil, HIGH) ;
  digitalWrite(pinkCoil  , HIGH) ;
  digitalWrite(blueCoil  , HIGH) ;
}

void step2() {
  digitalWrite(orangeCoil, LOW) ;
  digitalWrite(yellowCoil, LOW) ;
  digitalWrite(pinkCoil  , HIGH) ;
  digitalWrite(blueCoil  , HIGH) ;
}


void step3() {
  digitalWrite(orangeCoil, HIGH) ;
  digitalWrite(yellowCoil, LOW) ;
  digitalWrite(pinkCoil  , HIGH) ;
  digitalWrite(blueCoil  , HIGH) ;
}

void step4() {
  digitalWrite(orangeCoil, HIGH) ;
  digitalWrite(yellowCoil, LOW) ;
  digitalWrite(pinkCoil  , LOW) ;
  digitalWrite(blueCoil  , HIGH) ;
}

void step5() {
  digitalWrite(orangeCoil, HIGH) ;
  digitalWrite(yellowCoil, HIGH) ;
  digitalWrite(pinkCoil  , LOW) ;
  digitalWrite(blueCoil  , HIGH) ;
}

void step6() {
  digitalWrite(orangeCoil, HIGH) ;
  digitalWrite(yellowCoil, HIGH) ;
  digitalWrite(pinkCoil  , LOW) ;
  digitalWrite(blueCoil  , LOW) ;
}

void step7() {
  digitalWrite(orangeCoil, HIGH) ;
  digitalWrite(yellowCoil, HIGH) ;
  digitalWrite(pinkCoil  , HIGH) ;
  digitalWrite(blueCoil  , LOW) ;
}

void step8() {
  digitalWrite(orangeCoil, LOW) ;
  digitalWrite(yellowCoil, HIGH) ;
  digitalWrite(pinkCoil  , HIGH) ;
  digitalWrite(blueCoil  , LOW) ;
}
