#include <EEPROM.h>
#include <memory.h>

int i = 1;
const int MAX_BEACONS = 5;  // Adjust the maximum number of beacons as needed
int addr = 0;
#define EEPROM_SIZE 64

int getValue(int value)
{
  return EEPROM.read(value);
}

void setValue(int addr, int value)
{
  EEPROM.write(addr, value);
  EEPROM.commit();
}

void loadMemory()
{
  if (!EEPROM.begin(EEPROM_SIZE))
  {
    Serial.println("failed to initialise EEPROM");
  }
  else
  {
    Serial.println("initialised EEPROM");
  }

  if (getValue(60) != 7)
  {
    Serial.println("clearing inital values");
    for (int i = 0; i < EEPROM_SIZE; i++)
    { 
      setValue(i,0);
    }
    setValue(60,7);
  }
}

void clearMemory()
{
  Serial.println("clearing inital values");
  for (int i = 0; i < EEPROM_SIZE; i++)
  { 
    setValue(i,0);
  }
}

class Beacon {
public:
  // Constructor
  Beacon(const char* name, const char* beaconID, int minRssi) {
    this->id = i;
    this->name = name;
    this->beaconID = beaconID;
    this->minRssi = minRssi;
    this->isCompleted = getValue(i-1);
    this->isNotified = getValue(i + 19);;

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

  // Method to mark the beacon as completed
  void markCompleted() {
    isCompleted = true;
    setValue(id, isCompleted);
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
