#include <ESP8266WiFi.h>

const char* ssid = "ELSHINNAWEY4G";    //  Your Wi-Fi Name
const char* password = "1771962ma";   // Wi-Fi Password

int right = 2;   // led connected to GPIO2 (D4)
int left  = 0;
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  pinMode(right, OUTPUT);
  pinMode(left, OUTPUT);
  digitalWrite(right, LOW);
  digitalWrite(left , LOW);
  Serial.print("Connecting to the Newtork");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
  server.begin();
  Serial.println("Server started");
  Serial.print("IP Address of network: "); // will IP address on Serial Monitor
  Serial.println(WiFi.localIP());
  Serial.print("Copy and paste the following URL: https://"); // Will print IP address in URL format
  Serial.print(WiFi.localIP());
  Serial.println("/");
}

void loop()
{
  WiFiClient client = server.available();
  if (!client)
  {
    return;
  }
  Serial.println("Waiting for new client");
  while (!client.available())
  {
    delay(1);
  }
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
  int value = LOW;

  if (request.indexOf("/Right") != -1)
  {
    digitalWrite(right, HIGH);
    digitalWrite(left , LOW);
  }

  if (request.indexOf("/Left") != -1)
  {
    digitalWrite(right, LOW);
    digitalWrite(left , HIGH);
  }
  if (request.indexOf("/Stop") != -1)
  {
    digitalWrite(right, LOW);
    digitalWrite(left , LOW);
  }

  client.println("HTTP/1.1 200 OK"); //
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<br><br>");
  client.println("<a href=\"/Left\"\"><button><--</button></a>");
  client.println("<a href=\"/Stop\"\"><button>Stop</button></a>");
  client.println("<a href=\"/Right\"\"><button>--></button></a>");
  client.println("</html>");
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
}
