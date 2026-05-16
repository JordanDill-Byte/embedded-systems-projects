const uint8_t interruptPin = 2;//starting to use cosntant variables so that we don't have floating numbers
const uint8_t ledPin = 7;
int lastValue = 0; //volatile flags dissalow the compiler from optomizing the variables as they can change outside of program flow
volatile int interruptCounter = 0;//volatile forces the program to read the variable directly from memory every time it's called so values aren't lost
volatile unsigned long lastDebounceTime = 0;//volatile variable to keep track of debouncing
volatile unsigned long ledOffTime = 0;//counter for knowing when to turn the LED back on
const unsigned long debounceDelay = 50;//constant 50 milliseconds to account for debouncing
const unsigned long ledOnDelay = 500;//constant half second before we turn the LED back on



void increment(){
    unsigned long currentTime = millis();//local variable to hold current time in milliseconds, acts as a millisecond counter, this resets every time we interrupt
    if(currentTime - lastDebounceTime > debounceDelay){//if we've waited longer than 50 milliseconds then we're good to continue and interrupt again, this is to handle debounce
        interruptCounter = interruptCounter + 1;
        lastDebounceTime = currentTime;//setting debounce time to current time in milliseconds
        ledOffTime = currentTime;//setting ledOffTime to current time in milliseconds

    }
}

void setup(){
    pinMode(ledPin, OUTPUT);//pin 7 is output for the led
    pinMode(interruptPin, INPUT_PULLUP);//pin 2 is input for the button setting it up for a falling edge with internal resistor from board
    attachInterrupt(digitalPinToInterrupt(interruptPin), increment, FALLING); //attaching the interrupt to the increment function with a rising edge
    Serial.begin(9600);
    digitalWrite(ledPin, HIGH);


}


void loop(){
    Serial.println("Button state ");
    Serial.println(digitalRead(interruptPin));
    int localCounter = interruptCounter; // seting a local variable to handle race conditions
    long localLedCounter = ledOffTime;
    if(localCounter != lastValue  && localCounter != 0){
        Serial.println("Interrupt triggered");
        lastValue = localCounter;//decided to update the lastValue inside the if statement instead of outside of it to save resources (not that it matters at this size)
        digitalWrite(ledPin, LOW);

        
    }

    if(millis() - localLedCounter > ledOnDelay){//setting the LED back high, we're using non-blocking timing for a delay on restarting the LED
            digitalWrite(ledPin, HIGH);
    }
    

}