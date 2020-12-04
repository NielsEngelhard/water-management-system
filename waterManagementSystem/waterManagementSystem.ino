void matrixSetup();
void showValueOnDisplay();

void setup() {
  matrixSetup();
  Serial.begin(9600);
}

void loop() {
  showValueOnDisplay();
}

 
