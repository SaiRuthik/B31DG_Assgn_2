const int potPin = 3;
int ERROR_LED = 2;
float potval;
float cal_val =0;
float a1 = 0;
float a2 = 0;
float a3 = 0;
float a4 = 0;
float ana_avg;
float half_max;

void setup() 
{

  Serial.begin(9600);
  pinMode(3, INPUT);
  long int t1 = micros();
  task_3();
  long int t2 = micros();
  Serial.print("Time taken by the task: "); Serial.print(t2-t1); Serial.println(" microseconds");
}

void loop()
{
  
  task_3();

}

void task_3()
{
  
  potval = analogRead(potPin);
  cal_val = (3.3*potval)/4095;
  a1 = a2;
  a2 = a3;
  a3 = a4;
  a4 = cal_val;
  ana_avg = (a1 + a2 + a3 + a4)/4;
  half_max = 3.3/2;
  if (ana_avg > half_max)  {digitalWrite(ERROR_LED, HIGH);}
  else {digitalWrite(ERROR_LED, LOW);}
  
  
}