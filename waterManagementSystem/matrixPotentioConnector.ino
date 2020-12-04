void showNumber(int numberToDisplay);
int getMappedPotentioMeterValue();

void showValueOnDisplay() {
  int valueToDisplay = getMappedPotentioMeterValue();
//  Serial.println("value to display: ");
//  Serial.println(valueToDisplay);
  showNumber(valueToDisplay);
}
