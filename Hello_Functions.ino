/*Hello Functions
/*
* HC-SR04 example sketch
*
* https://create.arduino.cc/projecthub/Isaac100/getting-started-with-the-hc-sr04-ultrasonic-sensor-036380
*
* by Isaac100
*/
const int trigPin = 9;
const int echoPin = 11;
int cm;
float duration, distance;
void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  cm = getDistance();
  Serial.print("Distance: ");
  Serial.println(cm);
  delay(100);
}

int getDistance()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration *.0343) /2;
  return distance;
}

/*
if(getDistance() < 5)
moveServo(1);
else if(distance < 10)
moveServo(2);
else
stopServo();
*/