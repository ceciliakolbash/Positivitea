// Button and Sleep Functions
#include <Bounce2.h>
const uint8_t BUTTON_PINS[2] = {16, 17};      // UPDATE TO YOUR BUTTONS
Bounce * buttons = new Bounce[2];

int sleepTimer = 0;         // Track Awake
int sleepInterval = 10000;  // 10 Seconds

void initButtons(){
  for (int i = 0; i < 2; i++){
    buttons[i].attach(BUTTON_PINS[i], INPUT);
    buttons[i].interval(25);
  }
}

void checkButtons(){
  buttons[0].update(); 
  if(buttons[0].rose()){
    wifiRequest(apiUrl); 
    clearDisplay(); 
    mode = 1; 
    sleepTimer = millis();
  } 
  buttons[1].update(); 
  if(buttons[1].rose()){
    wifiRequest(apiUrl2); 
    clearDisplay(); 
    mode = 2; 
    sleepTimer = millis();
  } 
}

void checkSleep(){
  if(millis() - sleepTimer > sleepInterval){
    clearDisplay();
    mode = 0;
  }
}