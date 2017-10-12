#include <Arduino.h>
#include "bitsqueezr.hpp"

void setup() {
  Serial.begin(9600);

  delay(2500);
  Serial.println("\n\nBitsqueezr started...");

  BitSqueezr squeezr;
  squeezr.maxSize = 12; //12 byte maxsize
  squeezr.add(123456); //encode integer
  Serial.println("\nReturn A:\n");
  for (int i = 0; i < squeezr.currentSize - 1; i++)
      Serial.printf("%-2X \n", squeezr.bitArray[i]);
}

void loop() {
}
