#ifndef defs
#define defs
#include "place.h"
#include <ESP8266WiFi.h>

#define myTele "357390016"
#define LzName "Lz42Stas"
#define S868 "519049530"

#ifdef USBBOT
 #ifndef STASSID
  #define STASSID "SAN"
  #define STAPSK  "37212628"
 #endif
 IPAddress gateway(192,168,0,1);
 IPAddress subnet(255,255,255,0);
 IPAddress dns1(194,158,196,137);
 IPAddress dns2(194,158,196,141);
#endif 

#endif

