#include <EEPROM.h>

int i = 1;
const int MAX_BEACONS = 5;  // Adjust the maximum number of beacons as needed
int addr = 0;

class Beacon {
#include "memory.h"
public:
  // Constructor
  Beacon(const char* name, const char* beaconID, int minRssi) {
    this->id = i;
    this->name = name;
    this->beaconID = beaconID;
    this->minRssi = minRssi;
    this->isCompleted = boolStatus(getValue(i-1),1);//use 1 byte for completed and notified
    this->isNotified = boolStatus(getValue(i-1),2);//use 1 byte for completed and notified

    i++;
  }
  Beacon() {}

  // Member variables
  int id;
  const char* name;
  const char* beaconID;
  int minRssi;
  bool isCompleted;
  bool isNotified;

  bool boolStatus(int value, int state)
  {
    if (state == 1)//Completed
    { if (value >= 1) { return true; } else { return false; } }
    if (state == 2)//Notified
    { if (value == 2) { return true; } else { return false; } }
  }

  // Method to mark the beacon as completed
  void markCompleted() {
    isCompleted = true;
    setValue(id-1, 1);
  }

  void markNotiofied() {
    isNotified = true;
    setValue(id-1, 2);
  }
};

// Define an array of Beacon objects
Beacon beacons[MAX_BEACONS];

void loadBeacons()
{
  beacons[0] = Beacon("Home", "UUID1", -70);
  beacons[1] = Beacon("Oakland", "UUID2", -80);
  beacons[2] = Beacon("Hollywood Studios", "UUID2", -80);
  beacons[3] = Beacon("Sugar Mill", "UUID2", -80);
  beacons[4] = Beacon("Richloam General Store", "UUID2", -80);
  
  
  Serial.println("Loaded Beacons");
}
