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
    Serial.println(beacons[i].name);
  }
}
