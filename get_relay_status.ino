void get_relay_status(){
if(digitalRead(33)==1){
    Feedstatus = true;
    }else{
      Feedstatus = false;
      }
  if(digitalRead(32)==1){
    Lightstatus = true;
    }else{
      Lightstatus = false;
      }
  if(digitalRead(25)==1){
    Heaterstatus = true;
    }else{
      Heaterstatus = false;
      }
  if(digitalRead(25)==1){
    Fanstatus = true;
    }else{
    Fanstatus = false;
    }
}
