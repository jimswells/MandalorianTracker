#include <EEPROM.h>

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

void firstLoadMemory()
{
  if (!EEPROM.begin(EEPROM_SIZE))
  { Serial.println("failed to initialise EEPROM"); }
  else
  { Serial.println("initialised EEPROM"); }

  if (getValue(60) != 7)
  {
    Serial.println("clearing inital values");
    for (int i = 0; i < EEPROM_SIZE; i++)
    { //makes sure all memory is empty
      setValue(i,0);
    }
    setValue(60,7);//Firstload bit
  }
}

void clearMemory()
{//debug 
  setValue(60,0);
  firstLoadMemory();
}
