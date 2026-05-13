#include <Wire.h>//Built in I2C arduino library
#include <Adafruit_BMP085.h>//Library that includes the MBP180
#include <DHT.h> //library that includes the DHT22

DHT dht(7, DHT22); //Declaring the DHT22 and setting up which pin is used, defaults the count to 6
float temperatureDHT = 0; //declaring the temperature for DHT so as to not run it in loop
float humidityDHT = 0; //declaring humidity for DHT so as to not run it in loop

void setup(){
    Serial.begin(9600);//setting the baud rate for UART and the DHT22
    dht.begin(); //default value of usec=55

    

}


void loop(){

temperatureDHT = dht.readTemperature();//updating temperature with the device reading
humidityDHT = dht.readHumidity();//updating humidity with device reading
if(isnan(temperatureDHT)){ //ensuring that we get no false outputs and handle the error for both humidity and temperature
    Serial.println("Temperature reading failed");
}
    else{
        Serial.print("The temperature is :" );
        Serial.println(temperatureDHT);
    }

if(isnan(humidityDHT)){
    Serial.println("Humidity reading failed");

}
    else {
        Serial.print("The humidty is at ");
        Serial.print(humidityDHT);
        Serial.println("%");
    }
delay(2000); //delay because the DHT22 has a minimum scale of 2 seconds to read again

}