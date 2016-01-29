#define trigPin 9
#define echoPin 3

int BackLeftmotorPin = 7;
int ForthLeftmotorPin = 8;
int BackRightmotorPin = 2;
int ForthRightmotorPin = 4;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(BackLeftmotorPin, OUTPUT);
  pinMode(BackRightmotorPin, OUTPUT);
  pinMode(ForthLeftmotorPin, OUTPUT);
  pinMode(ForthRightmotorPin, OUTPUT);

}
void loop() {
  if(Serial.available()){
    // 讀出第 1 個字元
    unsigned char charreceived = Serial.read();
    
    switch(charreceived){
      case '1':
        digitalWrite(ForthRightmotorPin, HIGH);//往左前方轉
        break;
      case '2':
        digitalWrite(ForthLeftmotorPin, HIGH);//前進
        digitalWrite(ForthRightmotorPin, HIGH);
        break;
      case '3':
        digitalWrite(ForthLeftmotorPin, HIGH);//往右前方轉
        break;
      case '4':
        digitalWrite(BackLeftmotorPin, HIGH);//往正左轉
        digitalWrite(ForthRightmotorPin, HIGH);
        break;
      case '5':
        digitalWrite(BackLeftmotorPin, LOW);//停止
        digitalWrite(BackRightmotorPin, LOW);
        digitalWrite(ForthLeftmotorPin, LOW);
        digitalWrite(ForthRightmotorPin, LOW);
        break;
      case '6':
        digitalWrite(ForthLeftmotorPin, HIGH);//往正右轉
        digitalWrite(BackRightmotorPin, HIGH);
        break;
         case '7':
        digitalWrite(BackRightmotorPin, HIGH);//往左後方轉
        break;
      case '8':
        digitalWrite(BackLeftmotorPin, HIGH);//後退
        digitalWrite(BackRightmotorPin, HIGH);
        break;
      case '9':
        digitalWrite(BackLeftmotorPin, HIGH);//往右後方轉
        break;
      default:
        break;
    }
    
    // 清掉後續的字元，我們只要第 1 個字元
    Serial.flush();
  }
  delay(100);
  
  //超音波避障
  int duration,distance;
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin,HIGH);
  distance = (duration/2) / 29.1;//換算出距離
  if(distance<=15 && distance>=0){
    digitalWrite(BackLeftmotorPin, LOW);//停止
    digitalWrite(BackRightmotorPin, LOW);
    digitalWrite(ForthLeftmotorPin, LOW);
    digitalWrite(ForthRightmotorPin, LOW);
    delay(1000);
    digitalWrite(ForthLeftmotorPin, HIGH);//往正右轉1秒
    digitalWrite(BackRightmotorPin, HIGH);
    delay(1000);
    digitalWrite(ForthLeftmotorPin, LOW);
    digitalWrite(BackRightmotorPin, LOW);
  }
} 

