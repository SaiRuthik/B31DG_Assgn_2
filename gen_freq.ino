// C++ code
//
int led = 10;
int outputPin = 6;
float perio;
float frequenc;

void setup()
{
  pinMode(10, OUTPUT);
  pinMode(8,INPUT);
  pinMode(outputPin, OUTPUT); 
  analogWrite(outputPin, 127);
  Serial.begin(9600);
  long int t1 = micros();
  task2();
  long int t2 = micros();
  Serial.print("Time taken by the task: "); Serial.print(t2-t1); Serial.println(" microseconds");
}

void loop()
{
  gen_freq();
  task2();
}

void gen_freq()
{
  int frequency = 400;
  int period = 1000000 / frequency;
  int pulseWidth = period / 2;
  analogWrite(outputPin, 127);
  delayMicroseconds(pulseWidth);
  analogWrite(outputPin, 0);
  delayMicroseconds(pulseWidth);
 
}
  

void task2()
{
  
  perio = pulseIn(8, HIGH); 
  frequenc = 1000000 / (perio * 2);  
  Serial.print("frequency is "); Serial.println(frequenc);
  
}