//
// Created by Angel Zaprianov on 16.9.2016 г..
//

#ifndef ARDUINOMID_SENSINIT_H
#define ARDUINOMID_SENSINIT_H


//
// Read Tachometer
#include "sens/RpmSens.h"
//
// Read SpeedHub
#include "sens/VssSens.h"
//
//
#include "sens/EcuSens.h"
//
// Screen back-light sensor
#include "sens/DimSens.h"
//
// Temperature
#include "sens/TmpSens.h"

//
// Read inside temperature
#include "DispInfo.h"
void handleBackLight(){

}

void sensorsInit() {
    //
    // Sense of sensors ;)
    sensRpm();
    sensVss();
    sensEcu();
    sensAvr();
    sensTmp();
    sensDim(); // Dim display
}

#endif //ARDUINOMID_SENSINIT_H
