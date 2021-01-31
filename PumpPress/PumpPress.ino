#include <ESP8266WiFi.h>

const char *ssid = "HandSansitizer";
const char *password = "suspicious";

int val = 0;

//const char* host = "192.168.4.1";
const uint16_t port = 8888;

WiFiServer server(port);

void setup() {
  //Set up pins
  pinMode(D1, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  
  //Set up WiFi
  delay(1000);
  Serial.begin(115200);
  Serial.println();
  Serial.print("Configuring access point...");

  WiFi.softAP(ssid, password);
  
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);

  server.begin();
  
}

void loop() {

  WiFiClient client = server.available();

  if(client) {
    if(client.connected()) {
      Serial.println("Client connected");
    }
  }

  while(client.connected()) {
    client.write("test");
  }
  client.stop();
  Serial.println("Client disconnected");
  return;
  
  //Detect whether pump is pushed (HIGH is up, LOW is down)
  val = digitalRead(D1);
  //Wait a while before checking value again so pump can be pushed a few times without triggering again
  if(val == LOW)
  {
    digitalWrite(LED_BUILTIN, LOW);
    //client.println("go");
    delay(2000);
  }
  digitalWrite(LED_BUILTIN, HIGH);
}
