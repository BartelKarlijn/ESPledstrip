#pragma once
#include <Arduino.h>

// External libraries
// read and save data
#include <Preferences.h>   // om op ESP32 eeprom te kunnen lezen en schrijven
#include <SPIFFS.h>        // om het filesysteem van ESP32 te gebruiken
#include <ArduinoJson.h>

// Wifi
#include <WiFi.h>           //
#include <AsyncTCP.h>       // nodig voor de ESPAyncWebserver
#include <ESPAsyncWebServer.h>
#include <ElegantOTA.h>
#include <WebSerial.h>

// Own libraries
// variables
#include <0main/configuration.h>
#include <0main/configStrip.h>
#include <0main/globalvariables.h>

// Own subroutines
//   main
#include <0main/setupSerial.h>
#include <0main/print.h>
#include <0main/save_eprom.h>

// Spiffs() integrated file system)
#include <spiffs/humanReadableSize.h>
#include <spiffs/listFiles.h>
#include <spiffs/listStorage.h>
#include <spiffs/setupSpiffs.h>
#include <spiffs/writeFile.h>
#include <spiffs/readFile.h>
#include <spiffs/fileDefault2Single.h>
#include <spiffs/fileLoad2Single.h>
#include <spiffs/fileSaveSingle.h>

// fps
#include <0main/show_fps.h>

//main (needs to be after spiffs)
#include <0main/setupLed.h>
//sigleled
#include <singleled/led_aan.h>
#include <singleled/led_glow.h>
#include <singleled/led_rand.h>
#include <singleled/led_ramp.h>
#include <singleled/led_uit.h>
#include <singleled/showled.h>
#include <singleled/loadAnimatie.h>

//wifi
#include <wifi/on_file.h>            // downloaden of verwijderen
#include <wifi/on_fileUpload.h>
#include <wifi/onOTA.h>
#include <wifi/on_getCommitInfo.h>
#include <wifi/on_getSingled.h>
#include <wifi/on_getSetSingled.h>
#include <wifi/on_getfileLoad2Singled.h>
#include <wifi/on_getfileDefault2Singled.h>
#include <wifi/on_getfileSaveSingled.h>
#include <wifi/on_wifisave.h>
#include <wifi/setup_AsyncWebserver.h> 
#include <wifi/setup_ConnectKnownWifi.h>
#include <wifi/setup_CreateAccessPoint.h>
#include <wifi/startWifi.h>
#include <wifi/scanWifiNetworks.h>
