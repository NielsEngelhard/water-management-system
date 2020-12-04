#include "LedControl.h"

const int DINPin = 12;
const int CLKPin = 11;
const int CSPin = 10;
const int nOfDisplaysConnected = 1;
 
LedControl lc=LedControl(DINPin,CLKPin,CSPin,nOfDisplaysConnected);

const int lowestPossibleNumberToShow = 0;
const int highestPossibleNumberToShow = 9;
byte numbersToShow[10][8] = {
  {B00000000, B01111110, B01000010, B01000010, B01000010, B01000010, B01111110, B00000000},   // zero
  {B00000000, B00100010, B01000010, B11111110, B11111110, B00000010, B00000010, B00000000},  // one
  {B00000000, B01000110, B10001010, B10010010, B01100010, B00000000, B00000000, B00000000},  // two
  {B00000000, B00000000, B01111110, B00000000, B00000000, B00000000, B00000000, B00000000},  // three
  {B00000000, B00000000, B00000000, B01111110, B00000000, B00000000, B00000000, B00000000},  // four
  {B00000000, B00000000, B00000000, B00000000, B01111110, B00000000, B00000000, B00000000},  // five
  {B00000000, B00000000, B00000000, B00000000, B00000000, B01111110, B00000000, B00000000},  // six
  {B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B01111110, B00000000},  // seven
  {B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B01111110},  // eight
  {B01111110, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000}   // nine
  };
byte error[] = {B10000001, B01000010, B00100100, B00011000, B00011000, B00100100, B01000010, B10000001};
 
void matrixSetup() {
  lc.shutdown(0,false);  // Wake up displays
  lc.setIntensity(0,5);  // Set intensity levels
  lc.clearDisplay(0);  // Clear Displays
}

void displayNumberByByteArray(int number) {
  for (int i = 0; i < 8; i++)  { lc.setRow(0,i,numbersToShow[number][i]); }
}

void displayErrorOnMatrix() {
  for (int i = 0; i < 8; i++)  { lc.setRow(0,i,error[i]); }
}

void showNumber(int numberToDisplay) {
  Serial.println("Show number: ");
  Serial.println(numberToDisplay);
  if (numberToDisplay >= lowestPossibleNumberToShow && numberToDisplay <= highestPossibleNumberToShow) {
    displayNumberByByteArray(numberToDisplay);
  } else {
    displayErrorOnMatrix();
  }
}
