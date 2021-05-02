#include<Servo.h>
Servo motor;
char Incoming_value = 0;

// drive motor both of the left connections
int enl1 = 1;
int in1 = 2;
int in2 = 3;

//right motor 1 
int enr1 = 7;
int in5 = 8;
int in6 = 9;

//  mop motor connections
int enm = 13;
int in9 = 14;
int in10 = 15;

   
void setup() 
{
  Serial.begin(9600);         
  pinMode(13, OUTPUT);

  // Set all the motor control pins to outputs
  motor.attach(2);
  motor.write(180);

  pinMode(enl1, OUTPUT);
  pinMode(enr1, OUTPUT);
  pinMode(enm, OUTPUT);
  
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in5, OUTPUT);
  pinMode(in6, OUTPUT);
  pinMode(in9, OUTPUT);
  pinMode(in10, OUTPUT);
  

  
  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in5, LOW);
  digitalWrite(in6, LOW);
  digitalWrite(in9, LOW);
  digitalWrite(in10, LOW);    
}

void loop()
{
  if(Serial.available() > 0)  
  {
    Incoming_value = Serial.read();      
    
    Serial.print(Incoming_value);        
    Serial.print("\n");        
    
    if(Incoming_value == "Left")
    {             
      // Bot will move toward Left  
      analogWrite(enl1, 255);
      analogWrite(enr1, 0);
      
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in5, LOW);
      digitalWrite(in6, LOW);
      }
     
    else if(Incoming_value == "Right")
    {
     // Bot will move toward Right  
     analogWrite(enl1, 0);
     analogWrite(enr1, 255);
     
     digitalWrite(in1, LOW);
     digitalWrite(in2, LOW);
     digitalWrite(in5, HIGH);
     digitalWrite(in6, LOW);
     }
    
    else if(Incoming_value == "Go_ON")
    {
     //Bot will move forward
     analogWrite(enl1, 255);
     analogWrite(enr1, 255);
     
     digitalWrite(in1, HIGH);
     digitalWrite(in2, LOW);
     digitalWrite(in5, HIGH);
     digitalWrite(in6, LOW);
     }
     
    else if(Incoming_value == "Reverse")
    {
      //Bot will move in reverse direction
      analogWrite(enl1, 255);
      analogWrite(enr1, 255);
      
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in5, LOW);
      digitalWrite(in6, HIGH);
      }
      
    else if(Incoming_value == "Emergency_Stop")
    {
      //Bot will stop immediatly
      analogWrite(enl1, 255);
      analogWrite(enr1, 255);
      
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in5, LOW);
      digitalWrite(in6, HIGH);
      }
      
    
    else if(Incoming_value == "Mop_Down_Clean_Area")
    {
     for(int i=0;i<180;i++)
     {
      motor.write(i);
      }
     analogWrite(enm, 255);
     
    digitalWrite(in9, HIGH);
    digitalWrite(in10, LOW);
    }
      
   else (Incoming_value == "Mop_UP");
   {
    for(int i=180;i>0;i--)
    {
      motor.write(i);
      } 
    analogWrite(enm, 0);
    
    digitalWrite(in9, LOW);
    digitalWrite(in10, LOW);
    }
     
  }                            
} 
