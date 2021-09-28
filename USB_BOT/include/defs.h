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
 //#define myName "USBBOT"

 String myID="947749033";
 String myName="USBBOT";
 String myToken="947749033:AAF00_fgJ0JTYF2XsZE_0zbz-8aZwtdHb-M";
 //#define pinbeep D2
 #ifdef work
  IPAddress ip(192,168,1,233); 
 #endif


 //IPAddress ip(192,168,0,196);
 IPAddress gateway(192,168,0,1);
 IPAddress subnet(255,255,255,0);
 IPAddress dns1(194,158,196,137);
 IPAddress dns2(194,158,196,141);
#endif 

#endif

