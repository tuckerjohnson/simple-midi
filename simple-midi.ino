//midi defs
int channelMsg = 0xB4;
int controllerMsg = 0x77;

//Button-Pin 
int buttonPin = 2;

// gLv
int toggleState;
int lastButtonState = 1;
long unsigned int lastPress;
int debounceTime = 20;


void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(31250);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if((millis() - lastPress) > debounceTime)
  {
    lastPress = millis();

    if(buttonState == 0 && lastButtonState == 1)
    {
      toggleState =! toggleState;
      noteOn(channelMsg, controllerMsg, 0x7f);
      lastButtonState = 0;
    }
    if(buttonState == 1 && lastButtonState == 0)
    {
      lastButtonState = 1;
      noteOn(channelMsg, controllerMsg, 0x7f);
    }
  }
}

void noteOn(int cmd, int pitch, int velocity) {
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
}