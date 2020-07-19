#define BLUE 6
#define RED 5
#define GREEN 3

int soundSensor = 0;
int threshold = 1023;

void setup(){
  Serial.begin(9600);
  pinMode(soundSensor, INPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void loop(){
  int sensorStatus = analogRead(soundSensor);
  Serial.println(sensorStatus);
  if(sensorStatus < threshold){
    int r = random(1, 6);
    if(r == 1){
      digitalWrite(BLUE, LOW);
      digitalWrite(RED, HIGH);
      digitalWrite(GREEN, LOW);
    }
    if(r == 2){
      digitalWrite(BLUE, 1);
      digitalWrite(RED, 0);
      digitalWrite(GREEN, 0);
    }
    if(r == 3){
     analogWrite(BLUE, random(255, 100));
     analogWrite(RED, random(255, 100));
     digitalWrite(GREEN, 1);
    }
    if(r == 4){
     digitalWrite(BLUE, 1);
     analogWrite(RED, random(255, 100));
     analogWrite(GREEN, random(255, 100));
    }
    if(r == 5){
     analogWrite(BLUE, random(255, 100));
     digitalWrite(RED, 1);
     analogWrite(GREEN, random(255, 100));
    }
    if(r == 6){
     digitalWrite(BLUE, 1);
     digitalWrite(RED, 1);
     digitalWrite(GREEN, 0);
    }
    delay(5);
  }
  else{
    digitalWrite(BLUE, HIGH);
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, HIGH);
  }
}
