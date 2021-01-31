int val = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(D1, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(D1);
  if(val == LOW)
  {
    digitalWrite(LED_BUILTIN, LOW);
    delay(2000);
  }

  digitalWrite(LED_BUILTIN, HIGH); 
  //digitalWrite(LED_BUILTIN, val);
}
