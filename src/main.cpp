#include <Arduino.h>
#include "bitsqueezr.hpp"

/*! \brief Setup function
 *
 *  Setup function, only executed once
 */
void setup() {
  Serial.begin(9600);

  delay(2500);
  Serial.println("\n\nBitsqueezr started...");

  BitSqueezr squeezr;
  squeezr.setMaxSize(12);
  squeezr.add(12345678); //integer
  squeezr.add(1); //bool
  squeezr.add(uint64_t("c")); //char

  uint8_t* t = squeezr.getData();
  Serial.printf("\nReturning %d bytes:\n", squeezr.getSize()-1);
  for (int i = 0; i < squeezr.getSize() - 1; i++)
      Serial.printf("%-2X \n", t[i]);
}

/*! \brief Loop function
 *
 *  Loop function, loops continously
 */
void loop() {
}
