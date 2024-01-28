#pragma once
// Configuration file

///////////////// Serial  ///////////////////////////
// One, both or none of the Print options below can be used
#define PRINTWEBSERIAL   // follow print statements via web Serial.  Page adress: ipadres/webserial
#define PRINTSERIAL      // follow prints via serial connection
#define SERIALSPEED 115200
#define SHOWFPSEVERY 10000 //show fps every x msec

///////////////// PWM frequency //////////////////////
#define PWM_FREQUENCY 500
#define PWM_RESOLUTION  8

///////////////// wifi  //////////////////////////////
// names below are used as AccessPoint name and calls from master
#define NAME_ACCESSPOINT "VitrineLEDs"