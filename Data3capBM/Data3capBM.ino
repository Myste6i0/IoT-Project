void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() {
  
  String var;
  if(Serial.read() > 0){
    var=Serial.read();
  } 
  
  Serial.println(var);

//   if(var == 'a'){
//   // for(int i=0;i<5;i++){
//   // }
// // digitalWrite(13,HIGH);
// //   delay(100);
// //   digitalWrite(13,LOW);
// //   delay(100);
// //Serial.print("A");
// if(Serial.available() == 0){
//   // char h=Serial.read();
//   // if()

//    // Serial.print("Not present");
//   }else{
//     Serial.print("present");
//   }
  delay(1000);
}
