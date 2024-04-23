// InfoClip Starter Code
// Zane Cochran
// 13 APR 2024

// Setup
const char* ssid = "EZConnect";
const char* password = "gXJ386fZm3";
String apiUrl = "https://api.quotable.io/quotes/random"; // ***UPDATE THIS***
String apiUrl2 = "https://www.affirmations.dev/";

// Information
String content = "";
String author = "";
String affirmation = "";

// State Machine
int mode = -1;
int lastMode = -1;

void setup() {
  Serial.begin(115200);
  delay(2000);

  wifiConnect();
  wifiRequest(apiUrl);
  wifiRequest(apiUrl2);
  initDisplay();
  initButtons();
}

void loop() {
  checkButtons();
  checkSleep();

  switch(mode){
    case -1: showIntro(); break;
    case 0: showSleep(); break;
    case 1: showQuote(); break;
    case 2: showAffirmation(); break;
  }
}
