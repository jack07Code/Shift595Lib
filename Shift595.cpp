#include "Arduino.h"
#include "Shift595.h"

//Define mandatory pins
Shift595::Shift595(int _shift, int _data, int _latch) {
    shift=_shift;
    data=_data;
    latch=_latch;
}

/*
Initialise Library
Rst and disable are optional. If not specified, nothing will be done
*/
void Shift595::begin(int Rst=0, int disable=0) {
    if(Rst!=0) {
        is_rst_present=true;
        rst=Rst;
        digitalWrite(rst, HIGH);
        pinMode(rst, OUTPUT);
    }
    if(disable!=0) {
        is_dis_present=true;
        dis=disable;
        digitalWrite(dis, LOW);
        pinMode(dis, OUTPUT);
    }
    pinMode(data, OUTPUT);
    pinMode(shift, OUTPUT);
    pinMode(latch, OUTPUT);
    digitalWrite(data, LOW);
    digitalWrite(shift, LOW);
    digitalWrite(latch, LOW);
}

/*
Write data into the register. Cascading registers works
msb is optional. If not specified, the data will be written in msb order
msb -> true: MSBFIRST | false: LSBFIRST
*/
void Shift595::write(unsigned int num, bool msb=true) {
    shiftOut(data, shift, msb?MSBFIRST:LSBFIRST, num);
    digitalWrite(latch, LOW);
    digitalWrite(latch, HIGH);
    digitalWrite(latch, LOW);
}

/*
Enable/Disable latch output
active -> true: Enable | false: Disable
*/
void Shift595::outputState(bool active) {
    if(is_dis_present) digitalWrite(dis, !active);
}

/*
Reset Register
The reset pin on the 595 only resets the shift register. latching needs to be done after reset
WARNING: During the first write after reset, only the first register will work properly
*/
void Shift595::reset() {
    if(is_rst_present) {
        digitalWrite(rst, LOW);
        digitalWrite(rst, HIGH);
        digitalWrite(latch, LOW);
        digitalWrite(latch, HIGH);
        digitalWrite(latch, LOW);
    }
}

//If you're reading this, go touch some grass...