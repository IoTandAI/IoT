#define BLYNK_PRINT Serial

#define metal_detector_Pin D5

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

WidgetLED led1(V0); //register to virtual pin 1

char auth[] = "Auth_token";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "IoTaandAI";     //wifi name
char pass[] = "IoTaandAI"; //wifi password

void setup()
{
  Serial.begin(9600);

  pinMode(metal_detector_Pin, INPUT);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{    
  int metal_value = digitalRead(metal_detector_Pin);  
  if (metal_value == 1 ){
    led1.on();
    Serial.println(metal_value);
    Blynk.virtualWrite(V1,metal_value);
  }
  else{
    led1.off();
    Serial.println(metal_value);
    Blynk.virtualWrite(V1,metal_value);
  }
  Blynk.run();
}
