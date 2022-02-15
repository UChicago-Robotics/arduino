int trigPort = 8, echoPort = 7;
int redLED = 2, yellowLED = 5, greenLED = 4;
int waitTime = 70;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPort, OUTPUT);
  pinMode(echoPort, INPUT);
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPort, LOW);
  delayMicroseconds(20);
  digitalWrite(trigPort, HIGH);
  delayMicroseconds(100);
  digitalWrite(trigPort, LOW);

  int value = pulseIn(echoPort, HIGH);

  Serial.println(value);
  if (value < 500) {
    digitalWrite(greenLED, HIGH);
    delay(waitTime);
  }
  else if (value < 2000) {
    digitalWrite(yellowLED, HIGH);
    delay(waitTime);
  }
  else if (value < 3500) {
    digitalWrite(redLED, HIGH);
    delay(waitTime);
  }
  else {
    digitalWrite(greenLED, HIGH);
    delay(waitTime);
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, HIGH);
    delay(waitTime);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, HIGH);
    delay(waitTime);
    digitalWrite(redLED, LOW);
  }

  //delay(500);
  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, LOW);
}
