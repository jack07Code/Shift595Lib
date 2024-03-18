/*
    Made by Martinelli Giacomo - 17/03/2024
    Shift595 - Library to use the 74HC595 Shift Register
    in a simplified way
*/
#ifndef Shift595_h
#define Shift595_h

#include "Arduino.h"

class Shift595 {
    public:
    Shift595(int _shift, int _data, int _latch);
    void begin(int Rst=0, int disable=0);
    void write(unsigned int num, bool msb=true);
    void outputState(bool active);
    void reset();
    private:
    int data;
    int shift;
    int latch;
    int rst=0;
    int dis=0;
    bool is_rst_present=false;
    bool is_dis_present=false;
};

#endif

//You shouldn't be reading this...
