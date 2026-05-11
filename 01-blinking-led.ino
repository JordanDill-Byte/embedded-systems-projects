//arduinos don't use iostream they it has it's own built in functionality

void setup(){
    pinMode(13, OUTPUT); //Setting pin 13 as the output, clear easy pin for this project

}


void loop(){
    digitalWrite(13, HIGH); //Sending out a high signal to turn the LED on
    delay(1000); //holding 1 second before changing state
    digitalWrite(13, LOW);//Sending out a low signal to turn the LED off
    delay(1000);//holding for 1 second before changing state

}