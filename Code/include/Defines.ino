#include <Arduino.h>
#include <ESP32Servo.h>

#include <Adafruit_SSD1306.h>
#include <Adafruit_I2CDevice.h>
#include <Wire.h>
#include <SPI.h>
// Need to update for the ESP32 pinouts
#define GatePin 25

#define GateLED 9
#define GateLEDPwr 255
#define GateMin 0
#define GateMax 100

#define PotPin 26
#define Potmin 4095
#define Potmax 0

#define SwitchPin 35
#define ESCPin 16
#define ServoPin 17
#define CWMaxSpeed_Def 55 
#define CCWMaxSpeed_def 135
#define Stop 95
#define Spool  2
#define SpoolRPM 200

#define EncoderA 36 // Sensor VP  
#define EncoderB 39 // Sensor VN
#define EncoderSW 34

#define JoyX 32
#define JoyY 33
#define JoyB 27
#define JoyPot 14
#define JoySW 12

#define MOSI 23
#define MISO 

#define refresh 500
Servo ESC;
Servo servo;


void PinDeclare(){
pinMode(SwitchPin,INPUT_PULLUP);
pinMode(EncoderSW,INPUT_PULLUP);
pinMode(PotPin,INPUT);
pinMode(JoyX,INPUT);
pinMode(JoyY,INPUT);

  
}
//ccw vs cw.  6000 = 7.7k DCR, CW. 4.6 CCW 6000 vs 8000 makes same coil size
