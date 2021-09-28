#ifndef myDisplay
 #define myDisplay
#include "common.h"
#ifdef Lz428266WR
 #include "myComDisplay.h"
 #endif
#ifdef Lz428266YE
 #include "mySSD1306.h"
 #endif
#ifdef Lz428266VFD
 #include "myVFD.h"
 #endif
#ifdef Lz428266ZV
 #include "myLCD1602.h"
 #endif
#ifdef USBBOT
 #include "myComDisplay.h"
 #endif 
void screenon(void){screenonT();}
void screenoff(void){screenoffT();}
void tickclock(void){tickclockT();}
void showtime(void){showtimeT();}
void initmyDisplay(void){initmyDisplayT();}   
#endif