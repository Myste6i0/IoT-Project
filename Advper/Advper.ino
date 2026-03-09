//Soil Moister
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);

}

void loop() {
  //String s;
  
  // put your main code here, to run repeatedly:
  float l = analogRead(A1);
  float v = analogRead(A0);
  
  float p = (v/1024)*100;
  float per;
  Serial.println(v);
  per = 100-p;
  Serial.print("Moisture content : ");
  Serial.print(per);

  Serial.println("%");
  //Serial.println(val*v);
  Serial.println(" ");
  float lp = (l/1024)*100;
  float lper;
  lper = 100 - p;
  Serial.print("Light intensity : ");
  Serial.print(lper);
  if(per <= 50){
    digitalWrite(13,HIGH);
  }else{
    digitalWrite(13,LOW);
  }
  if(lper <= 50){
    digitalWrite(13,HIGH);
  }else{
    digitalWrite(13,LOW);
  }
  delay(1000);
  // delay(1000);
  // digitalWrite(12,HIGH);
  // delay(1000);
  // digitalWrite(12,LOW);
  // delay(1000);
}



//*data1,data2#


