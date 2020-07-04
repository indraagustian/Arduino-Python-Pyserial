String inString = "";    // string to hold input
void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
}
void loop(){
  while (Serial.available() > 0) {
    int inChar = Serial.read();
    // convert the incoming byte to a char and add it to the string:
    inString += (char)inChar;

    // if you get a newline, print the string, then the string's value:
    if (inChar == '\n') {
      Serial.print(inString);
      if(inString=="on\n"){
        Serial.println(1);
        digitalWrite(LED_BUILTIN, HIGH);
      }
      else if(inString=="off\n"){
        Serial.println(0);
        digitalWrite(LED_BUILTIN, LOW);
      }
      else Serial.print("idle");
      // clear the string for new input:
      inString = "";
    }
  }

}

