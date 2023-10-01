//Mando Tracker
//Bluetooth beacon tracker for scavenger hunt

#include <WiFi.h>
#include <WebServer.h>
#include <EMailSender.h>
#include "beacons.h"
#include "screen.h"
#include "memory.h"

bool debugMode = true;
const char* ssid       = "<WIFI>";
const char* password   = "<password>";
EMailSender emailSend("<Gmailfromemail>", "<GMailpasscode>");
const char* smsAddress = "<toaddress>";

WebServer server(80);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Starting");
 
  //Load beacon with saved data
  firstLoadMemory();
  loadBeacons();

  //Inital page
  showStart();

  checkNotifications();
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if (Serial.available() > 0) {
    // get incoming byte:
    String inByte = Serial.readString();
    inByte.trim();

    if (inByte == "list") { showList(); }
    if (inByte == "start"){ showStart(); }
    if (inByte == "scan") { showScan(); }
    if (inByte == "reset"){ clearMemory(); }
    
    if (inByte == "1") { beacons[0].markCompleted(); }
    if (inByte == "11"){ beacons[0].markNotiofied(); }
    if (inByte == "2") { beacons[1].markCompleted(); }
    if (inByte == "22"){ beacons[1].markNotiofied(); }
    if (inByte == "3") { beacons[2].markCompleted(); }
    if (inByte == "33"){ beacons[2].markNotiofied(); }
    if (inByte == "4") { beacons[3].markCompleted(); }
    if (inByte == "44"){ beacons[3].markNotiofied(); }
    if (inByte == "5") { beacons[4].markCompleted(); }
    if (inByte == "55"){ beacons[4].markNotiofied(); }
  }
}

void checkNotifications()
{
  
  // Connect to WiFi network
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
  for (int i = 0; i < MAX_BEACONS; i++)
  {
    if (beacons[i].isCompleted == true && beacons[i].isNotified == false)
    {
      beacons[i].markNotiofied();
      EMailSender::EMailMessage message;
      message.subject = "Adventure";
      message.message = String(beacons[i].name) + " has been completed";
      
      EMailSender::Response resp = emailSend.send(smsAddress, message);

      Serial.println("Sending status: ");
      Serial.println(resp.status);
      Serial.println(resp.code);
      Serial.println(resp.desc);
      Serial.println("Sending notificaton for " + String(beacons[i].name));
      server.send(200,"text/html","Ok");
    }
  }
}

void ping()//Not used yet
{
    //connect to WiFi
  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
  }
  Serial.println(" CONNECTED");
}
