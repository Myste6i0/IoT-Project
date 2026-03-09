int i = 0;
void setup() {
 // int j=1;
  // put your setup code here, to run once:
  Serial.begin(9600);
   pinMode(13,OUTPUT);
  
}

void loop() {
 if(i==0){
   digitalWrite(13,HIGH);
   delay(100);
   digitalWrite(13,LOW);
   delay(100);
 } 
 if(Serial.available()>0){
   char recval =Serial.read();
   if(recval == 'a'){
     i = !i;
   }
 }
}
// *hello#




