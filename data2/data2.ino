void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
   pinMode(13,OUTPUT);
  
}

void loop() {
  
 Serial.available();
 char var=Serial.read();
 if(var == 'a'){
 Serial.print("Bavan");
// // for(int i=0;i<5;i++){
 }
digitalWrite(13,HIGH);
  delay(100);
  digitalWrite(13,LOW);
  delay(100);
}
