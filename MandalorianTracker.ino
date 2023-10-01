//Mando Tracker
//Bluetooth beacon tracker for scavenger hunt

#include "beacons.h"
#include "memory.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(1000);
  Serial.println("Starting");
  loadMemory();

  //Load beacon with saved data
  loadBeacons();

  
  showStart();
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if (Serial.available() > 0) {
    // get incoming byte:
    String inByte = Serial.readString();
    inByte.trim();
    // read first analog input, divide by 4 to make the range 0-255:
    //Serial.println(beacons[inByte].name);
    //beacons[inByte].markCompleted();    
    //Serial.print("-");
    //Serial.print(inByte);
    //Serial.println("-");
    if (inByte == "list")
    {
      showList();
    }
    if (inByte == "start")
    {
      showStart();
    }
    if (inByte == "scan")
    {
      showScan();
    }

    if (inByte == "C")
    {
      clearMemory();
    }
    
    if (inByte == "1")
    {
      beacons[4].markCompleted(); 
    }
  }
}

void showStart()
{
  Serial.print("-------------");
  Serial.print("- Adventure -");
  Serial.println("-------------");
}

void showScan()
{
  Serial.print("-------------");
  Serial.print("-    Scan   -");
  Serial.println("-------------");
}

void showList()
{
  for (int i = 0; i < 5; i++)
    {
      Serial.print("[");
      Serial.print(beacons[i].isCompleted);
      Serial.print("]");
      Serial.print(" - ");
      Serial.print(beacons[i].id);
      Serial.print(" - ");
      Serial.println(beacons[i].name);
    }
}
