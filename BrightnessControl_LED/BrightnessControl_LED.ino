const int LED = 3;    //the pin for the LED
const int BUTTON = 7; // the pin for the pushbutton
int val = 0; // store the state of the input pin

int pre = 0; //store the previous value of val
int state = 0; //0 = LED off while 1 = LED on

int brightness = 128; // stores the brightness value
unsigned long startTime = 0; // when did we begin pressing?

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);

}

void loop() {
  val = digitalRead(BUTTON); //read input value and store it
  
  //check if button has been pushed
  if ((val == HIGH) && (pre == LOW)) {
    state = 1 - state;
    startTime = millis(); //millis() is the Arduino clock. it returns how many milliseconds have passed since the board has been reset.
    // it remembers when the button was last pressed
    delay(10);
    }
    
    //check whether the button has been held down
   if ((val == HIGH) && (pre == HIGH)) {
    
    //If the button is held for more than 500ms
    if (state == 1 && (millis() - startTime) > 500) {
        brightness++;// increment brightness by 1
        delay(10); //delay to aviod brightness going up too fast

        if (brightness > 255) {
          brightness = 0; //if we go over 255, let's go back to 0
          }
      }
    }

    pre = val;

    if (state == 1) {
      analogWrite(LED, brightness); // turn LED ON at the current brightness level
      } else {
        analogWrite(LED, 0); // turn LED OFF
        }
}
