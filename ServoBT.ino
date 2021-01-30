#include <Servo.h>
#define rojo 10
#define verde 11
#define azul 12

Servo servomotor;
String grados,intensidad;
int numGrado,estado; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servomotor.attach(9);

  pinMode(rojo,OUTPUT);
  
}

void loop() {
  if(Serial.available()>0){
    char a = Serial.read();
    if(a=='s'){
      delay(10);
      while(Serial.available()){
        char b = Serial.read();
        grados=grados+b;
      }
      numGrado = grados.toInt();
      servomotor.write(numGrado);
      delay(15);
      grados="";
    }
  }
}

/*****************Funciones***********************/
void servoMotor()
{
  
}

void encenderLed(){
  if(Serial.available()>0){
    char a = Serial.read();
    if(a=='e'){
      digitalWrite(rojo,HIGH);
    }
    if(a=='a'){
      digitalWrite(rojo,LOW);
    }
    if(a=='r'){
      delay(10);
      while(Serial.available()){
        char b = Serial.read();
        intensidad=intensidad+b;
      }
      estado = intensidad.toInt();
      analogWrite(verde,estado);
      delay(15);
      intensidad="";
    }
  }
}
