//char j = 'a';
void setup() {
 // int j=1;
  // put your setup code here, to run once:
  Serial.begin(9600);
   pinMode(13,OUTPUT);
  
}

void loop() {
   int i=0;
 Serial.available();
 char c=Serial.read();
 //char varr=Serial.read();

 //char varr;
 if(c == 'a'&& i==0){
   digitalWrite(13,HIGH);
   delay(100);
   digitalWrite(13,LOW);
   delay(100);
   i=1;
 }

 //char t= var;
 if(c == 'a'&& i==1){
     //j = 'r';
   digitalWrite(13,LOW);
   i=0;
   // j='a';
 }
 
  /*if(var == 'a'){
      j=a;
     digitalWrite(13,HIGH);
       delay(100);
      digitalWrite(13,LOW);
       delay(100);
  }*/
 
}


