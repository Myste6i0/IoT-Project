String inputString ="";  

void setup() {
  Serial.begin(9600); 
}

void loop() {
  if (Serial.available()) { 
    char inputChar = Serial.read(); 
    inputString += inputChar; 
    
    if (inputString.charAt(0)== '#')&&inputString.charAt(inputString.length() - 1) == '*') { 
      String modifiedString = inputString.substring(1, inputString.length() - 1);
      Serial.println(modifiedString); 
      inputString ="";
    }
  else {
  Serial.println(inputString);
  }
  }
}