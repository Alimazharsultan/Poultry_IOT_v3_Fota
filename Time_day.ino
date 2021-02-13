void Time_day()
{
  root = SD.open("Poultry.txt", FILE_WRITE);
  DateTime now = rtc.now();
  if (! rtc.begin()) {
    Serial.println("No RTC Found");
   root.println("No RTC Found");
    //display.setSegments(SEG_F002);
   return;
  }else{
    Serial.print("Time:- ");
    Serial.print(now.hour()); Serial.print(":"); Serial.print(now.minute()); Serial.print(":"); Serial.println(now.second());
    Serial.print("Date:-");
    Serial.print(now.year());Serial.print("/");Serial.print(now.month());Serial.print("/");Serial.println(now.day());
    
    root.print("Time:- ");
    root.print(now.hour()); root.print(":"); root.print(now.minute()); root.print(":"); root.println(now.second());
    root.print("Date:-");
    root.print(now.year());root.print("/");root.print(now.month());root.print("/");root.println(now.day());
    
    }
   root.flush();
   /* close the file */
   root.close();
}
