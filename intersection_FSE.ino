
int stl1 = 1;
int tr1 = 13;
int ty1 = 12;
int tg1 = 11;
int tr2 = 10;
int ty2 = 9;
int tg2 = 8;
int pin8 = 1;
int pin9 = 1;
int pin10 = 1;
int pin11 = 1;
int pin12 = 1;
const int pResistor = A0;


float starttime = 0;

int delayTime = 100;
int delayTime2 = 300;

void setup() {
  Serial.begin(9600);
  //
  pinMode(stl1, OUTPUT);
  pinMode(tr1, OUTPUT);
  pinMode(tr2, OUTPUT);
  pinMode(tg1, OUTPUT);
  pinMode(tg2, OUTPUT);
  pinMode(ty1, OUTPUT);
  pinMode(ty2, OUTPUT);
  pinMode(pin8, OUTPUT);
  pinMode(pin9, OUTPUT);
  pinMode(pin10, OUTPUT);
  pinMode(pin11, OUTPUT);
  pinMode(pin12, OUTPUT);
  pinMode(pResistor, INPUT);
  starttime = millis();
}

void loop()
{
  long delta = millis() - starttime;
  Serial.println(delta);
  /*
    digitalWrite(tg1, HIGH);
    digitalWrite(ty1, HIGH);
    digitalWrite(tr1, HIGH);
    digitalWrite(tr2, HIGH);
    digitalWrite(ty2, HIGH);
    digitalWrite(tg2, HIGH);
  */
  intersection(delta);
  railway(delta);

  if (delta > 15000) {
    starttime = millis();
  }
}

void railway(long delta) {
  if (delta < 500) {
    tone(7, 240, 200);
  } else if (delta < 750) {
    noTone(7);
  }
  else if (delta < 1000) {
    tone(7, 240, 200);
  }
  else if (delta < 1250) {
    noTone(7);
  }
  else if (delta < 1500) {
    tone(7, 240, 200);
  } else if (delta < 1750) {
    noTone(7);
  }
  else if (delta < 2000) {
    tone(7, 240, 200);
  } else if (delta < 2250) {
    noTone(7);
  }
  else if (delta < 2500) {
    tone(7, 240, 200);
  } else if (delta < 2750) {
    noTone(7);
  }
  else if (delta < 3000) {
    tone(7, 240, 200);
  } else if (delta < 3250) {
    noTone(7);
  }

  else if (delta < 3500) {
    tone(7, 240, 200);
  } else if (delta < 3750) {
    noTone(7);
  }
    
  else if (delta < 4000) {
    tone(7, 240, 200);
  } else if (delta < 4250) {
    noTone(7);
  }
    
  else if (delta < 4500) {
    tone(7, 240, 200);
  } else if (delta < 4750) {
    noTone(7);
  }
}




void streetlight() {
  int value = analogRead(pResistor);
  if (value > 25) {
    digitalWrite(stl1, LOW);
  }
  else {
    digitalWrite(stl1, HIGH);
  }
  delay(500);
}

void intersection(long delta) {
  // 1 red 2 green 5s
  if (delta < 5000) {
    digitalWrite(tg1, LOW);
    digitalWrite(ty1, LOW);
    digitalWrite(tr1, HIGH);
    digitalWrite(tr2, LOW);
    digitalWrite(ty2, LOW);
    digitalWrite(tg2, HIGH);
  } else if ( delta < 6000) {
    // 1 red 2 yellow 3s
    digitalWrite(tg1, LOW);
    digitalWrite(ty1, LOW);
    digitalWrite(tr1, HIGH);
    digitalWrite(tr2, LOW);
    digitalWrite(ty2, HIGH);
    digitalWrite(tg2, LOW);
  } else if (delta < 11000) {
    // 1 green 2 red 5s
    digitalWrite(tg1, HIGH);
    digitalWrite(ty1, LOW);
    digitalWrite(tr1, LOW);
    digitalWrite(tr2, HIGH);
    digitalWrite(ty2, LOW);
    digitalWrite(tg2, LOW);
  } else if (delta < 12000) {
    // 1 yellow 2 red 3s
    digitalWrite(tg1, LOW);
    digitalWrite(ty1, HIGH);
    digitalWrite(tr1, LOW);
    digitalWrite(tr2, HIGH);
    digitalWrite(ty2, LOW);
    digitalWrite(tg2, LOW);
  }
}


