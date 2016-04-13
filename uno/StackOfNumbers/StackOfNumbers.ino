#include "Stack.h"
#include "MemoryMeter.h"

#define LED_PIN 33

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

  Stack *s = NULL;
  if (s_init(&s)) {
    Serial.println(F("OK: Allocation"));
    printMemoryFree();

    Serial.print(F("PUSH: "));
    for (int i=0; i<25; i++) {
      if (s_push(s, i)) {
        Serial.print(i);
        Serial.print(F(" "));
      }
      else {
        Serial.print(i);
        Serial.print(F(" fail"));
        break;
      }
    }
    Serial.println(F(""));

    printMemoryFree();

    int peekData = -1;
    Serial.print(F("PEEK: "));
    if (s_peek(s, &peekData)) {
      Serial.println(peekData);
    }
    else {
      Serial.println(F(" fail"));
    }

    printMemoryFree();

    Serial.print(F("POP: "));
    int data = -1;
    while (s_pop(s, &data)) {
      Serial.print(data);
      Serial.print(F(" "));
    }
    Serial.println(F(""));

    Serial.println(F("ATTEMPT: Deallocation"));
    s_destroy(s);
    printMemoryFree();
  }
  else {
    Serial.println(F("FAIL: Allocation"));
  }
  Serial.println(F("========================="));

  digitalWrite(LED_PIN, HIGH);
  Serial.println(F("\nDELAY: 2500 ms"));
  delay(2500);
}

void printMemoryFree()
{
  Serial.print(F(">>> RAM FREE BYTES: "));
  Serial.println(memoryFree());
}

