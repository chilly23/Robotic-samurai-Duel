#include <Servo.h>
katana_fighting_robotic_arms

Servo pr1;
Servo sr1;
Servo r1;

int pr1Pin = 5;
int sr1Pin = 6;
int r1Pin = 7;

void respect(){
  r1.write(0);
  delay(1000 / 4);
  pr1.write(120);

  delay(2000 / 4);

  pr1.write(30);
  delay(1000 / 4);
  r1.write(90);
  delay(1000 / 4);
  pr1.write(30);

  delay(2000);
}

void idle(int ms){
  int idle_pr1 = 30;
  int idle_sr1 = 25;
  int idle_r1 = 90;

  pr1.write(idle_pr1);
  sr1.write(idle_sr1);
  r1.write(idle_r1);
  delay(ms);
}

void verticalslash(){
  sr1.write(90);
  pr1.write(90);
  r1.write(180);
  delay(400);
  r1.write(0);
  idle(2000 / 4);
}

void horislash(){
  r1.write(90);
  pr1.write(90);
  sr1.write(180);
  delay(400);
  sr1.write(0);
}

void sslash(){
  r1.write(90);
  pr1.write(90);
  for (int i = 0; i <= 180; i++){
    sr1.write(i);
    r1.write(i);
    delay(5);
  }
  delay(400);
  for (int i = 180; i >= 2; i--){
    sr1.write(i);
    r1.write(i);
    delay(5);
  }
}

void stab(){
  r1.write(90);
  pr1.write(0);
  sr1.write(90);
  for (int i = 0; i <= 180; i++){
    pr1.write(i);
    sr1.write(90 + i);
    delay(5);
  }
}

void protect(){
  pr1.write(0);
  sr1.write(90);
  r1.write(180);
  delay(3000 / 4);
}

void lowslash(){
  r1.write(90);
  pr1.write(120);
  sr1.write(180);
  delay(400);
  r1.write(180);
  delay(400);
  r1.write(90);
}

void setup() {
  pr1.attach(pr1Pin);
  sr1.attach(sr1Pin);
  r1.attach(r1Pin);
  
  Serial.begin(9600);
  
  Serial.println("1 - Vertical Slash");
  Serial.println("2 - Horizontal Slash");
  Serial.println("3 - S Slash");
  Serial.println("4 - Stab");
  Serial.println("5 - Protect");
  Serial.println("6 - Low Slash");
  Serial.println("7 - Respect");
}

void loop() {
  if (Serial.available() > 0) {
    int choice = Serial.parseInt();
    
    switch (choice) {
      case 1:
        Serial.println("Performing Vertical Slash...");
        verticalslash();
        break;
      case 2:
        Serial.println("Performing Horizontal Slash...");
        horislash();
        break;
      case 3:
        Serial.println("Performing S Slash...");
        sslash();
        break;
      case 4:
        Serial.println("Performing Stab...");
        stab();
        break;
      case 5:
        Serial.println("Performing Protect...");
        protect();
        break;
      case 6:
        Serial.println("Performing Low Slash...");
        lowslash();
        break;
      case 7:
        Serial.println("Performing Respect...");
        respect();
        break;
      default:
        Serial.println("Invalid choice! Please enter a valid number.");
    }
    
    Serial.println("Choose another move:");
  }
}
