const int VRXPin = A0;
const int VRYPin = A1;

int VRX;
int VRY;

void setup() {
  Serial.begin(9600);
}

void loop() {
  VRX = analogRead(VRXPin);
  VRY = analogRead(VRYPin);

  Serial.println(VRX);
  Serial.println(VRY);
  delay(100);
}
