// C++ code
//
int pin_led1 = 8;
int pin_led2 = 9;
int pin_led3 = 10;
int pin_led4 = 11;

int pin_triger = 7;
int pin_echo = 5;

void setup()
{
  //앞에는 핀번호
  pinMode(pin_led1, OUTPUT);
  pinMode(pin_triger, OUTPUT); //내보냄
  pinMode(pin_echo, INPUT);
  
  //아두이노에 유에스비 꽂으면 vs쪽으로 와서 내 노트북에 찍힘
  Serial.begin(9600);
}

void loop()
{
  int distance = 0;
  //트리거  잠깐 줬다가 뗀다
  //초음파 센서 코드 부분
  digitalWrite(pin_triger, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin_triger, LOW);
  
  distance = pulseIn(pin_echo, HIGH);
  int cm = distance / 63;
  //값을 받아서 출력
  //Serial.println(cm);
  
  
  if(cm>200) {
    Serial.println("led off");
    digitalWrite(pin_led1, LOW);
    digitalWrite(pin_led2, LOW);
    digitalWrite(pin_led3, LOW);
    digitalWrite(pin_led4, LOW);
    
    
  } else if(cm<=200 && cm >170) {
    digitalWrite(pin_led1, HIGH);
    digitalWrite(pin_led2, LOW);
    digitalWrite(pin_led3, LOW);
    digitalWrite(pin_led4, LOW);
    
  } else if(cm<=170 && cm>130){
    digitalWrite(pin_led1, HIGH);
    digitalWrite(pin_led2, HIGH);
    digitalWrite(pin_led3, LOW);
    digitalWrite(pin_led4, LOW);
    
  } else if(cm<=130 && cm>100){
    digitalWrite(pin_led1, HIGH);
    digitalWrite(pin_led2, HIGH);
    digitalWrite(pin_led3, HIGH);
    digitalWrite(pin_led4, LOW);
    
  } else {
    digitalWrite(pin_led1, HIGH);
    digitalWrite(pin_led2, HIGH);
    digitalWrite(pin_led3, HIGH);
    digitalWrite(pin_led4, HIGH);
    
    
  }
  
}