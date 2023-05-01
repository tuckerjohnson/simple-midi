A very simple switch for sending midi messages over 5-pin din. \
for ATmega328

To implement:
- digital pin 1 connected to DIN pin 5 through 220 ohm resistor
- DIN pin 2 connected to ground
- DIN pin 4 connected to +5V through 220 ohm resistor
- digital pin 2 connected to ground through switch

To add more switches and messages:
- duplicate midi variables, increment variables, and modify midi channel and controller messages

```c++
int channelMsg1 = 0xHEX;
int controllerMsg1 = 0xHEX;
```

- duplicate pin variables, increment variables, and modify `switchPin` value to specify new pin

```c++
int switchPin1 = NEWPIN;
int toggleState1;
int lastSwitchState1 = 1;
long unsigned int lastClose1;
```

- duplicate pin setup and increment variables

```c++
pinMode(switchPin1, INPUT_PULLUP);
```

- duplicate contents of primary loop and increment variables (must be duplicated inside of `void loop()` braces)

```c++
int switchState1 = digitalRead(switchPin1);

if((millis() - lastClose1) > debounceTime)
{
   	lastClose1 = millis();

    	if(switchState1 == 0 && lastSwitchState1 == 1)
    	{
      		toggleState1 =! toggleState1;
     		midiSend(channelMsg1, controllerMsg1, 0x7f);
      		lastSwitchState1 = 0;
    	}
    
    	if(switchState1 == 1 && lastSwitchState1 == 0)
    	{
      		lastSwitchState1 = 1;
      		midiSend(channelMsg1, controllerMsg1, 0x00);
    	}
}
```
