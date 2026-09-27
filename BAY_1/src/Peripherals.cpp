#include <Arduino.h>
#include <DHT.h>
#include "State.h"
#include "Peripherals.h"
#include "config.h"


DHT   dht(DHT_PIN , DHT_TYPE);

 float mapFloat(long x , long inMin ,long inMax , float outMin , float outMax) {
      return (x - inMin)*(outMax - outMin) /(float)(inMax - inMin) + outMin;
   }

void sample_sensor(void)
{
      int raw_current = analogRead(CURRENT_PIN); // 0 to 4095 0 to 32A
      int raw_voltage = analogRead(VOLTAGE_PIN); // 0 to 4095 0 to 250v

      // map voltage & current 
      voltage = mapFloat(raw_voltage ,0 , 4095 ,0 , 250);
      if(bayStatus == "CHARGING"){
            current = mapFloat(raw_current ,0 , 4095 ,0 , 32);
         }
         else{
            current = 0;
         }

         // calculate power 
         power = voltage * current ;

    //to read temperature 
       float t = dht.readTemperature(DHT_PIN );      
         if(!(isnan(t))){
               temperature = t ;
         }
    


}

float recentAvgCurrent(void){
   float sum = 0;
   for(int i = 0 ; i< 5 ; i++){
      sum = sum + current ;

   } return sum/5 ;
}
bool plugin_flag = 1;
bool plugout_flag = 1;

 
void plug_status(void){ 
   bool pluginread = digitalRead(BTN_PLUGIN);
   // detect the sw is pressed
      if(pluginread == LOW && plugin_flag  ){

          sessionStartMs = millis() ;

         plugin_flag =0;

         if(bayStatus == "FREE"){

            bayStatus = "CHARGING";

            Serial.println("Bay-1 plugin detected ,Bay is charging");
           
            digitalWrite(RELAY_PIN,HIGH);
         }

      }
      if(pluginread == HIGH ){
         plugin_flag = 1;
      }


   // plug out switch is pressed
  
      bool plugoutread = digitalRead(BTN_PLUGOUT);
   // detect the sw is pressed
      if(plugoutread == LOW && plugout_flag  ){
         plugout_flag =0;
         if(bayStatus == "CHARGING"){
            bayStatus = "FREE";
            Serial.println("Bay-1 plugout detected ,Bay is free ");
            digitalWrite(RELAY_PIN, LOW);

         }

      }
      if(plugoutread == HIGH ){
         plugout_flag = 1;
      }   



}


/* void update_led_status(void){
   //if bay status is charging turn ON green led
   if(bayStatus =="FREE"){
      digitalWrite(LED_GREEN, HIGH);
       digitalWrite(LED_YELLOW, LOW);

   }
   else{
      //if bay status is charging turn ON YELLOW led
        digitalWrite(LED_GREEN, LOW);
       digitalWrite(LED_YELLOW, HIGH);

   }
 


}*/