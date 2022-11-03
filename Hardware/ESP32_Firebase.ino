#if defined(ESP32)
#include <WiFi.h>
#include <FirebaseESP32.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
#endif

//Provide the token generation process info.
#include <addons/TokenHelper.h>

//Provide the RTDB payload printing info and other helper functions.
#include <addons/RTDBHelper.h>

/* 1. Define the WiFi credentials */
#define WIFI_SSID "Tawann"
#define WIFI_PASSWORD "Tawanza080"

//For the following credentials, see examples/Authentications/SignInAsUser/EmailPassword/EmailPassword.ino

/* 2. Define the API Key */
#define API_KEY "AIzaSyBZcC7DmK-CvpKgMZzovjC1GYYIci7hATk"

/* 3. Define the RTDB URL */
#define DATABASE_URL "https://esp32-project-demo-92ccf-default-rtdb.asia-southeast1.firebasedatabase.app" //<databaseName>.firebaseio.com or <databaseName>.<region>.firebasedatabase.app


//Define Firebase Data object
FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;


char mystring[10];

void setup()
{
  Serial.begin(230400);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);

  /* Assign the api key (required) */
  config.api_key = API_KEY;

  config.database_url = DATABASE_URL;



  //////////////////////////////////////////////////////////////////////////////////////////////
  //Please make sure the device free Heap is not lower than 80 k for ESP32 and 10 k for ESP8266,
  //otherwise the SSL connection will fail.
  //////////////////////////////////////////////////////////////////////////////////////////////

  Firebase.begin(DATABASE_URL, API_KEY);

  //Comment or pass false value when WiFi reconnection will control by your code or third party library
  // Firebase.reconnectWiFi(true);

  Firebase.setDoubleDigits(5);

}

void loop()
{
  if (Firebase.ready())
  {
    Serial.readBytes(mystring,9);  //Read the serial data
    Serial.println(mystring);       //Print data on Serial Monitor
    Serial.println("RECEIVER");
    delay(200);
    Serial.printf("Set string... %s\n", Firebase.setString(fbdo, "/test/string", mystring) ? "ok" : fbdo.errorReason().c_str());
//    Serial.printf("Set string... %s\n", Firebase.setString(fbdo, "/test/string2", mystring) ? "ok" : fbdo.errorReason().c_str());
//    Serial.printf("Set string... %s\n", Firebase.setString(fbdo, "/test/string3", mystring) ? "ok" : fbdo.errorReason().c_str());
//    Serial.printf("Set string... %s\n", Firebase.setString(fbdo, "/test/string4", mystring) ? "ok" : fbdo.errorReason().c_str());
//    Serial.printf("Set string... %s\n", Firebase.setString(fbdo, "/test/string5", mystring) ? "ok" : fbdo.errorReason().c_str());
  }
}
