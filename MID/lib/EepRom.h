//
// Created by Angel Zaprianov on 28.6.2016 г..
//
// Since EEPROM have live time will use external-sourcecode ...
// http://www.hobbytronics.co.uk/arduino-external-eeprom

// http://playground.arduino.cc/Main/LibraryForI2CEEPROM
#ifdef EEP_ROM_ADDRESS

#include <Wire.h>

#else

#include <EEPROM.h>

#endif


#include "CarSens.h"
#include "MainFunc.h"

#ifndef ARDUINOMID_EepRom_H
#define ARDUINOMID_EepRom_H

//#define EEP_ROM_ADDRESS 0x50    //Address of 24LC256 eeprom chip
#define DEBUG_EEP_ROM
//#define EEP__INJ_SER true

//
//  Mega2560
// 	20 (SDA), 21 (SCL)
//
// Saves Addresses in EEP Rom
const int EEP_ADR_FTK = 0; // Fuel tank Astra G -  52 liter 14 gallons

const uint8_t EEP_ADR_CL1 = 1; // Consumption Float A LPG
const uint8_t EEP_ADR_Cl2 = 2; // Consumption Float B LPG

const uint8_t EEP_ADR_CB1 = 8; // Consumption Float A BNZ
const uint8_t EEP_ADR_CB2 = 9; // Consumption Float B BNZ
// Fuel distance
const uint8_t EEP_ADR_TD1 = 3; //  Travel distance
const uint8_t EEP_ADR_TD2 = 4; //  Travel distance
// Global car distance
const uint8_t EEP_ADR_WD1 = 5; // Work distance
const uint8_t EEP_ADR_WD2 = 6; // Work distance
// Trip distance
const uint8_t EEP_ADR_TR1 = 10; // Trip distance
const uint8_t EEP_ADR_TR2 = 11; // Trip distance
// Trip time
const uint8_t EEP_ADR_TT1 = 12; // Trip Time
const uint8_t EEP_ADR_TT2 = 13; // Trip Time

const int EEP_ADR_TRS = 5; // Tires size
const int EEP_ADR_RMS = 6; // Rims Size

// AT24C256
// We’re using a 256kbit eeprom which is actually 32kbytes of space.
//      262,144 bits / 8 bits in a byte = 32,768 bytes.
//      That’s 62 times the Arduino’s built-in storage!

struct SavedData {
    float fuel_adt;
    float fuel_def;
    float dist_trv;
    float total_km;
    float time_trp;
    float dist_trp;
};

//
//
class EepRom {

    CarSens &car;

public:
/**
 * EepRom Constructor
 * @param carSens
 */
    EepRom(CarSens &carSens) : car(carSens) {

    }

    void setup() {
#ifdef EEP_ROM_ADDRESS
        Wire.begin();
#endif

    };

    //
    // Called when zeroed current data
    void saveZeroingData();

    void saveCurrentData();

    void loadCurrentData();

    void saveTripData();

    void clearTripData();


    float getAvrageLitersPer100km() {
        return (container.dist_trv + car.getDst()) / getConsumedFuel();
    }

/**
 *
 */
    float getConsumedFuel() {

        //
        // Switching between LPG / BNZ
        if (car.getFuelState() == 0) { // BNZ [default]
            return container.fuel_def + car.getDefFuelCns();
        }
        if (car.getFuelState() == 1) { // LPG [additional]
            return container.fuel_adt + car.getAdtFuelCns();
        }
    }

/**
 * Injection data from USB serial monitor
 */
    void injectFromSerial(void);

/**
 * Gets worked distance
 * @return
 */
    int getWorkDistance(void);

/**
 * Gets travel distance
 * @return
 */
    float getTraveDistance(void);

/**
 * Gets default consumed fuel liters
 * @return
 */
    float getDefFuel(void);

/**
 * Gets additional consumed fuel liters
 * @return
 */
    float getAdtFuel(void);

/**
 * Sets new Car's worked distance
 * @param value
 * @return
 */
    void setWorkDistance(float value);

/**
 * Sets new travel distance
 * @param value
 * @return
 */
    void setTravelDistance(float value);

/**
 * Sets new Default consumed liters
 * @param value
 * @return
 */
    void setDefFuel(float value);

/**
 * Sets new Additional consumed liters
 * @param value
 * @return
 */
    void setAdtFuel(float value);

/**
 *  Gets all saved data
 * @return SavedData
 */
    SavedData getData(void);

private:
/**
 * Container of saved data
 */
    SavedData container;

/**
 *
 * @return
 */
    float loadAdtCons();

/**
 *
 * @param value
 */
    void saveAdtCons(float value = 0);

/**
 * Loads default consumption
 * @return
 */
    float loadDefCons();

/**
 * Loads default consumption
 * @param value
 */
    void saveDefCons(float value = 0);

/**
 * Loads Work distance
 * @return
 */
    float loadWorkDistance();

/**
 * Saves work distance
 * @param value
 */
    void saveWorkingDistance(float value = 0);

/**
 * loads travel distance
 * @return
 */
    float loadTravelDistance();

/**
 * Saves travel distance
 * @param value
 */
    void saveTravelDistance(float value = 0);

/**
 * Load trip distance
 */
    float loadTripDistance();

/**
 * Save trip distance
 */
    void saveTripDistance(float value = 0);

/**
 * Save trip Time
 */
    float loadTripTime();

/**
 * Save trip Time
 */
    void saveTripTime(float value = 0);

/**
 * Write data driver
 * @param theMemoryAddress
 * @param u8Byte
 */
    void WireEepRomWriteByte(uint16_t theMemoryAddress, int u8Byte);

/**
 * Read data driver
 * @param theMemoryAddress
 * @return
 */
    int WireEepRomRead(uint16_t theMemoryAddress);

};


/**
 *
 * @param theMemoryAddress
 * @param u8Byte
 */
void EepRom::WireEepRomWriteByte(uint16_t theMemoryAddress, int u8Byte) {

#ifdef  EEP_ROM_ADDRESS
    Wire.beginTransmission(EEP_ROM_ADDRESS);
    Wire.write((theMemoryAddress >> 8) & 0xFF);
    Wire.write((theMemoryAddress >> 0) & 0xFF);
    Wire.write((uint8_t) u8Byte);
    Wire.endTransmission();
#else
    EEPROM.write(theMemoryAddress, u8Byte);
#endif

    delay(10);
}

/**
 *
 * @param theMemoryAddress
 * @return
 */
int EepRom::WireEepRomRead(uint16_t theMemoryAddress) {
    int u8retVal = 0;
#ifdef  EEP_ROM_ADDRESS

    Wire.beginTransmission(EEP_ROM_ADDRESS);
    Wire.write((theMemoryAddress >> 8) & 0xFF);
    Wire.write((theMemoryAddress >> 0) & 0xFF);
    Wire.endTransmission();
    delay(10);
    Wire.requestFrom(EEP_ROM_ADDRESS, 1);
    if (Wire.available()) u8retVal = Wire.read();
#else
    u8retVal = EEPROM.read(theMemoryAddress);
#endif
    return u8retVal;
}

/**
 *  Loads travel consumption
 */
float EepRom::loadAdtCons() {
    int va1 = WireEepRomRead(EEP_ADR_CL1);
    int va2 = WireEepRomRead(EEP_ADR_Cl2);
    return restoreFloat(va1, va2);
}

/**
 *  Saves travel consumption
 */
void EepRom::saveAdtCons(float value) {
    int val[2];
    separateFloat(value, val);
    WireEepRomWriteByte(EEP_ADR_CL1, val[0]);
    WireEepRomWriteByte(EEP_ADR_Cl2, val[1]);
}

/**
 *  Loads travel consumption
 */
float EepRom::loadDefCons() {
    int va1 = WireEepRomRead(EEP_ADR_CB1);
    int va2 = WireEepRomRead(EEP_ADR_CB2);
    return restoreFloat(va1, va2);
}

/**
 *  Saves travel consumption
 */
void EepRom::saveDefCons(float value) {
    int val[2];
    separateFloat(value, val);
    WireEepRomWriteByte(EEP_ADR_CB1, val[0]);
    WireEepRomWriteByte(EEP_ADR_CB2, val[1]);
}

/**
 *  LOAD Travel distance
 */
float EepRom::loadTripDistance() {
    int va1 = WireEepRomRead(EEP_ADR_TR1);
    int va2 = WireEepRomRead(EEP_ADR_TR2);
    return restoreFloat(va1, va2);
}

/**
 *  SAVE Travel distance
 */
void EepRom::saveTripDistance(float value) {
    int val[2];
    separateFloat(value, val);
    WireEepRomWriteByte(EEP_ADR_TR1, val[0]);
    WireEepRomWriteByte(EEP_ADR_TR2, val[1]);
}

/**
 *  LOAD Travel distance
 */
float EepRom::loadTripTime() {
    int va1 = WireEepRomRead(EEP_ADR_TT1);
    int va2 = WireEepRomRead(EEP_ADR_TT2);
    return restoreFloat(va1, va2);
}

/**
 *  SAVE Travel distance
 */
void EepRom::saveTripTime(float value) {
    int val[2];
    separateFloat(value, val);
    WireEepRomWriteByte(EEP_ADR_TT1, val[0]);
    WireEepRomWriteByte(EEP_ADR_TT2, val[1]);
}

/**
 *  LOAD Travel distance
 */
float EepRom::loadTravelDistance() {
    int va1 = WireEepRomRead(EEP_ADR_TD1);
    int va2 = WireEepRomRead(EEP_ADR_TD2);
    return restoreFloat(va1, va2);
}

/**
 *  SAVE Travel distance
 */
void EepRom::saveTravelDistance(float value) {
    int val[2];
    separateFloat(value, val);
    WireEepRomWriteByte(EEP_ADR_TD1, val[0]);
    WireEepRomWriteByte(EEP_ADR_TD2, val[1]);
}

/**
 *  LOAD Work distance
 */
float EepRom::loadWorkDistance() {
    int va1 = WireEepRomRead(EEP_ADR_WD1);
    int va2 = WireEepRomRead(EEP_ADR_WD2);
    return restoreFloat(va1, va2);
}

/**
 *  Saves Work distance
 */
void EepRom::saveWorkingDistance(float value) {
    int val[2];
    separateFloat(value, val);
    WireEepRomWriteByte(EEP_ADR_WD1, val[0]);
    WireEepRomWriteByte(EEP_ADR_WD2, val[1]);
}

/*************************************************
 *  public
 *              Combined methods
 *
 */
/**
 * Saves data to EepRom
 */
void EepRom::saveCurrentData() {

    container.fuel_adt = container.fuel_adt + car.getAdtFuelCns();
    saveAdtCons(container.fuel_adt);

    container.fuel_def = container.fuel_def + car.getDefFuelCns();
    saveDefCons(container.fuel_def);

    container.dist_trv = container.dist_trv + car.getDst();
    saveTravelDistance(container.dist_trv);
}

/**
 * Saves trip data in order to continue the trip
 */
void EepRom::saveTripData() {

    float time = millis() / MILLIS_PER_HR;

    container.dist_trp = container.dist_trp + car.getDst();
    container.time_trp = container.time_trp + time;

    saveTripTime(container.time_trp);
    saveTripDistance(container.dist_trp);
}

/**
 * Clears trip data
 */
void EepRom::clearTripData() {
    container.time_trp = 0;
    container.dist_trp = 0;
}

/**
 * Load data from chip
 */
void EepRom::loadCurrentData() {
    container.fuel_adt = loadAdtCons();
    container.fuel_def = loadDefCons();
    container.time_trp = loadTripTime();        // Trip
    container.total_km = loadWorkDistance();    // Work
    container.dist_trp = loadTripDistance();    // Trip
    container.dist_trv = loadTravelDistance();  // Travel
    delay(5);
}

/**
 * Saves final data
 */
void EepRom::saveZeroingData() {

    container.fuel_adt = 0;
    container.fuel_def = 0;
    container.dist_trv = 0;
    //
    // Calculate total work distance
    container.total_km = container.total_km + (int(container.dist_trv) * 0.001);

    saveAdtCons(container.fuel_adt);
    saveDefCons(container.fuel_def);
    saveTravelDistance(container.dist_trv);
    saveWorkingDistance(container.total_km);
    //
    // In order to fix and clear assumed data
    car.clearBuffer();
}

/**
 * Gets Car's total distance
 * @return
 */
int EepRom::getWorkDistance(void) {
    return int(container.total_km * 1000);
}

/**
 * Gets saved travel distance
 * @return
 */
float EepRom::getTraveDistance(void) {
    return container.dist_trv;
}

/**
 * Gets default consumed fuel
 * @return
 */
float EepRom::getDefFuel(void) {
    return container.fuel_def;
}

/**
 * Gets additional consumed fuel
 * @return
 */
float EepRom::getAdtFuel(void) {
    return container.fuel_adt;
}


/**
 * Gets SavedData data
 * @return
 */
SavedData EepRom::getData(void) {
    return container;
}

/**
 *
 * @param value
 * @return
 */
void EepRom::setWorkDistance(float value) {
    container.total_km = value;
}

/**
 *
 * @param value
 * @return
 */
void EepRom::setTravelDistance(float value) {
    container.dist_trv = value;
}

/**
 *
 * @param value
 * @return
 */
void EepRom::setDefFuel(float value) {
    container.fuel_def = value;
}

/**
 *
 * @param value
 * @return
 */
void EepRom::setAdtFuel(float value) {
    container.fuel_adt = value;
}

/**
 * Injection data from USB serial monitor
 */
void EepRom::injectFromSerial(void) {
    //
// Serial injection
#if defined(SERIAL_INJECT_DATA)
    String srlAllData;
    String srlStrName;
    String srlOutputs;
    //
    // Default message
    srlOutputs = F(" None ... Sorry! ");
    //
    // Execute command from serial
    if (Serial.available() > 0) {
        float saveTemp;

        srlStrName = Serial.readStringUntil('=');
        //
        // So ... C++ is static language...
        //      is not good idea to re-set dynamically

        if (srlStrName == "trd") {
            // trip distance
            saveTemp = Serial.readStringUntil('\n').toInt() * 0.01;
            container.dist_trp = saveTemp;
            srlOutputs = F("Trip distance ");
            srlOutputs += saveTemp;
        }

        if (srlStrName == "trt") {
            // Trip time
            saveTemp = Serial.readStringUntil('\n').toInt() * 0.01;
            container.time_trp = saveTemp;
            srlOutputs = F("Trip time ");
            srlOutputs += saveTemp;
        }

        if (srlStrName == "change") {
            // Saves type
            saveTemp = Serial.readStringUntil('\n').toInt();
            if (saveTemp == 1)saveTripData();
            srlOutputs = F("Change trip data ");
            srlOutputs += saveTemp;
        }

        if (srlStrName == "lpg") {
            // Total Liters per hour consumed
            saveTemp = Serial.readStringUntil('\n').toInt() * 0.01;
            setAdtFuel(saveTemp);
            srlOutputs = F("LPG fuel ");
            srlOutputs += saveTemp;
        }
        if (srlStrName == "bnz") {
            // Total Liters per hour consumed
            saveTemp = Serial.readStringUntil('\n').toInt() * 0.01;
            setDefFuel(saveTemp);
            srlOutputs = F("BNZ fuel ");
            srlOutputs += saveTemp;
        }
        if (srlStrName == "ttd") {
            // Total Travel distance
            saveTemp = Serial.readStringUntil('\n').toInt() * 0.01;
            setTravelDistance(saveTemp);
            srlOutputs = F("Travel distance ");
            srlOutputs += saveTemp;
        }
        if (srlStrName == "wrk") {
            // Total work distance
            saveTemp = Serial.readStringUntil('\n').toInt() * 0.001;
            setWorkDistance(saveTemp);
            srlOutputs = F("Work distance ");
            srlOutputs += saveTemp;
        }

        if (srlStrName == "save_wrk") {
            // Saves type 
            saveTemp = Serial.readStringUntil('\n').toInt();
            if (saveTemp == 1)saveWorkingDistance(container.total_km);
            srlOutputs = F("Saved Work distance ");
            srlOutputs += saveTemp;
        }
        if (srlStrName == "save") {
            // Saves type
            saveTemp = Serial.readStringUntil('\n').toInt();
            if (saveTemp == 1)saveCurrentData();
            srlOutputs = F("Saved All data ");
            srlOutputs += saveTemp;
        }

        //
        // Show command information to human
        Serial.print(F("\n\n==============================================================\n"));
        Serial.print(F("\n \t\t  [MID $]> Affected value of "));
        Serial.print(srlOutputs);
        Serial.print(F("\n\n\n==============================================================\n\n"));
        //
        // Remove containers
        srlStrName = "";
        srlAllData = ""; // Clear recieved buffer
        srlOutputs = "";
    }
#endif
}


#endif