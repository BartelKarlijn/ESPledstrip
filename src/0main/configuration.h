#pragma once
// Configuration file

///////////////// Serial  ///////////////////////////
// One, both or none of the Print options below can be used
#define PRINTWEBSERIAL   // follow print statements via web Serial.  Page adress: ipadres/webserial
#define PRINTSERIAL      // follow prints via serial connection
#define SERIALSPEED 115200
#define SHOWFPSEVERY 10000 //show fps every x msec

///////////////// pins  //////////////////////////////
#define PIN_L1 0
#define PIN_L2 1
#define PIN_L3 2
#define PIN_L4 3
#define PIN_L5 4
#define PIN_R1 5
#define PIN_R2 6
#define PIN_R3 7
#define PIN_R4 8
#define PIN_R5 9

#define PWM_CHANNEL_L1 0
#define PWM_CHANNEL_L2 1
#define PWM_CHANNEL_L3 2
#define PWM_CHANNEL_L4 3
#define PWM_CHANNEL_L5 4
#define PWM_CHANNEL_R1 5
#define PWM_CHANNEL_R2 6
#define PWM_CHANNEL_R3 7
#define PWM_CHANNEL_R4 8
#define PWM_CHANNEL_R5 9

///////////////// PWM frequency //////////////////////
#define PWM_FREQUENCY 500
#define PWM_RESOLUTION  8

///////////////// wifi  //////////////////////////////
// names below are used as AccessPoint name and calls from master
#define NAME_ACCESSPOINT "VitrineLEDs"