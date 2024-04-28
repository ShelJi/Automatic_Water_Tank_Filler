#define trig 2
#define echo 3
#define pump 4
#define led 5

long duration;
int lvl;

void setup() {
  // put your setup code here, to run once:
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(pump,OUTPUT);
  pinMode(led,OUTPUT);

  digitalWrite(pump,LOW);
  digitalWrite(led,LOW);

  Serial.begin(9600);
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  waterlvl();
  Serial.println(lvl);
  pmp();
  leed();
}

void waterlvl(){
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  duration=pulseIn(echo,HIGH);
  lvl=duration*0.034/2;
}

void pmp(){
  if(lvl>=10){
    delay(1000);
    waterlvl();
    if(lvl>=10){
      digitalWrite(pump,HIGH);
    }
    //digitalWrite(pump,HIGH);
  }
  else if(lvl>=4);
  else if(lvl<=3){
    digitalWrite(pump,LOW);
  }
  else {
    digitalWrite(pump,LOW);
  }
}

void leed(){
  if(lvl>=9){
    digitalWrite(led,HIGH);
    delay(1000);
  }
  else if(lvl>=6){
      digitalWrite(led,HIGH);
      delay(500);
      digitalWrite(led,LOW);
      delay(500);
  }
  else {
    digitalWrite(led,LOW);
    delay(1000);
  }
}