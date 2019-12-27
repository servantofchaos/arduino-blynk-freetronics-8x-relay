/*  Description:
    Control freetronics relay via Blynk

    Status:
    Working on Wemos D1
*/

//---------------------------------------------------------------------------------------------------------------
//                                                  LIBRARIES
//---------------------------------------------------------------------------------------------------------------
#include <Adafruit_GFX.h>       //grafix library for OLED
#include "SSD1306Wire.h"        // legacy: #include "SSD1306.h

#include "Wire.h" // for I2C bus
#define I2C_ADDR 0x20 // 0x20 is the address with all jumpers removed

// Setup WiFi
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <ArduinoOTA.h>
#include <ESP8266mDNS.h>
#include <WiFiClient.h>

#define BLYNK_PRINT Serial        // blynk setup

//---------------------------------------------------------------------------------------------------------------
//                                                   DEFINITIONS
//---------------------------------------------------------------------------------------------------------------
String myStr;                                 // String for first line
String myStr2;                                // String for second line
String myHeader;                              // String for header
String r1 = "[-]"; // String for relay1 status
String r2 = "[-]"; // String for relay2 status
String r3 = "[-]"; // String for relay3 status
String r4 = "[-]"; // String for relay4 status
String r5 = "[-]"; // String for relay5 status
String r6 = "[-]"; // String for relay6 status
String r7 = "[-]"; // String for relay7 status
String r8 = "[-]"; // String for relay8 status

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "ZvGvKHfmEWw2mDBg4SobTXm5Q4AOT5W6";

// Setup WiFi info
char ssid[] = "Telstra69EB6F";
char pass[] = "ragd48gdeat6";

// Define relay values
int relay1 = 1;
int relay2 = 2;
int relay3 = 4;
int relay4 = 8;
int relay5 = 16;
int relay6 = 32;
int relay7 = 64;
int relay8 = 128;

// Define latch value
int i;
int latchValue;
int pinValue1;
int pinValue2;
int pinValue3;
int pinValue4;
int pinValue5;
int pinValue6;
int pinValue7;
int pinValue8;
int pinValue9;

BLYNK_CONNECTED() {
  // Request the latest state from the server
  Blynk.syncVirtual(V1);
  Blynk.syncVirtual(V2);
  Blynk.syncVirtual(V3);
  Blynk.syncVirtual(V4);
  Blynk.syncVirtual(V5);
  Blynk.syncVirtual(V6);
  Blynk.syncVirtual(V7);
  Blynk.syncVirtual(V8);
  Blynk.syncVirtual(V9);
}

BLYNK_WRITE(V1)
{
  int pinValue1 = param.asInt();
  if (pinValue1 == 1)
  {
    latchValue = latchValue + relay1;
    myHeader = "= RELAYS =";
    r1 = "[1]";
  } else {
    if (pinValue1 == 0) {
      latchValue = latchValue - relay1;
      myHeader = "= RELAYS =";
      r1 = "[-]";
    }
  }
  pushToDisplay (myHeader, r1, r2, r3, r4, r5, r6, r7, r8);
}

BLYNK_WRITE(V2)
{
  int pinValue2 = param.asInt();
  if (pinValue2 == 1)
  {
    latchValue = latchValue + relay2;
    myHeader = "= RELAYS =";
    r2 = "[2]";
  } else {
    if (pinValue2 == 0) {
      latchValue = latchValue - relay2;
      myHeader = "= RELAYS =";
      r2 = "[-]";
    }
  }
  pushToDisplay (myHeader, r1, r2, r3, r4, r5, r6, r7, r8);
}

BLYNK_WRITE(V3)
{
  int pinValue3 = param.asInt();
  if (pinValue3 == 1)
  {
    latchValue = latchValue + relay3;
    myHeader = "= RELAYS =";
    r3 = "[3]";
  } else {
    if (pinValue3 == 0) {
      latchValue = latchValue - relay3;
      myHeader = "= RELAYS =";
      r3 = "[-]";
    }
  }
  pushToDisplay (myHeader, r1, r2, r3, r4, r5, r6, r7, r8);
}

BLYNK_WRITE(V4)
{
  int pinValue4 = param.asInt();
  if (pinValue4 == 1)
  {
    latchValue = latchValue + relay4;
    myHeader = "= RELAYS =";
    r4 = "[4]";
  } else {
    if (pinValue4 == 0) {
      latchValue = latchValue - relay4;
      myHeader = "= RELAYS =";
      r4 = "[-]";
    }
  }
  pushToDisplay (myHeader, r1, r2, r3, r4, r5, r6, r7, r8);
}

BLYNK_WRITE(V5)
{
  int pinValue5 = param.asInt();
  if (pinValue5 == 1)
  {
    latchValue = latchValue + relay5;
    myHeader = "= RELAYS =";
    r5 = "[5]";
  } else {
    if (pinValue5 == 0) {
      latchValue = latchValue - relay5;
      myHeader = "= RELAYS =";
      r5 = "[-]";
    }
  }
  pushToDisplay (myHeader, r1, r2, r3, r4, r5, r6, r7, r8);
}

BLYNK_WRITE(V6)
{
  int pinValue6 = param.asInt();
  if (pinValue6 == 1)
  {
    latchValue = latchValue + relay6;
    myHeader = "= RELAYS =";
    r6 = "[6]";
  } else {
    if (pinValue6 == 0) {
      latchValue = latchValue - relay6;
      myHeader = "= RELAYS =";
      r6 = "[-]";
    }
  }
  pushToDisplay (myHeader, r1, r2, r3, r4, r5, r6, r7, r8);
}

BLYNK_WRITE(V7)
{
  int pinValue7 = param.asInt();
  if (pinValue7 == 1)
  {
    latchValue = latchValue + relay7;
    myHeader = "= RELAYS =";
    r7 = "[7]";
  } else {
    if (pinValue7 == 0) {
      latchValue = latchValue - relay7;
      myHeader = "= RELAYS =";
      r7 = "[-]";
    }
  }
  pushToDisplay (myHeader, r1, r2, r3, r4, r5, r6, r7, r8);
}

BLYNK_WRITE(V8)
{
  int pinValue8 = param.asInt();
  if (pinValue8 == 1)
  {
    latchValue = latchValue + relay8;
    myHeader = "= RELAYS =";
    r8 = "[8]";
  } else {
    if (pinValue8 == 0) {
      latchValue = latchValue - relay8;
      myHeader = "= RELAYS =";
      r8 = "[-]";
    }
  }
  pushToDisplay (myHeader, r1, r2, r3, r4, r5, r6, r7, r8);
}

BLYNK_WRITE(V9)
{
  int pinValue9 = param.asInt();
  if (pinValue9 == 1)
  {
    latchValue = relay1 + relay2 + relay3 + relay4 + relay5 + relay6 + relay7 + relay8;
    myHeader = "= RELAYS =";
    r1 = "[1]";
    r2 = "[2]";
    r3 = "[3]";
    r4 = "[4]";
    r5 = "[5]";
    r6 = "[6]";
    r7 = "[7]";
    r8 = "[8]";
    Blynk.virtualWrite(1, HIGH);
    Blynk.virtualWrite(2, HIGH);
    Blynk.virtualWrite(3, HIGH);
    Blynk.virtualWrite(4, HIGH);
    Blynk.virtualWrite(5, HIGH);
    Blynk.virtualWrite(6, HIGH);
    Blynk.virtualWrite(7, HIGH);
    Blynk.virtualWrite(8, HIGH);
  } else {
    if (pinValue9 == 0) {
      latchValue = 0;
      myHeader = "= RELAYS =";
      r1 = "[-]";
      r2 = "[-]";
      r3 = "[-]";
      r4 = "[-]";
      r5 = "[-]";
      r6 = "[-]";
      r7 = "[-]";
      r8 = "[-]";
      Blynk.virtualWrite(1, LOW);
      Blynk.virtualWrite(2, LOW);
      Blynk.virtualWrite(3, LOW);
      Blynk.virtualWrite(4, LOW);
      Blynk.virtualWrite(5, LOW);
      Blynk.virtualWrite(6, LOW);
      Blynk.virtualWrite(7, LOW);
      Blynk.virtualWrite(8, LOW);
    }
  }
  //display.clear();
  pushToDisplay (myHeader, r1, r2, r3, r4, r5, r6, r7, r8);
}

//---------------------------------------------------------------------------------------------------------------
//                                                LIBRARY CALL
//---------------------------------------------------------------------------------------------------------------
// Initialize the OLED display using Arduino Wire:
SSD1306Wire display(0x3c, SDA, SCL);   // ADDRESS, SDA, SCL  -  SDA and SCL usually populate automatically


//---------------------------------------------------------------------------------------------------------------
//                                                  SETUP
//---------------------------------------------------------------------------------------------------------------
void setup()
{
  Serial.begin(115200);

  Serial.println("Initialising display ...");

  delay(1000);

  // Initialising the UI will init the display too.
  display.init();

  display.flipScreenVertically();
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_16);
  display.clear();

  delay(500);

  Wire.begin(); // Wake up I2C bus
  // Set I/O bank A to outputs
  Wire.beginTransmission(I2C_ADDR);
  Wire.write(0x00); // IODIRA register
  Wire.write(0x00); // Set all of bank A to outputs
  Wire.write(0); // Turn all relays off
  Wire.endTransmission();

  myHeader = "= RELAYS =";
  r1 = "Live relay: ";
  r5 = "Ready";
  display.clear();
  pushToDisplay (myHeader, r1, r2, r3, r4, r5, r6, r7, r8);

  int period = 500;

  Serial.println("Starting WiFi");
  WiFi.begin(ssid, pass);
  // WiFi.begin("Telstra69EB6F", "ragd48gdeat6");
  reconnect();
  Serial.println("Blynk setup");
  Blynk.begin(auth, ssid, pass);
}


//---------------------------------------------------------------------------------------------------------------
//                                               MAIN LOOP
//---------------------------------------------------------------------------------------------------------------
void loop()
{
  Blynk.run();
  // Serial.println("Receiving from Blynk");

  byte relay = 1;

  display.clear();                              //clear display @ beginning of each loop

  if (latchValue < 0) {
    latchValue = 0;
  }
  // turn on relay
  Wire.beginTransmission(I2C_ADDR);
  Wire.write(0x12); // Select bank A
  //    Wire.write(relay); // Send value to bank A
  Wire.write(latchValue); // Send latch value
  Wire.endTransmission();
  delay(500);

  /* turn off all relays
    Wire.beginTransmission(I2C_ADDR);
    Wire.write(0x12); // Select bank A
    Wire.write(0); // Send value to bank A
    Wire.endTransmission();
    delay(500);
  */
}


// Reconnect script for WiFi
void reconnect() {

  myHeader = "= WiFi =";
  r1 = "Connecting to ...";
  r5 = ssid;

  //attempt to connect to the wifi if connection is lost
  if (WiFi.status() != WL_CONNECTED) {
    //debug printing
    Serial.print("Connecting to ");
    Serial.println(ssid);
    delay (1000);
    r5 = "[-]";
    display.clear ();
    pushToDisplay (myHeader, r1, r2, r3, r4, r5, r6, r7, r8);
    delay(1000);

    //loop while we wait for connection
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }

    //print out some more debug once connected
    display.clear();
    myHeader = "= WiFi =";
    r1 = "WiFi connected";

    Serial.println("");
    Serial.println(myStr);
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    display.clear();
    pushToDisplay (myHeader, r1, r2, r3, r4, r5, r6, r7, r8);
  }
}

void pushToDisplay (String myHeader, String r1, String r2, String r3, String r4, String r5, String r6, String r7, String r8 ) {
  // Push to display
  display.clear();
  display.drawString(0, 0, myHeader);
  //  display.drawString(0, 16, myStr);
  //  display.drawString(0, 32, myStr2);
  display.drawString(0, 16, r1);
  display.drawString(30, 16, r2);
  display.drawString(60, 16, r3);
  display.drawString(90, 16, r4);
  display.drawString(0, 34, r5);
  display.drawString(30, 34, r6);
  display.drawString(60, 34, r7);
  display.drawString(90, 34, r8);
  display.display();
  // Push to serial
  Serial.println(myHeader);
}
