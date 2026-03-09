int a=0,i=0;
String temp="";
String tempnext="";
void setup() {
Serial.begin(9600);
}

void loop() {
  if(Serial.available())
  {
    char c=Serial.read();
    if(c == '*')
      {
        i=1;
      }
    else if(c == '#')
    {
      i=0;
      Serial.print("Light intensity = ");
      Serial.println(temp);
      Serial.print("Moisture Content = ");
      Serial.println(tempnext);
      Serial.println("");
      temp = "";
      tempnext = "";
      a=0;
     }
    else if(c == ',')
    {
      a=1;
    }
      if(i ==1) 
      {
        if(c !='*' && c !='#' && c !=',')
        {
          if(a==0)
          {
            temp+=c;
          }
          else if(a==1)
          {
               tempnext+=c;
          }         
        }
      } 
  }
}
