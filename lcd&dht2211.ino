
// All the basic libraries required
#include "Arduino.h"
#include "DHT.h"
#include "LiquidCrystal.h"


// Pin Definitions
#define DHT_PIN_DATA	2
#define LCD_PIN_RS	8
#define LCD_PIN_E	7
#define LCD_PIN_DB4	3
#define LCD_PIN_DB5	4
#define LCD_PIN_DB6	5
#define LCD_PIN_DB7	6





//Initialization
DHT dht(DHT_PIN_DATA);
LiquidCrystal lcd(LCD_PIN_RS,LCD_PIN_E,LCD_PIN_DB4,LCD_PIN_DB5,LCD_PIN_DB6,LCD_PIN_DB7);


// Setup 
void setup() 
{
    // Setup Serial which is useful for debugging
    // Use the Serial Monitor to view printed messages
    Serial.begin(9600);
    while (!Serial) ; // wait for serial port to connect. Needed for native USB
    Serial.println("start");
    
    dht.begin();
    // set up the LCD's number of columns and rows
    lcd.begin(16, 2);
    menuOption = menu();
    
}

// Main logic 
{
    
    
    if(menuOption == '1') {
    // DHT22/11 Humidity and Temperature Sensor - Test Code
    // Reading humidity in %
    float dhtHumidity = dht.readHumidity();
    // Read temperature in Celsius, for Fahrenheit use .readTempF()
    float dhtTempC = dht.readTempC();
    Serial.print(F("Humidity: ")); Serial.print(dhtHumidity); Serial.print(F(" [%]\t"));
    Serial.print(F("Temp: ")); Serial.print(dhtTempC); Serial.println(F(" [C]"));

    }
    else if(menuOption == '2') {
    // LCD 16x2 - Test Code
    // Print a message to the LCD.
    lcd.setCursor(0, 0);
    lcd.print("Mauser 18 !");
    // Turn off the display:
    lcd.noDisplay();
    delay(500);
    // Turn on the display:
    lcd.display();
    delay(500);
    }
    
    if (millis() - time0 > timeout)
    {
        menuOption = menu();
    }
    
}
