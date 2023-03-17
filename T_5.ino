float f1 = 550;
float f2 = 650;
int f1_1;
int f2_1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  long int t1 = micros();
  task_5();
  long int t2 = micros();
  Serial.print("Time taken by the task: "); Serial.print(t2-t1); Serial.println(" microseconds");

}

void loop() {
  // put your main code here, to run repeatedly:
  task_5();

}

void task_5()
{
  f1_1 = ((f1 - 333)*99)/(1000 - 333);
  f2_1 = ((f2 - 500)*99)/(1000 - 500);
  Serial.printf("%d, %d\n",f1_1, f2_1);
}