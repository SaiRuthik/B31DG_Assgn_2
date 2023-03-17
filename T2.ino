// C++ code
//
int led = 10;
int Htime;              //integer for storing high time
int Ltime;                //integer for storing low time
float Ttime;            // integer for storing total time of a cycle
float frequency;        //storing frequency
int pin = 9;


void setup()
{
  pinMode(10, OUTPUT);
  pinMode(9,INPUT);
  Serial.begin(9600);
  long int t1 = micros();
  task2();
  long int t2 = micros();
  Serial.print("Time taken by the task: "); Serial.print(t2-t1); Serial.println(" microseconds");
}


void task2()
{
  //float period = pulseIn(9, HIGH); 
  //float frequency = 1000000 / (period * 2);
  while (digitalRead(pin) == LOW);
  unsigned long t1 = micros();
  while (digitalRead(pin) == HIGH);
  unsigned long  t2 = micros();
  float period = (t2 - t1)*0.000001;
  float frequency = 1/(period*2);
  Serial.println(frequency);
  //delay(100);
  
}

void loop() // Single time slot function of the Cyclic Executive (repeating)
{
  // uncomment this to find execution time of given tasks 
  
 /* unsigned long bT = micros();
  for (int i=0; i<1000; i++) {*/
    task2();
 // }
  /*unsigned long timeItTook = micros()-bT;
  Serial.print("Duration SerialOutput Job = ");
  Serial.print(timeItTook);
  exit(0);
  task2();*/

}