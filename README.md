# Shift595Lib
This library is made for using the 74HC595 Shift Register, mainly used to drive led and signals using only few pins

## Description
With this library you can
* write to the register, even with cascaded registers
* Enable and Disable the output
* Reset the Register

## Simple Usage
This library requires atleast 3 pin which are Data, Shift Clock and Latch Clock to write the registers.

## Extended Usage
You can also connect the output enable and reset direclty to the arduino, but they are not mandatory.
You can leave empty the parameters of the functions using OE and RST if you don't need then
Example:\
shift.begin(3, 2);//<-With parameters\
shift.begin();//<- without Parameters
\
WARNING: First write after reset won't work properly.\
Check the Example for more details!
