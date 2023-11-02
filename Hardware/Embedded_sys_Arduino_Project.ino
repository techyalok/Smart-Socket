
#include <ESP8266WiFi.h>  
#include <FirebaseArduino.h>  
int D1=5;
  
// Set these to run example.  
#define FIREBASE_HOST "smart-socket-705-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "WnCam2Ofr2Y9e8uKZlsGERd4B6eDcCFTOZ840pan"
#define WIFI_SSID "Alok"
#define WIFI_PASSWORD "alok1234"
  
void setup() {  
  Serial.begin(9600);  
  
  // connect to wifi.  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);  
  Serial.print("connecting");  
  while (WiFi.status() != WL_CONNECTED) {  
    Serial.print(".");  
    delay(500);  
  }  
  Serial.println();  
  Serial.print("connected: ");  
  Serial.println(WiFi.localIP());  
    
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);  
  pinMode(D1,OUTPUT);  
  Firebase.set("SOCKET_STATUS",0);  
}  
  
int n = 0;  
  
void loop() {  
  // set value  
  n=Firebase.getInt("SOCKET_STATUS");  
  // handle error  
  if (n==1) {  
      Serial.print("Socket is ON");  
      digitalWrite(D1,HIGH);  
      Serial.println(Firebase.error());    
      return;  
       delay(100);  
  }  
 else{  
   Serial.print("Socket is OFF");  
   digitalWrite(D1,LOW);  
 }  
    
  // update value  
    
}  