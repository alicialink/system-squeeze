#include "Stack.h"
#include <stdlib.h>

bool s_init(Stack **target)
{
  Stack *s = (Stack *)malloc(sizeof(Stack));
  
  if (s != NULL) {
    s->head = NULL;
    *target = s;
    return true;
  }
  else {
    return false;
  }
}

bool s_push(Stack *s, int data)
{
  Element *e = (Element *)malloc(sizeof(Element));
  if (e != NULL) {
    if (s->head == NULL) {
      e->next = NULL;
    }
    else {
      e->next = s->head;
    }
    e->data = data;
    s->head = e;
    return true;
  }
  else {
    return false;
  }
}

bool s_pop(Stack *s, int *data)
{
  if (s->head != NULL) {
    Element *oldHead = s->head;
    *data = oldHead->data;
    s->head = oldHead->next;
    free(oldHead);
    return true;
  }
  else {
    return false;
  }
}

bool s_peek(Stack *s, int *data)
{
  if (s->head != NULL) {
    *data = s->head->data;
    return true;
  }
  else {
    return false;
  }
}

void s_destroy(Stack *s)
{
  Element *deleteMe = s->head;
  while (deleteMe != NULL) {
    Element *deleteNext = deleteMe->next;
    free(deleteMe);
    deleteMe = deleteNext;
  }
  free(s);
}

