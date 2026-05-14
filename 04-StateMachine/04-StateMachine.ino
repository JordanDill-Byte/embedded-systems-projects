
enum TrafficLights{//Enum to specify the states
    GREEN,
    YELLOW,
    RED
};
TrafficLights currentState = GREEN;//initializing the currentState to green when the program starts
void setup(){//setting up the output pins to connect to the LED's
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
}


void loop(){
    switch(currentState){ //Switch case that sets the correct outputs for each of the states then transitions to the correct order of GREEN -> YELLOW -> RED back to GREEN 
        case RED:
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, HIGH);
        delay(4000);
        currentState = GREEN;//have to ensure that we move on to the next state inside the switch case and not just use a counter, code is much cleaner this way
        break;//break statements are used sowe don't transistion to the next case automatically

        case YELLOW:
        digitalWrite(3, LOW);
        digitalWrite(4, HIGH);
        digitalWrite(5, LOW);
        delay(3000);
        currentState = RED;
        break;

        case GREEN:
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        delay(4000);
        currentState = YELLOW;
        break;

    }
    
}