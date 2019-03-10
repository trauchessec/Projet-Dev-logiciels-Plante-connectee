const byte LedPIN = 3; // PIN of power (output)
const byte PotentiometerPIN = A1; //Read the value from potentiometer (input)
const byte ButtonPIN = 9; //Read if the button is pushed or not (input)

const int PotentiometerMaxValue = 1000;
const int LightStrengh = 0;
const char KeyLightOff = 'o';
const char KeyLightOn = 'O';

bool lightBlinking = false;
bool lightState = true;

void setup() 
{
  Serial.begin(9600); //Open the serial monitor.
  
  pinMode(LedPIN, OUTPUT);
  pinMode(ButtonPIN, INPUT);
  pinMode(PontentiometerPIN, INPUT);
}

void loop() 
{
 
  Serial.println(analogRead(PontentiometerPIN)); //Read the potentiometer value.
  
  int LightStrengh = (analogRead(PontentiometerPIN) / PotentiometerMaxValue) * 255; //Set the light strengh from the potentiometer value.

  //Change the lightState : 
 
 if(char(Serial.read()) == KeyLightOn)
  {
    bool LightState = true;
  }
  
 if(char(Serial.read()) == KeyLightOff)
  {
    bool LightState = false;
  }

  // Light off mode :
  
  if(lightState = false)
  {
    digitalWrite(LedPIN, 0);
    return;
  }

  // Normal mode with button ?

  LightBlinkink = false; //Reset the blinking to the setup form
  
  if(digitalRead(ButtonPIN))
  {
    lightBlinking = true; // Activate the blinking mode if the button is pushed
  }

  //Normal mode :
  
  digitalWrite(LedPIN, LightStrengh); // Turn on the light at the potentiometer value

  //Blinking mode :

  if(lightBlinking = true)
  {
    delay(1000); //Light on for 1 sec (1000 ms)
    digitalWrite(LedPIN, 0);
    delay(1000); //Light off for 1 sec 
  }
}
