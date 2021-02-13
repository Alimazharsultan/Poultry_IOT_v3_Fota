void display_relay_status(){
  if(DisplayNumber==4){
      if(Feedstatus){
       tm.DisplayStr("FEED ON   ", 2);
      }else{
        tm.DisplayStr("FEED OFF   ", 2);
        }
    }
     if(DisplayNumber==5){
       if(Lightstatus){
      tm.DisplayStr("LIGHT ON  ", 2);
      }else{
        tm.DisplayStr("LIGHT OFF", 2);
        }
    }      
    if(DisplayNumber==6){
        if(Heaterstatus){
      tm.DisplayStr("HEATON  ", 2);
      }else{
        tm.DisplayStr("HEATOFF   ", 2);
        }  
    }
    if(DisplayNumber==7){
        if(Fanstatus){
      tm.DisplayStr("FAN ON   ", 2);
      }else{
        tm.DisplayStr("FAN OFF   ", 2);
        }  
    }
    if(DisplayNumber==8){
      if(WifiStatus){
        tm.DisplayStr("WIFI ON   ", 2);
        }else{
          tm.DisplayStr("WIFI OFF   ", 2);
          }
      }

}
