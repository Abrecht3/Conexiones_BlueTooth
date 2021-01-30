#define rojo 9
#define verde 10
#define azul 11

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(rojo,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
  char a = Serial.read();
  if(a=='e'){
    digitalWrite(rojo,HIGH);
  }
  if(a=='a'){
    digitalWrite(rojo,LOW);
  }
  }
}
