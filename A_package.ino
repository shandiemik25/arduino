#include <WiFi.h>
#include <FirebaseESP32.h>
#include <FirebaseArduino.h>
#include <ArduinoJson.h>

#define FIREBASE_HOST "https://esp32andfirebase-f0541-default-rtdb.asia-southeast1.firebasedatabase.app/"
#define FIREBASE_AUTH "sHHVED50JYjHhV3mwJUg6Y3nWS2D34veVVUHpzMQ"
#define WIFI_SSID "SHANDIE"
#define WIFI_PASSWORD "20001025"

//Define FirebaseESP32 data object
FirebaseData firebaseData;
FirebaseJson json;

// TCS230 or TCS3200 pins wiring to Arduino
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

// Stores frequency read by the photodiodes
int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;
