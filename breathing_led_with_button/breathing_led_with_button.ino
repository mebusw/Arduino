  
const int ledPin = 9;           // the pin that the LED is attached to
const int buttonPin = 2;     // the number of the pushbutton pin
const int A_IN = A0;

int brightness = 0;    // how bright the LED is
int buttonState = 0;         // variable for reading the pushbutton status

// the setup routine runs once when you press reset:
void setup()  { 
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);      
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT); 
} 

// the loop routine runs over and over again forever:
void loop()  { 
    // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  
  int sensorValue = analogRead(A_IN);
  int gapValue = map(sensorValue, 0, 1024, 1, 40);
  
  // check if the pushbutton is pressed.
  if (buttonState == HIGH) {     
    for (int fadeValue = 0; fadeValue <= 255; fadeValue += 5) {
      analogWrite(ledPin, fadeValue);
      delay(gapValue);
    }
    
      
    for (int fadeValue = 255; fadeValue >= 0; fadeValue -= 5) {
      analogWrite(ledPin, fadeValue);
      delay(gapValue);
    } 
  } 
  else {
    // nothing 
  }
  


}

