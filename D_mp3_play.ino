void setSuara()
{
  Serial.begin(115200);
  Serial2.begin(9600);
  delay(100);

  Serial.println();
  Serial.println("DFRobot DFPlayer Mini Demo");
  Serial.println("Initializing DFPlayer ... (May take 3~5 seconds)");

  if (!mp3.begin(Serial2)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while (true);
  }
  Serial.println("DFPlayer Mini online.");
  mp3.setTimeOut(500); //Set serial communictaion time out 500ms
  mp3.volume(50);  //Set volume value (0~30).
//  delay(1000);
//  mp3.play(98);  //Play the first mp3
  delay(1000);
}
void loopWarna(suara)
{
  mp3.play (suara);
  delay (6000);
}
