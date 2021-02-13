void set_relay_status(){
  readkey = tm.ReadKey16Two();
if(readkey==16){
    if(Feedstatus){
      Serial.println("R1 low");
       digitalWrite(FEED, LOW); // sets the digital pin 13 on
      Feedstatus=false;
      }else{
        Serial.println("R1 HIGH");
         digitalWrite(FEED, HIGH); // sets the digital pin 13 on
         Feedstatus=true;
        }
        delay(500);
    }else if(readkey==32){
       if(Lightstatus){
       digitalWrite(LIGHT, LOW); // sets the digital pin 13 on
      Lightstatus=false;
      }else{
         digitalWrite(LIGHT, HIGH); // sets the digital pin 13 on
         Lightstatus=true;
        }
        delay(500);
      }else if(readkey==64){
        if(Heaterstatus){
       digitalWrite(HEATER, LOW); // sets the digital pin 13 on
      Heaterstatus=false;
      }else{
         digitalWrite(HEATER, HIGH); // sets the digital pin 13 on
         Heaterstatus=true;
        }
      }else if(readkey==128){
        if(Fanstatus){
       digitalWrite(FAN, LOW); // sets the digital pin 13 on
      Fanstatus=false;
      }else{
         digitalWrite(FAN, HIGH); // sets the digital pin 13 on
         Fanstatus=true;
        }
}
}
