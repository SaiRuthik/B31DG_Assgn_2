// C++ code
//
int led = 10;
void setup()
{
  pinMode(10, OUTPUT);
  Serial.begin(9600);
  long int t1 = micros();
  task1();
  long int t2 = micros();
  Serial.print("Time taken by the task: "); Serial.print(t2-t1); Serial.println(" microseconds");
}

void loop()
{ 
  task1();
}

void task1()
{
  

  digitalWrite(led, HIGH);
  delayMicroseconds(200);
  digitalWrite(led, LOW);
  delayMicroseconds(50);
  digitalWrite(led, HIGH);
  delayMicroseconds(30);  
  digitalWrite(led, LOW);
  
}