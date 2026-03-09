//Analog to digital converter(ADC)
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(A0,INPUT);
  pinMode(13,OUTPUT);

}

void loop() {
  int v = analogRead(A0);
  Serial.println(v);
  digitalWrite(13,HIGH);
  delay(1000);
  digitalWrite(13,LOW);
  delay(1000);

}
