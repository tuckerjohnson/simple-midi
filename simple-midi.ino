// midi variables - duplicate for more (increment variable index, i.e. "int channelMsg1 = XxXX")
int channelMsg0 = 0xB4;
int controllerMsg0 = 0x77;

// Pin variables - duplicate for more (increment variable index)
int switchPin0 = 2;
int toggleState0;
int lastSwitchState0 = 1;
long unsigned int lastSwitch0;


// global variables
int debounceTime = 20;


void setup() {
  // pin setup - duplicate for more (increment variable index, i.e. "switchPin1")
  pinMode(switchPin0, INPUT_PULLUP);
  
  // global setup
  Serial.begin(31250);
}


void loop() {
  // primary loop, monitors pins and sends midi messages - duplicate for more (increment all variables except debounceTime)
  int switchState0 = digitalRead(switchPin0);

  if((millis() - lastPress0) > debounceTime)
  {
    lastPress0 = millis();

    if(switchState0 == 0 && lastSwitchState0 == 1)
    {
      toggleState0 =! toggleState0;
      midiSend(channelMsg0, controllerMsg0, 0x7f);
      lastSwitchState0 = 0;
    }
    
    if(switchState0 == 1 && lastSwitchState0 == 0)
    {
      lastSwitchState0 = 1;
      midiSend(channelMsg0, controllerMsg0, 0x00);
    }
  }
}

// function for sending midi, should not change
void midiSend(int cmd, int pitch, int velocity) {
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
}
