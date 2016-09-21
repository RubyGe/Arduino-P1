const int LED = 13; // the pin for the LED
const int BUTTON = 7; // the input pin where the pushbutton is connected
int val = 0;  //val will be userd to store the state of the input pin
int pre = 0; //store previous state of the input pin
int state = 0; //number of times the pushbutton has been pushed

void setup() {
  pinMode(LED, OUTPUT); // tell Arduino LED is an output
  pinMode(BUTTON, INPUT); // and BUTTON is an input
}

void loop() {
  val = digitalRead(BUTTON); //read input value and store it
  //check whether the input is HIGH (button pressed)
  if ((val == HIGH) && (pre == LOW)) { //check if there is a status change
    state = 1 - state;
    delay(10); //pushbutton debouncing, needs to be there everytime the pushbotton has been pushed or released
    }
   if ((val == LOW) && (pre == HIGH)) {
    delay (10); 
    }
   if (state == 1) {digitalWrite(LED, HIGH);}
      else {
        digitalWrite(LED,LOW);
        }
    pre = val;
 
}
