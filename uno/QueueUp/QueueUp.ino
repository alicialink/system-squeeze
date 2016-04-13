#include "Queue.h"
#include "MemoryMeter.h"

#define LED_PIN 12

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

  Queue *q = NULL;
  if (q_init(&q)) {
    Serial.println(F("OK: Allocation"));
    printMemoryFree();
    Serial.print(F("ENQUEUE: "));
    for (int i=0; i<25; i++) {
      Serial.print(i);
      Serial.print(F(" "));
      if (!q_enqueue(q, i)) {
        Serial.print(F("fail"));
      }
    }
    Serial.println(F(""));

    int data = -1;
    Serial.print(F("PEEK: "));
    if (q_peek(q, &data)) {
      Serial.print(data);
    }
    else {
      Serial.print(F(" fail"));
    }
    Serial.println(F(""));

    Serial.print(F("DEQUEUE: "));
    while (q_dequeue(q, &data)) {
      Serial.print(data);
      Serial.print(F(" "));
    }
    Serial.println(F(""));

    Serial.println(F("ATTEMPT: Deallocation"));
    q_destroy(q);
    printMemoryFree();
  }
  else {
    Serial.println(F("FAIL: Allocation"));
  }
  printMemoryFree();

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

