int val = 0;

void setup() {
  //Set up pins
  pinMode(D1, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  //Detect whether pump is pushed (HIGH is up, LOW is down)
  val = digitalRead(D1);
  //Wait a while before checking value again so pump can be pushed a few times without triggering again
  if(val == LOW)
  {
    digitalWrite(LED_BUILTIN, LOW);
    delay(2000);
  }
  digitalWrite(LED_BUILTIN, HIGH);
}
