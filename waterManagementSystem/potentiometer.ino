/*
 * HARDWARE
 * Potentiometer
 *
 * Button (left) to arduino (right):
 * 5V  -> 5V
 * GND -> GND
 * Com -> A2
 * 
 * Reads value from the potentiometer and returns (maps) it as a number between 0 and 10.
 * 
 */

int potPin = 2;
const int lowestPossibleMappedValue = 0;
const int highestPossibleMappedValue = 9; 
const int lowestPossibleValuePotMeterCanReturn = 0;
const int highestPossibleValuePotMeterCanReturn = 1000;

int getMappedPotentioMeterValue() {
  int actualValue = analogRead(potPin);
  int mappedValue = map(actualValue, lowestPossibleValuePotMeterCanReturn, highestPossibleValuePotMeterCanReturn, lowestPossibleMappedValue, highestPossibleMappedValue);
  return mappedValue;
}
