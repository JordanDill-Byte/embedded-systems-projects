
int increment = 0; //Global variable to increment each UART transmission

void setup(){
    Serial.begin(9600); //setting the baud rate
    pinMode(13, OUTPUT); //setting pin 13 to output

}

void loop(){
    Serial.print("Jordan Transmission: ");
    Serial.println(increment);//seperating out the print statements because I can't directly concatenate in arduino
    increment = increment + 1; //increasing the increment count for each completed loop, decided to place it after the print statement so that we start at 0
    delay(500); //setting a half second delay so we don't instantly shoot up in increments to keep it readable

}
