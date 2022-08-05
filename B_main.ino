void setup()
{
  setWarna();

  Serial.begin(115200);

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

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

  //Set database read timeout to 1 minute (max 15 minutes)
  Firebase.setReadTimeout(firebaseData, 1000 * 60);
  //tiny, small, medium, large and unlimited.
  //Size and its write timeout e.g. tiny (1s), small (10s), medium (30s) and large (60s).
  Firebase.setwriteSizeLimit(firebaseData, "small");

  /*
  This option allows get and delete functions (PUT and DELETE HTTP requests) works for device connected behind the
  Firewall that allows only GET and POST requests.
  
  Firebase.enableClassicRequest(firebaseData, true);
  */

  //String path = "/data";
  

  Serial.println("------------------------------------");
  Serial.println("Connected...");
   setSuara();
}

void loop()
{
  loopWarna();
  
  int Rdata = redFrequency;
  int Gdata = greenFrequency;
  int Bdata = blueFrequency;
  if (Rdata >= 200 || Gdata >= 200 || Bdata >= 200){
    Serial.println("UANG TIDAK TERDETEKSI");
  }
  else {
    Serial.print(Rdata);
    Serial.print(Gdata);
    Serial.print(Bdata);
    delay(1000); 
    json.set("/r", Rdata);
    json.set("/g", Gdata);
    json.set("/b", Bdata);
    Firebase.updateNode(firebaseData,"/Sensor",json); 
  }
  delay(5000);
  Serial.print("Nominal : ");
  //Serial.println(Firebase.getString("Output/Output_nominal"));
  //String output = Firebase.getString("Output/Output_nominal");
  if (output = "Uang Seratus Ribu Rupiah"){
    x = 7
    loopWarna();
}
  else if (output = "Uang Lima Puluh Ribu Rupiah"){
    x = 6
    loopWarna();
  }
  else if (output = "Uang Dua Puluh Ribu Rupiah"){
    x = 5
    loopWarna();
  }
  else if (output = "Uang Sepuluh Ribu Rupiah"){
    x = 4
    loopWarna();
  }
  else if (output = "Uang Lima Ribu Rupiah"){
    x = 3
    loopWarna();
  }
  else if (output = "Uang Dua Ribu Rupiah"){
    x = 2
    loopWarna();
  }
  else {
    x = 1
    loopWarna();
  }
}
