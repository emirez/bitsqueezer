#ifndef UNIT_TEST
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

  int maxsize = 12;

  BitSqueezr squeezr;
  squeezr.setMaxSize(maxsize);
  char string[] = "HelloWorld";
  if(!squeezr.add(string))
      Serial.printf("[ERROR] Couldnt fit in %d bytes, we should not send!", maxsize);

  //squeezr.add(12345678); //integer
  //squeezr.add(1); //bool
  //squeezr.add(uint64_t("c")); //char

  uint8_t* t = squeezr.getEncodedData();
  Serial.printf("\nEncoded %d bytes:\n", squeezr.getTotalBytes());
  for (int i = 0; i < squeezr.getTotalBytes(); i++)
      Serial.printf("%-2X \n", t[i]);

  if(squeezr.unpack(t))
      Serial.printf("\nDecoded bytes:\n%d", squeezr.getDecodedData());
}

/*! \brief Loop function
 *
 *  Loop function, loops continously
 */
void loop() {
}
#endif
