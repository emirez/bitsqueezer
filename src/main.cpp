#include <Arduino.h>
#include "bitsqueezr.hpp"

void setup() {
  Serial.begin(9600);

  delay(2500);
  Serial.println("\n\nBitsqueezr started...");
  BitSqueezr squeezr;
  squeezr.maxSize = 12; //12 byte maxsize
  squeezr.add(98765); //encode integer
  //squeezr.add(1234); //encode integer

  Serial.println("\nReturn:\n");

  for (int i = 0; i < squeezr.currentSize - 1; i++)
      Serial.printf("%-2X \n", squeezr.bitArray[i]);
}

void loop() {
}
