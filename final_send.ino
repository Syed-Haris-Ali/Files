/* 
 
 Created by:- Rishi Tiwari
 Website:- TrickSumo.com
 Video Tutorial:- https://youtu.be/nLzC0-VaqDs
 
 Libraries used:- 

https://github.com/mobizt/Firebase-ESP8266/

*/

#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
                          
#define FIREBASE_HOST "sectionatest-default-rtdb.firebaseio.com"                     //Your Firebase Project URL goes here without "http:" , "\" and "/"
#define FIREBASE_AUTH "n1DvFh0ImBC3LQAAkHsJo4hSNJmx6u6MlnR3oyaj"

#define WIFI_SSID "AndroidAPAB20"                                               //WiFi SSID to which you want NodeMCU to connect
#define WIFI_PASSWORD "rmrd5492"                                      //Password of your wifi network 
 
  

// Declare the Firebase Data object in the global scope
FirebaseData firebaseData;

// Declare global variable to store value
int val=0;



void setup() {

  Serial.begin(115200);                                   // Select the same baud rate if you want to see the datas on Serial Monitor

  Serial.println("Serial communication started\n\n");  
           
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                     //try to connect with wifi
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);


  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());                                            //print local IP address
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);   // connect to firebase

  Firebase.reconnectWiFi(true);
  delay(1000);
}

void loop() { 

// Firebase Error Handling And Writing Data At Specifed Path************************************************


if (Firebase.setInt(firebaseData, "/data", val)) {    // On successful Write operation, function returns 1  
               Serial.println("Value Uploaded Successfully");
               Serial.print("Val = ");
               Serial.println(val);




               
               Serial.println("\n");
               
               val++;
               delay(1000);

     }

else {        
    Serial.println(firebaseData.errorReason());
  }

}


/* NOTE:
 *  To upload value, command is ===> Firebase.setInt(firebaseData, "path", variable);
 *  Example                     ===>  Firebase.setInt(firebaseData, "/data", val);
 */
       
