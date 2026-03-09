void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  float light = analogRead(A1);
  float Moist = analogRead(A0);
  float l = (light/1024)*100;
  float M = (Moist/1024)*100;
  float lper = 100 -l;
  float Moistper = 100 -M;
  Serial.print("*");
  Serial.print(lper);
  Serial.print(",");
  Serial.print(Moistper); 
  Serial.print("#");
  Serial.println();

  if(lper <= 50){
    digitalWrite(13,HIGH);
  }else{
    digitalWrite(13,LOW);
  }
  if(Moistper <= 50){
    digitalWrite(12,HIGH);
  }else{
    digitalWrite(12,LOW);
  }
  delay(1000);
  
}
