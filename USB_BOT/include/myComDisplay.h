#ifndef myComDisplay
#define myComDisplay
#include "place.h"
#include "common.h"
#include "defs.h"
void tickclockT(void){}
void initmyDisplayT(void){
    Serial.begin(9600);
}
void screenonT(void){ Serial.println("ON");}
void screenoffT(void){ Serial.println("OFF");}
void showtimeT(void){ Serial.println("ShowTime");}
#endif //myComDisplay