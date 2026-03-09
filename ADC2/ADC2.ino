void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(A1,INPUT);
  pinMode(13,OUTPUT);

}

void loop() {
  int v = analogRead(A1);
  float val=0.0048828125;
  //val = 5/1024;
  Serial.println(v);
  Serial.println(v*val);
  Serial.println();
  digitalWrite(13,HIGH);
  delay(1000);
  digitalWrite(13,LOW);
  delay(1000);

}
