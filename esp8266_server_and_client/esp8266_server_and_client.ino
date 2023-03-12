#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WebServer.h>

const char *ssid = "HA";
const char *password = "@semfio123";
String endpoint = "http://192.168.0.116:1880/endpoint/test"; // OBS: It does not resolve DNS. Only use IPs

ESP8266WebServer server(80);
void handleRoot() {
 server.send(200, "text/html", "<form action=\"/LED_BUILTIN_on\" method=\"get\" id=\"form1\"></form><button type=\"submit\" form=\"form1\" value=\"On\">On</button><form action=\"/LED_BUILTIN_off\" method=\"get\" id=\"form2\"></form><button type=\"submit\" form=\"form2\" value=\"Off\">Off</button>");
}
void handleSave() {
 if (server.arg("pass") != "") {
   Serial.println(server.arg("pass"));
 }
}
void setup() {
 pinMode(LED_BUILTIN, OUTPUT);
 delay(3000);
 Serial.begin(115200);
 Serial.println();
 Serial.print("Configuring access point...");
 WiFi.begin(ssid, password);
 while (WiFi.status() != WL_CONNECTED) {
   delay(500);
   Serial.print(".");
 }
 Serial.println("");
 Serial.println("WiFi connected");
 Serial.println("IP address: ");
 Serial.println(WiFi.localIP());
 server.on ( "/", handleRoot );
 server.on ("/save", handleSave);
 server.begin();
 Serial.println ( "HTTP server started" );
 server.on("/LED_BUILTIN_on", []() {
   digitalWrite(LED_BUILTIN, 1);
   Serial.println("on");
   WiFiClient client;
   HTTPClient http;
    
   // Your Domain name with URL path or IP address with path
   http.begin(client, "http://192.168.0.116:1880/endpoint/test?status=1");
  
   // Send HTTP GET request
   int httpResponseCode = http.GET();
   Serial.print("Response: ");
   Serial.println(httpResponseCode);
   handleRoot();
 });
 server.on("/LED_BUILTIN_off", []() {
   digitalWrite(LED_BUILTIN, 0);
   Serial.println("off");
   WiFiClient client;
   HTTPClient http;
    
   // Your Domain name with URL path or IP address with path
   http.begin(client, "http://192.168.0.116:1880/endpoint/test?status=0");
  
   // Send HTTP GET request
   int httpResponseCode = http.GET();
   Serial.print("Response: ");
   Serial.println(httpResponseCode);
   http.end();
   handleRoot();
 });
}
void loop() {
 server.handleClient();
} 
