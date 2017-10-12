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
  squeezr.add(123456); //integer
  //squeezr.add(1); //bool
  //squeezr.add(uint64_t("c")); //char

  uint8_t* t = squeezr.getEncodedData();
  Serial.printf("\Encoded %d bytes:\n", squeezr.getSize());
  for (int i = 0; i < squeezr.getSize(); i++)
      Serial.printf("%-2X \n", t[i]);

  if(squeezr.unpack(t))
      Serial.printf("\nDecoded bytes:\n%lld", (long long)squeezr.getDecodedData());
}

/*! \brief Loop function
 *
 *  Loop function, loops continously
 */
void loop() {
}
