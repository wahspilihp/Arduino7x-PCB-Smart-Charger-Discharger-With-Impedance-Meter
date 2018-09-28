// Arduino Smart Charger / Discharger
// ---------------------------------------------------------------------------
// Created by Brett Watt on 20/07/2018
// Copyright 2018 - Under creative commons license 3.0:
//
// This software is furnished "as is", without technical support, and with no 
// warranty, express or implied, as to its usefulness for any purpose.
// 
// @brief 
// This is the header file for the Arduino Smart Charger / Discharger
// User and Board Custom Settings
//
// @author Email: info@vortexit.co.nz 
//       Web: www.vortexit.co.nz

const float shuntResistor = 3.3; // In Ohms - Shunt resistor resistance
const float referenceVoltage = 5.01; // 5V Output of Arduino Charger 1
//const float referenceVoltage = 4.94; // 5V Output of Arduino Charger 2
const float defaultBatteryCutOffVoltage = 2.8; // Voltage that the discharge stops ---> Will be replaced with Get DB Discharge Cutoff
const byte restTimeMinutes = 1; // The time in Minutes to rest the battery after charge. 0-59 are valid
const int lowMilliamps = 1000; //  This is the value of Milli Amps that is considered low and does not get recharged because it is considered faulty
const int highMilliOhms = 500; //  This is the value of Milli Ohms that is considered high and the battery is considered faulty
const int offsetMilliOhms = 0; // Offset calibration for MilliOhms Charger 2
const byte chargingTimeout = 8; // The timeout in Hours for charging
const byte tempThreshold = 7; // Warning Threshold in degrees above initial Temperature 
const byte tempMaxThreshold = 10; //Maximum Threshold in degrees above initial Temperature - Considered Faulty
// You need to run the Dallas get temp sensors sketch to get your DS serails
// Charger 1

DeviceAddress tempSensorSerial[9]= {
  {0x28, 0xFF, 0x81, 0x90, 0x63, 0x16, 0x03, 0x4A},
  {0x28, 0xFF, 0xB8, 0xC1, 0x62, 0x16, 0x04, 0x42},
  {0x28, 0xFF, 0xBA, 0xD5, 0x63, 0x16, 0x03, 0xDF},
  {0x28, 0xFF, 0xE7, 0xBB, 0x63, 0x16, 0x03, 0x23},
  {0x28, 0xFF, 0x5D, 0xDC, 0x63, 0x16, 0x03, 0xC7},
  {0x28, 0xFF, 0xE5, 0x45, 0x63, 0x16, 0x03, 0xC4},
  {0x28, 0xFF, 0x0E, 0xBC, 0x63, 0x16, 0x03, 0x8C},
  {0x28, 0xFF, 0xA9, 0x9E, 0x63, 0x16, 0x03, 0x99}
};  
// Charger 2
/*
DeviceAddress tempSensorSerial[9]= {
  {0x28, 0x02, 0x00, 0x07, 0xB6, 0x43, 0x01, 0x0B},
  {0x28, 0x0C, 0x01, 0x07, 0x96, 0x38, 0x01, 0xD4},
  {0x28, 0x02, 0x00, 0x07, 0xB6, 0x43, 0x01, 0x0B},
  {0x28, 0x07, 0x00, 0x07, 0x1C, 0x58, 0x01, 0xB3},
  {0x28, 0x02, 0x00, 0x07, 0x09, 0x3D, 0x01, 0x82},
  {0x28, 0x02, 0x00, 0x07, 0xC0, 0x20, 0x01, 0x3A},
  {0x28, 0x0C, 0x01, 0x07, 0x52, 0x43, 0x01, 0x8C},
  {0x28, 0x02, 0x00, 0x07, 0xB6, 0x43, 0x01, 0x0B}
 };  

//{0x28, 0x02, 0x00, 0x07, 0x5D, 0x2A, 0x01, 0xE5} Broken ?? Sensor
*/

const char userHash[] = "c4ca4238";    // Database Hash - this is unique per user - Get this from Charger / Discharger Menu -> View
const byte CDUnitID = 2;    // CDUnitID this is the Units ID - this is unique per user - Get this from Charger / Discharger Menu -> View -> Select your Charger / Discharger
