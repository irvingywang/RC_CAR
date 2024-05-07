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

  VRX -= 505;
  VRY -= 504;
  VRY *= -1;

  Serial.print("x: ");
  Serial.println(VRX);
  Serial.print("y: ");
  Serial.println(VRY);
  delay(100);
}
