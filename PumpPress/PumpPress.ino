#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char *ssid = "HandSansitizer";
const char *password = "suspicious";

ESP8266WebServer server(80);

int val = 0;

//Called when client connects
void handleRoot() {
  server.send(200, "text/plain", "Hello");
}

void setup() {
  //Set up pins
  pinMode(D1, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  
  //Set up WiFi
  delay(1000);
  Serial.begin(115200);
  Serial.println();
  Serial.print("Configuring access point...");

  WiFi.softAP(ssid, password);
  
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started");
  
}

void loop() {
  server.handleClient();
  
  //Detect whether pump is pushed (HIGH is up, LOW is down)
  val = digitalRead(D1);
  //Wait a while before checking value again so pump can be pushed a few times without triggering again
  if(val == LOW)
  {
    digitalWrite(LED_BUILTIN, LOW);
    server.send(200, "text/plain", "yes");
    delay(2000);
  }
  digitalWrite(LED_BUILTIN, HIGH);
}
