void showStart()
{
  Serial.println("-------------");
  Serial.println("- Adventure -");
  Serial.println("-------------");
}

void showScan()
{
  Serial.println("-------------");
  Serial.println("-    Scan   -");
  Serial.println("-------------");
}

void showList()
{
  for (int i = 0; i < MAX_BEACONS; i++) 
  {
    Serial.print("[");
    Serial.print(beacons[i].isCompleted);
    Serial.print("]");
    Serial.print("[");
    Serial.print(beacons[i].isNotified);
    Serial.print("]");
    Serial.print(" - ");
    Serial.print(beacons[i].id);
    Serial.print(" - ");
    Serial.print(beacons[i].name);
    Serial.print(" - ");
    Serial.print("[");
    Serial.print(beacons[i].hasMessage);
    Serial.print("]");
    Serial.println(beacons[i].message);
  }
}
