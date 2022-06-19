#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "ThingSpeak.h"

#define  trig  D2
#define  echo  D1


unsigned long channelID =1265395;
unsigned int field_no=1;
const char* writeAPIKey = ""; // Thingspeak write API Key
const char* readAPIKey = ""; // Thingspeak read API Key

long duration;
int distance;
WiFiClient client;
// You should get Auth Token in the Blynk App.

char auth[] = "";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "";
char pass[] = "";
#define WLAN_SSID ""
#define WLAN_PASSWORD ""

BlynkTimer timer;
void wifiSetup (){
delay (10);
Serial.println(); Serial.println(WLAN_SSID);
Serial.println(F("Kablosuz Agina Baglaniyor"));
WiFi.begin(WLAN_SSID, WLAN_PASSWORD);
// WiFi durum kontrolü
while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
}
Serial.println();
Serial.print(WLAN_SSID); Serial.println("Kablosuz Aga Baglandi");
Serial.println("IP adresi: "); Serial.println(WiFi.localIP());
}

void setup()
{
  wifiSetup(); 
  // Debug console
  pinMode(trig, OUTPUT);  // Sets the trigPin as an Output
  pinMode(echo, INPUT);   // Sets the echoPin as an Inpu
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  ThingSpeak.begin(client);

  // Setup a function to be called every second
  timer.setInterval(1000L, sendSensor);
}

void loop()
{
  Blynk.run();
  timer.run();
  uzunluk(); 
}
void sendSensor()
{
  digitalWrite(trig, LOW);   // Makes trigPin low
  delayMicroseconds(2);       // 2 micro second delay

  digitalWrite(trig, HIGH);  // tigPin high
  delayMicroseconds(10);      // trigPin high for 10 micro seconds
  digitalWrite(trig, LOW);   // trigPin low

  duration = pulseIn(echo, HIGH);   //Read echo pin, time in microseconds
  distance = duration * 0.034 / 2;   //Calculating actual/real distance

  Serial.print("Distance = ");        //Output distance on arduino serial monitor
  Serial.println(distance);
  
  Blynk.virtualWrite(V0, distance);
  delay(1000);                        //Pause for 3 seconds and start measuring distance again
}

void uzunluk()
{
  Serial.print("ThingSpeak Gonderilen Uzaklık Değeri: "); Serial.println(distance);
  ThingSpeak.writeField (channelID, field_no, distance, writeAPIKey); 
  ThingSpeak.setField (1, distance); // 1 nolu field ı kur
// ThingSpeak.writeFields(channelID, writeAPIKey); // kurulu field lere yaz (çoklu yazma)
Serial.println("\n");
/* ThingSpeak Field Okuma İşlemi */
float oku = ThingSpeak.readFloatField (channelID, field_no); // ilgili kanalın belirtilen field oku
// float oku = ThingSpeak.readFloatField(channelID, field_no, readAPIKey); // private kanallar için readAPIKey
Serial.print("ThingSpeak’ten Okunan Uzunluk Değeri: "); Serial.println(oku);

}
