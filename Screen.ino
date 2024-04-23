// Images
#include "positivityPic.h"
#include "teaPic.h"

// Screen Libraries
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#define i2c_Address 0x3c //initialize with the I2C addr 0x3C Typically eBay OLED's
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1   //   QT-PY / XIAO
Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void initDisplay(){
  display.begin(i2c_Address, true);
  display.clearDisplay();
  display.display();
  display.setRotation(0);
}

void showIntro(){
  display.drawBitmap(0, 0, positivityPic, 128, 64, SH110X_WHITE);
  display.setCursor(10, 48);
  display.setTextWrap(true);
  display.display();
  delay(3000);
}

void showQuote(){
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(0, 0);
  display.print(content);
  display.setCursor(0,54);
  display.print(author);
  display.display();
}

void showAffirmation(){
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(0, 0);
  display.print(affirmation);
  display.display();
}

int teaX = 32;  int teaSpeedY = 1;
int teaY = 32;  int teaSpeedX = 1;

void showSleep(){
  teaX += teaSpeedX;
  teaY += teaSpeedY;
  display.drawBitmap(teaX, teaY, teaPic, 32, 32, SH110X_WHITE);
  if(teaX < 0 || teaX > 128){teaSpeedX = -teaSpeedX;}
  if(teaY < 0 || teaY > 64){teaSpeedY = -teaSpeedY;}
  display.display();
}

void clearDisplay(){display.clearDisplay();}