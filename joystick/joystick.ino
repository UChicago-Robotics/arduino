#define joyX A0
#define joyY A1
int x, y;
const int redPin1 = 7;
const int blackPin1 = 6;
const int redPin2 = 5;
const int blackPin2 = 4;
 
void setup() {
  Serial.begin(9600);
  pinMode(redPin1, OUTPUT);
  pinMode(blackPin1, OUTPUT);
  pinMode(redPin2, OUTPUT);
  pinMode(blackPin2, OUTPUT);
}
 
void loop() {
  // put your main code here, to run repeatedly:
  x = analogRead(joyX);
  y = analogRead(joyY);

  // Down: clockwise
  if (y > 550 && (x < 550 && x > 450)) {
    digitalWrite(redPin1, HIGH);
    digitalWrite(blackPin1, LOW);
    digitalWrite(redPin2, HIGH);
    digitalWrite(blackPin2, LOW);
  }
  // Up: counterclockwise
  else if (y < 450 && (x < 550 && x > 450)) {
    digitalWrite(redPin1, LOW);
    digitalWrite(blackPin1, HIGH);
    digitalWrite(redPin2, LOW);
    digitalWrite(blackPin2, HIGH);
  }
  // Left: 1 clockwise, 2 counterclockwise
  else if (x > 550 && (y < 550 && y > 450)) {
    digitalWrite(redPin1, HIGH);
    digitalWrite(blackPin1, LOW);
    digitalWrite(redPin2, LOW);
    digitalWrite(blackPin2, HIGH);
  }
  // Right: 1 counterclockwise, 2 clockwise
  else if (x < 450 && (y < 550 && y > 450)) {
    digitalWrite(redPin1, LOW);
    digitalWrite(blackPin1, HIGH);
    digitalWrite(redPin2, HIGH);
    digitalWrite(blackPin2, LOW);
  }
  else {
    digitalWrite(redPin1, LOW);
    digitalWrite(blackPin1, LOW);
    digitalWrite(redPin2, LOW);
    digitalWrite(blackPin2, LOW);
  }
 
  //print the s with to plot or view
  Serial.print(x);
  Serial.print("\t");
  Serial.println(y);
}
