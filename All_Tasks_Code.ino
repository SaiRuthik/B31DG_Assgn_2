#include <B31DGMonitor.h> // Cyclic Executive Monitor Library provided by Prof. Mauro 

#include<Ticker.h>        // Ticker Library is included 

B31DGCyclicExecutiveMonitor monitor; // Creating an instance of Cyclic Executive Monitor
int t1_out = 2;       // t1_out is the LED for Task 1 and is connected to pin 2
int f1_in = 10;       // f1_in pin is used to read frequency for task 2 from 10
float f1;             // frequency of task 2 is here
int f1_1;             // Used in task 5 to scale the frq read in Task 2
float f1_read;        // Frq time difference of Task 2 is here
unsigned long t1;     // time stamp used to measure time in Task 2
unsigned long t2;     // time stamp used to measure time in Task 2
int f2_in = 11;       // f2_in pin is used to read frequency for task 3 from 11
float f2;             // frequency of task 3 is here
int f2_1;             // Used in task 5 to scale the frq read in Task 3
float f2_read;        // Frq time difference of Task 3 is here
unsigned long t3;     // time stamp used to measure time in Task 3
unsigned long t4;     // time stamp used to measure time in Task 3
int potPin = 4;       // The wiper pin of potentiometer is connected to Pin 4, named as potPin
int ERROR_LED = 19;   // The ERROR LED of Task 4 is connected to pin 19
float potval;         // The analog data read from potentiometer is stored here
float cal_val =0;     // Used to scale up the voltage from 0v to 3.3v
float a1 = 0;         // 4th recent value read from potentiometer
float a2 = 0;         // 2nd recent value read from potentiometer
float a3 = 0;         // 3rd recent value read from potentiometer
float a4 = 0;         // Most recent value read from potentiometer
float ana_avg;        // Average of recent 4 potentiometer values is stored here
float half_max;       // Half of the maximum input voltage value is stored
unsigned long frameTime = 0;  
unsigned long frameCounter = 0;// Used as a counter in the schedule to shift to next frame
Ticker ticker;        // Creating an instance of a ticker



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  // Setting the baud rate of the serial monitor to 9600
  while(!Serial);
  Serial.println("Ready");

  pinMode(t1_out, OUTPUT); // Initializing t1_out as an OUTPUT PIN
  pinMode(f1_in, INPUT);   // Initializing f1_in as an INPUT PIN
  pinMode(f2_in, INPUT);   // Initializing f2_in as an INPUT PIN
  pinMode(potPin, INPUT);  // Initializing potPin as an INPUT PIN
  pinMode(ERROR_LED, OUTPUT);// Initializing ERROR_LED as an OUTPUT PIN
  monitor.startMonitoring(); // Monitor will start monitoring to check if tasks are crossing deadlines or not
  cycexesch();                   // case 0 of schedule is executed as ticker will start from case 1
  ticker.attach_ms(4, cycexesch); // attaching the ticker instance to the cycexesch which will run once every 4ms


}

void loop() {
  // put your main code here, to run repeatedly:
  //cycexesch();

}


void cycexesch() // Cyclic Executive Schedule function is created with 50 frames which is a time frame of 200ms
{
  unsigned int move = frameCounter % 50; // move is used as a case shifter in the switch case
  //                                        while vrameCounter is used as counter which executes 50 frames and then restarts again 
  switch (move)
  {
    case 0:  task1();            task3();              break;
    case 1:  task1();  task2();                        break;
    case 2:  task1();            task3();              break;
    case 3:  task1();                      task4();    break;
    case 4:  task1();            task3();              break;
    case 5:  task1();  task2();                        break;
    case 6:  task1();            task3();              break;
    case 7:  task1();                                  break;
    case 8:  task1();            task3();              break;
    case 9:  task1();                      task4();    break;
    case 10: task1();            task3();              break;
    case 11: task1();  task2();                        break;
    case 12: task1();            task3();              break;
    case 13: task1();                      task4();    break;
    case 14: task1();            task3();              break;
    case 15: task1();  task2();                        break;
    case 16: task1();            task3();              break;
    case 17: task1();                                  break;
    case 18: task1();            task3();              break;
    case 19: task1();                      task4();    break;
    case 20: task1();            task3();              break;
    case 21: task1();  task2();                        break;
    case 22: task1();            task3();              break;
    case 23: task1();                      task4();  task5();    break;
    case 24: task1();            task3();              break;
    case 25: task1();  task2();                        break;
    case 26: task1();            task3();              break;
    case 27: task1();                                  break;
    case 28: task1();            task3();              break;
    case 29: task1();                      task4();    break;
    case 30: task1();            task3();              break;
    case 31: task1();  task2();                        break;
    case 32: task1();            task3();              break;
    case 33: task1();                      task4();    break;
    case 34: task1();            task3();              break;
    case 35: task1();  task2();                        break;
    case 36: task1();            task3();              break;
    case 37: task1();                                  break;
    case 38: task1();            task3();              break;
    case 39: task1();                      task4();    break;
    case 40: task1();            task3();              break;
    case 41: task1();  task2();                        break;
    case 42: task1();            task3();              break;
    case 43: task1();                      task4();    break;
    case 44: task1();            task3();              break;
    case 45: task1();  task2();                        break;
    case 46: task1();            task3();              break;
    case 47: task1();                                  break;
    case 48: task1();            task3();              break;
    case 49: task1();                      task4();  task5();   ;  break;
  }
  frameCounter++;                                 // frame counter is incremented as to move to next frame

}


void task1()       // Worst case implementation of Task 1 is 293us ~ 0.3ms
{                  // In Task 1 we generate a digital signal and pulse it accordingly
  monitor.jobStarted(1); // Monitor job started to monitor time taken by task 1 
  digitalWrite(t1_out, HIGH);
  delayMicroseconds(200);
  digitalWrite(t1_out, LOW);
  delayMicroseconds(50);
  digitalWrite(t1_out, HIGH);
  delayMicroseconds(30);  
  digitalWrite(t1_out, LOW);
  monitor.jobEnded(1); // Monitor job ended for Task 1
}


void task2()        // Worst case implementation time of Task 2 is 3054us ~ 3.1ms
{                   // In Task 2 we read a square wave signal with 50% Duty Cycle of frq ranging from 333Hz to 1000Hz
  monitor.jobStarted(2); // Monitor job started to monitor time taken by task 2
  while (digitalRead(f1_in) == LOW);
  t1 = micros();
  while (digitalRead(f1_in) == HIGH);
  t2 = micros();
  f1_read = (t2 - t1)*0.000001; // HIGH time of the signal is calculated and then converted to microseconds
  f1 = 1/(f1_read*2);           // the above time is converted to frequency by formula Frq = 1/time
  //delay(3);
  monitor.jobEnded(2);  // Monitor job ended for Task 2
}

void task3()       // Worst case implementation time of Task 3 is 2014us ~ 2.1ms
{                  // In Task 3 we read a square wave signal with 50% Duty Cycle of frq ranging from 500Hz to 1000Hz
  monitor.jobStarted(3);  // Monitor job started to monitor time taken by task 3
  while (digitalRead(f2_in) == LOW);
  t3 = micros();
  while (digitalRead(f2_in) == HIGH);
  t4 = micros();
  f2_read = (t4 - t3)*0.000001;
  f2 = 1/(f2_read*2);
  //delay(2);
  monitor.jobEnded(3);// Monitor job ended for Task 3
}


void task4()     // Worst case implementation time of Task 4 is 246us ~ 0.3ms
{
  monitor.jobStarted(4); // Monitor job started to monitor time taken by task 4
  potval = analogRead(potPin); // Analog Data is read from potPin and stored in potval
  cal_val = (3.3*potval)/4095; // analog data is scaled between 0v and 3.3v
  a1 = a2;                     // shifting the values to remove the older values
  a2 = a3;                     // and maintaining only recent 4 readings of potentiometer
  a3 = a4;
  a4 = cal_val;
  ana_avg = (a1 + a2 + a3 + a4)/4; // averaging recent 4 values of potentiometer
  half_max = 3.3/2;                // calculating half of maximum value
  if (ana_avg > half_max)  {digitalWrite(ERROR_LED, HIGH);} // comparing ana_avg and half_max and 
  else {digitalWrite(ERROR_LED, LOW);}                      // generating the required Digital Pulse
  monitor.jobEnded(4);  // Monitor job ended for Task 4
}


void task5()    // Worst case implementation time of Task 5 is 167us ~ 0.3ms
{
  monitor.jobStarted(5);  // Monitor job started to monitor time taken by task 5
  f1_1 = 0;
  f2_1 = 0;
  f1_1 = ((f1 - 333)*99)/(1000 - 333); // As frq range of task 2 was from 333Hz to 1000Hz, scaled it from 0 to 99 using this  
  f2_1 = ((f2 - 500)*99)/(1000 - 500); // As frq range of task 3 was from 500Hz to 1000Hz, scaled it from 0 to 99 using this 

  if(f1_1<=0){f1_1 = 0;}               // If value scales value goes negative, it is assigned 0
  else if(f1_1 > 99){f1_1 = 99;}       // If scaled value goes more than 99, it is assigned 99
  else{f1_1 = f1_1;}

  if(f2_1<=0){f2_1 = 0;}
  else if(f2_1 > 99){f2_1 = 99;}
  else{f2_1 = f2_1;}

  Serial.printf("%d, %d\n",f1_1, f2_1); // Printing the scaled values on the serial monitor in the desired format
  monitor.jobEnded(5);  // Monitor job ended for Task 1
}


