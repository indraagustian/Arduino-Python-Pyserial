char serialData;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  if(Serial.available()>0){
    serialData=Serial.read();
    Serial.print(serialData);

    if(serialData=='1')digitalWrite(LED_BUILTIN, HIGH);
    else if(serialData=='0')digitalWrite(LED_BUILTIN, LOW);
  }
}
