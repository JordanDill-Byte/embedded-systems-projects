#include <Wire.h>//Built in I2C arduino library
#include <Adafruit_BMP085.h>//Library that includes the MBP180
#include <DHT.h> //library that includes the DHT22

DHT dht(7, DHT22); //Declaring the DHT22 and setting up which pin is used, defaults the count to 6
Adafruit_BMP085 bmp180; //The declaration for the bmp does not accept parameters, all parameteres are handled in setup

float temperatureDHT = 0; //declaring the temperature for DHT so as to not run it in loop
float humidityDHT = 0; //declaring humidity for DHT so as to not run it in loop
float temperatureBMP180 = 0; //declaring temperature variable for BMP180
float pressureBMP180 = 0;//declaring pressure variable for BMP180


void setup(){
    Serial.begin(9600);//setting the baud rate for UART and the DHT22
    dht.begin(); //default value of usec=55

    if (!bmp180.begin()){//activating the bmp180, also error handling if it doesn't connect properly
        Serial.println("could not activate bmp180 please reset.");
        while(true){};
    }
    

    

}


void loop(){

temperatureDHT = dht.readTemperature();//updating temperature with the device reading
humidityDHT = dht.readHumidity();//updating humidity with device reading
temperatureBMP180 = bmp180.readTemperature();//updating temperature reading for BMP180
pressureBMP180 = bmp180.readPressure();//updating pressure variable for BMP180 reading

if(isnan(temperatureDHT)){ //this if else statement handles if the reading fails and if not outputs the DHT temperature reading
    Serial.println("DHT22 Temperature reading failed");
}
    else{
        Serial.print("DHT22 temperature reading :" );
        Serial.print(temperatureDHT);
        Serial.println(" C");
    }

if(isnan(humidityDHT)){//this if else statement handles if the reading fails and if not outputs the DHT humidity reading
    Serial.println("DHT22 Humidity reading failed");

}
    else {
        Serial.print("DHT22 humidity reading ");
        Serial.print(humidityDHT);
        Serial.println("%");
    }

Serial.print("BMP180 temperature reading ");//this 3 line serial print handles the bmp180 temperature output
Serial.print(temperatureBMP180);
Serial.println(" C");

Serial.print("BMP180 pressure reading ");//this 3 line serial print handles the bmp180 pressure output
Serial.print(pressureBMP180);
Serial.println(" Pa");
delay(2000); //delay because the DHT22 has a minimum scale of 2 seconds to read again

}