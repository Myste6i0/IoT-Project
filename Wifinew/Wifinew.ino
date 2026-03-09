#include <ESP8266WiFi.h>           // Use this for WiFi instead of Ethernet.h
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>

IPAddress server_addr(192,168,99,79);  // IP of the MySQL *server* here
char user[] = "user";              // MySQL user login username
char password[] = "12345678";        // MySQL user login password
int a=0,i=0;
String temp="";
String tempnext="";
// Sample query
//char INSERT_SQL[] = "INSERT INTO test_arduino.hello_arduino (message) VALUES ('Hello, Arduino!')";

char INSERT_SQL[] = "UPDATE iot_in.ind_plant SET Moisture_content = '%s',Light_int = '%s' WHERE Serial_no = '1'";
char query [256];

// WiFi card example
char ssid[] = "project";         // your SSID
char pass[] = "123456789";     // your SSID Password
//esp8266
WiFiClient client;                 // Use this for WiFi instead of EthernetClient
MySQL_Connection conn(&client);
MySQL_Cursor* cursor;

void setup()
{
  Serial.begin(9600);

  // Begin WiFi section
  Serial.printf("\nConnecting to %s", ssid);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // print out info about the connection:
  Serial.println("\nConnected to network");
  Serial.print("My IP address is: ");
  Serial.println(WiFi.localIP());

  Serial.print("Connecting to SQL...  ");
  if (conn.connect(server_addr, 3306, user, password))
    Serial.println("OK.");
  else
    Serial.println("FAILED.");
  
  // create MySQL cursor object
  cursor = new MySQL_Cursor(&conn);
}

void loop()
{
  if(Serial.available())  {
    char c=Serial.read();
    if(c == '*') {
      i=1;
    }
    else if(c == '#') {
      i=0;
      Serial.println(temp);
      Serial.println(tempnext);
      Serial.println("");

      if (conn.connected()) {
        sprintf (query, INSERT_SQL, String (temp).c_str(), String (tempnext).c_str());
        Serial.println (query);
        cursor->execute(query);
      }

      temp = "";
      tempnext = "";
      a=0;
    }
    else if(c == ',') {
      a=1;
    }
      
    if(i ==1) {
      if(c !='*' && c !='#' && c !=',') {
        if(a==0) {
          temp+=c;
        }
        else if(a==1) {
              tempnext+=c;
        }         
      }
    } 
  }
}


