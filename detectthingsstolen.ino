
#define trigPin 10 //Echo - pin D10 Arduino 
#define echoPin 9 //Trig - pin D9 Arduino 
#define buzzPin 2 //positive pin of Buzzer - pin D2 Arduino 

void setup()
{
  pinMode(trigPin, OUTPUT); // trigPin as OUTPUT
  pinMode(echoPin, INPUT); // echoPin as an INPUT to get pulse width
  pinMode(buzzPin, OUTPUT); // buzzPin as an OUTPUT to control buzzering
  Serial.begin(9600); //Serial Communication is starting with 9600 of baudrate speed
}

void loop()
{
  long duration;  // variable for the duration of sound wave travel
  int distance;   // variable for the distance measurement
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Set the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  //calculate duration in microsecond
  duration = pulseIn(echoPin, HIGH);
  
  distance = duration * 0.034 / 2;  //Calculate the distance

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  if (distance <= 5 && distance >= 0) {
    // if 0 <= distance <= 5cm, the buzzer doesn't ring 
    digitalWrite(buzzPin, LOW);
  } 
  if (distance > 5){
    // if distance > 5cm, the buzzer ring 
    digitalWrite(buzzPin, HIGH);
  }
  else {     
  }
}
