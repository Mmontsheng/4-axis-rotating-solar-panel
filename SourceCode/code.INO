
#include <Servo.h> // include Servo library 

Servo horizontal; // horizontal servo
int servoh = 90;     // stand horizontal servo

Servo vertical;   // vertical servo
int servov = 90;     // stand vertical servo

// LDR pin connections
//  name  = analogpin;
int eastLDR = A0; //LDR top left
int westLDR = A1; //LDR top rigt
int northLDR = A2; //LDR down left
int southLDR = A3; //ldr down rigt

float westValue = 0;
float eastValue = 0;
float southValue = 0;
float northValue = 0;
int angle = 65;
void setup()
{
  Serial.begin(9600);
  // servo connections
  // name.attacht(pin);
  horizontal.attach(9);
  vertical.attach(10);
  horizontal.write(angle);
  pinMode(eastLDR, INPUT);
  pinMode(westLDR, INPUT);
  pinMode(northLDR, INPUT);
  pinMode(southLDR, INPUT);
  
}

void loop()
{

  westValue = analogRead(westLDR);
  eastValue = analogRead(eastLDR);
  southValue = analogRead(southLDR);
  northValue = analogRead(northLDR);


  Serial.print("WEST VALUE : ");
  Serial.println(westValue);
 /* Serial.println();
  Serial.print("SOUTH VALUE : ");
  Serial.println(southValue);
  Serial.println();
*/
  if (westValue > eastValue) {
    // go west
    angle++;
    if (angle >= 165) {
      angle = 135;
    }
    horizontal.write(angle);
  } else if (eastValue>westValue) {
    angle--;
    if (angle <= 15) {
      angle = 15;
    }
    horizontal.write(angle);
  }else if((abs(eastValue-westValue))==0){
    horizontal.write(angle);
  }
  delay(10);
}
