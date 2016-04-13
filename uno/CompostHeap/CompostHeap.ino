#include "MemoryMeter.h"
#include "Heap.h"
#include <avr/pgmspace.h>

#define LED_PIN 12

// Test input for heap
#define COUNT 12
const byte littleRandom[]PROGMEM = { 20, 10, 35, 42, 27, 80, 90, 70, 30, 60, 50, 40 };

void setup()
{
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{

  digitalWrite(LED_PIN, LOW);
  Serial.println(F("\n========================="));
  printMemoryFree();

  Heap *h = NULL;
  if (h_create(&h)) {
    Serial.println(F("OK: Initialization"));

    Serial.print(F("INSERT: "));
    for (int i=0; i<COUNT; i++) {
      int j = pgm_read_byte(&littleRandom[i]);
      Serial.print(j);
      if (!h_insert(h, j)) {
        Serial.print(F(" fail "));
      }
      Serial.print(F(" "));
    }
    Serial.println(F(""));

    Serial.print(F("HEAP ARRAY: "));
    for (int i=0; i < (h->size); i++) {
      Serial.print(h->tree[i]);
      Serial.print(F(" "));
    }
    Serial.println(F(""));

    Serial.print(F("EXTRACT: "));
    int j = -1;
    while (h_remove(h, &j)) {
      Serial.print(j);
      Serial.print(F(" "));
    }
    Serial.println(F(""));

    Serial.println(F("ATTEMPT: Destruction"));
    h_erase(h);
  }
  else {
    Serial.println(F("FAIL: Initialization"));
  }

  printMemoryFree();
  Serial.println(F("========================="));

  digitalWrite(LED_PIN, HIGH);
  Serial.println(F("\nDELAY: 20000 ms"));
  delay(20000);
}

void printMemoryFree()
{
  Serial.print(F(">>> RAM FREE BYTES: "));
  Serial.println(memoryFree());
}
