bool getTemperaturee() {
  char temperatureString[10];
  char humidityString[10];
  root = SD.open("Poultry.txt", FILE_WRITE);
  TempAndHumidity newValues = dht.getTempAndHumidity();
  if (dht.getStatus() != 0) {
    Serial.println("DHT11(1) error status: " + String(dht.getStatusString()));
    root.println("DHT11(1) error status: " + String(dht.getStatusString()));
    if(DisplayNumber==0){
    tm.DisplayStr("NO DHT 1",2);
    }
    }else{
  Serial.println("DHT 1 Reading:1 ");
  Serial.println(" T:" + String(newValues.temperature) + " H:" + String(newValues.humidity));
  root.println("DHT 1 Reading: ");
  root.println(" T:" + String(newValues.temperature) + " H:" + String(newValues.humidity));
  if(WifiStatus){
    Blynk.virtualWrite(V0, String(newValues.temperature));
    Blynk.virtualWrite(V1, String(newValues.humidity));
    }
  sprintf(temperatureString, "T1=%2.0f C    ", newValues.temperature);
  if(DisplayNumber==0){
    tm.DisplayStr(temperatureString,2);
    }
    sprintf(humidityString, "H1=%2.0f   ", newValues.humidity);
  if(DisplayNumber==1){
     tm.DisplayStr(humidityString,2);
    }  
  root.flush();
//   /* close the file */
  root.close();
}
}
