//Blinking LED

const int LED = 13; //LED connected to digital pin 13

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH); //turns the LED on
  delay(1000); //waits for a sec
  digitalWrite(LED, LOW); //turns the LED off
  delay(1000); //waits for a sec

}
