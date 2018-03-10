/*
This arduino script is used to receive commands by Serial communication
and control 4 motors by PWM.
The objective is to control a drone.

The first step is to use LEDs to simulate motor

Front right motor is red LED
Front left motor is green LED
Back left motor is blue LED
Back right motor is yellow LED
*/

// Motors parameters
#define BR 1
#define FR 2
#define BL 3
#define FL 4

byte motorBR = 8;
byte motorFR = 9;
byte motorBL = 10;
byte motorFL = 11;

// Communication parameters
String inputString = "";
char inChar = '';
boolean commandReceived = false;
String selectedMotor = "";
int motorSpeed = 100;


void setup()
{
  pinMode(motorBR, OUTPUT);
  pinMode(motorFR, OUTPUT);
  pinMode(motorBR, OUTPUT);
  pinMode(motorFR, OUTPUT);
  
  analogWrite(motorBR, motorSpeed);
  analogWrite(motorFR, motorSpeed);
  analogWrite(motorBR, motorSpeed);
  analogWrite(motorFR, motorSpeed);
  
  Serial.begin(115200);
}

void loop()
{
  if(commandReceived)
  {
    Serial.print("Command received:\n");
    Serial.print("Selected motor:");
    Serial.println(selectedMotor);
    Serial.print("Speed = ");
    Serial.println(motorSpeed);
    
    switch (selectedMotor)
    {
      case BR:
        analogWrite(motorBR, motorSpeed);
      case FR:
        analogWrite(motorFR, motorSpeed);
      case BL:
        analogWrite(motorBL, motorSpeed);
      case FL:
        analogWrite(motorFL, motorSpeed);
    }
    commandReceived = false;
  }
}

void serialEvent()
{
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    
    if (inChar == ':')
    {
      if (inputString == "BR")
      {
         selectedMotor = BR;
      }
      else if (inputString == "FR")
      {
         selectedMotor = FR;
      }
      else if (inputString == "BL")
      {
         selectedMotor = BL;
      }
      else if (inputString == "FL")
      {
         selectedMotor = FL;
      }
     
      inputString = "";
    }
    else if (inChar == '\n')
    {
      motorSpeed = inputString.toInt();
      inputString = "";
      commandReceived = true;
    }
    else
    {
      inputString += inChar;
    } 
    
  }
}
