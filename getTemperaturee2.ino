bool getTemperaturee2() {
  char temperatureString[10];
  char humidityString[10];
 root = SD.open("Poultry.txt", FILE_WRITE);
  TempAndHumidity newValues = dht2.getTempAndHumidity();
  if (dht2.getStatus() != 0) {
    Serial.println("DHT11(2) error status: " + String(dht.getStatusString()));
    root.println("DHT11(2) error status: " + String(dht.getStatusString()));
    if(DisplayNumber==2){
    tm.DisplayStr("NO DHT 2",2);
    }
    }else{
  Serial.println("DHT 2 Reading:1 ");
  Serial.println(" T:" + String(newValues.temperature) + " H:" + String(newValues.humidity));
  root.println("DHT 2 Reading: ");
  root.println(" T:" + String(newValues.temperature) + " H:" + String(newValues.humidity));
  if(WifiStatus){
  Blynk.virtualWrite(V2, String(newValues.temperature));
  Blynk.virtualWrite(V3, String(newValues.humidity));
  }
  sprintf(temperatureString, "T2=%2.0f C    ", newValues.temperature);
  if(DisplayNumber==2){
    tm.DisplayStr(temperatureString,2);
    }
    sprintf(humidityString, "H2=%2.0f    ", newValues.humidity);
  if(DisplayNumber==3){
     tm.DisplayStr(humidityString,2);
    } 
 root.flush();
//   /* close the file */
 root.close();
}
}
