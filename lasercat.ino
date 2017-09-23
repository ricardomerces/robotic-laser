//
//   ROBOTIC LASER PET v1.0 - Ricardo Merces - twitter.com/r_merces 
//

#include <Servo.h>

#define POS_INICIAL 90
#define X_MINIMO    30  // Angulo de X (30 a 150) 
#define Y_MINIMO    50  // Angulo de Y (50 a 90)
#define X_INTERVALO 12 // (X maximo - X minimo) /10 = 12
#define Y_INTERVALO  4 // (Y maximo - Y minimo) /10 = 4
#define LASER_TEMPO 60 // Tempo em segundos que o laser ficará acionado
#define LASER       D1
#define PIR         D2

Servo servoX;
Servo servoY;

void setup() {
servoX.attach(D3);
servoY.attach(D4);
servoX.write(POS_INICIAL);
servoY.write(POS_INICIAL);

pinMode(LASER,OUTPUT);
digitalWrite(LASER,LOW);

pinMode(PIR, INPUT);

Serial.begin(9600);
}

void loop() {
  int trigger = digitalRead(PIR);
  if (trigger == HIGH) {
    liga_laser();
  }
  else {
    desliga_laser();
  }
  delay(1000);
}

// FUNÇÕES AUXILIARES

void posiociona_servos() {
  int posicaoX = (random(0, (X_INTERVALO)) * 10 + (X_MINIMO));
  int posicaoY = (random(0, (Y_INTERVALO)) * 10 + (Y_MINIMO));
  servoX.write(posicaoX);
  servoY.write(posicaoY);
}

void liga_laser() {
  for(int i = 0; i <= LASER_TEMPO/2; i++) {
    digitalWrite(LASER, HIGH);
    posiociona_servos();
    delay(2000);
  }
}

void desliga_laser() {
  digitalWrite(LASER, LOW);
}

