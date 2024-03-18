/*
 * Shift595Lib Example - Made by Martinelli Giacomo 17/03/2024
 * Library usage example
*/
#include <Shift595.h>

//         Shift | Data | Latch
Shift595 shift(12, 13, 11);

void setup() {
  Serial.begin(9600);
  //All parameters are optional, but there will be no default init
  //      Reset | Output Enable
  shift.begin(3, 2);
}

void loop() {
  //Disable or enable the output on the registers
  //true -> Active | false -> Disabled
  shift.outputState(true);
  Serial.println("Lights On!");
  Serial.println("Write AAAA using two cascaded registers");
  shift.write(0xaaaa);
  delay(3000);
  Serial.println("Lights Off!");
  shift.outputState(false);
  delay(3000);
  shift.outputState(true);
  Serial.println("Lights On!");
  Serial.println("Invert the registers");
  //MSB is optional and indicates the bit order(MSB true | LSB false)
  //            Data | MSB
  shift.write(0xaaaa, false);
  delay(3000);
  Serial.println("Lights Off!");
  shift.outputState(false);
  delay(3000);
  //Reset the 595
  //WARNING: The first write after the reset does not work properly
  Serial.println("Resetting...");
  shift.reset();
}
