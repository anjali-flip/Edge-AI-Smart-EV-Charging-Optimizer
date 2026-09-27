#include <Arduino.h>
#include <WiFi.h>
#include "State.h"
#include "config.h"
#include "Peripherals.h"
#include "Network.h"
#include "Telemetry.h"
#include "model.h"
#include "edge_ai.h"
#include "optimization.h"
#include "rpc.h"
#include "attributes.h"




void setup()
{
// initalise serial monitor
    Serial.begin(115200);
   // initialise sesnor
    dht.begin(); 

//config esp32 with real time
    configTime(0,0,"pool.ntp.org", "time.nist.gov");
     
    //confi periperal pins
    pinMode(BTN_PLUGIN, INPUT_PULLUP);
    pinMode(BTN_PLUGOUT, INPUT_PULLUP);
    pinMode(RELAY_PIN, OUTPUT);
    pinMode(LED_GREEN,OUTPUT);
    pinMode(LED_YELLOW,OUTPUT);
    pinMode(LED_RED,OUTPUT);

    //connect board to wifi
    connectWiFi();
    
    //config mqtt server
    mqtt.setServer(MQTT_SERVER, MQTT_PORT); // mqtt server addr of things and port number 
    mqtt.setCallback(mqttCallback);
    mqtt.setBufferSize(512);
    //connect board to the cloud 
    connectMQTT(); // passing token , device id
   
}

unsigned long now;
unsigned long last_print;

void loop()
{
    mqtt.loop();
    //push data every 5 sec
    now = millis();
    if((now - last_print) > 5000)
    {
        last_print = now;
     //read data from sensors 
        sample_sensor();
     // run AI to get prediction
        runEdgeAIInference();  
    // decide load based on the predictions 
        if(manualOverrideActive == 0){
 
        runOptimization(); }
    //publish the data
        publishTelemetry() ;
    
           
    }
    plug_status();
    updateLeds();
}

