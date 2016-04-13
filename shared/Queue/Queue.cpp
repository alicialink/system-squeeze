#include "Queue.h"
#include <stdlib.h>

bool q_init(Queue **q)
{
  Queue *newQueue = (Queue *)malloc(sizeof(Queue));
  if (newQueue != NULL) {
    newQueue->head = NULL;
    newQueue->tail = NULL;
    *q = newQueue;
    return true;
  }
  else {
    return false;
  }
}

bool q_enqueue(Queue *q, int data)
{
  Element *newElement = (Element *)malloc(sizeof(Element));

  newElement->data = data;
  newElement->prev = NULL;

  if (newElement != NULL) {

    // Assume if there is no head, there is no tail either.
    if (q->head == NULL) {
      newElement->next = NULL;
      q->head = newElement;
      q->tail = newElement;
    }

    // Otherwise prepend to the head.
    else {
      newElement->next = q->head;
      q->head->prev = newElement;
      q->head = newElement;
    }
    return true;
  }
  else {
    return false;
  }
}

bool q_dequeue(Queue *q, int *data)
{
  if (q->tail != NULL) {
    *data = q->tail->data;
    Element *oldTail = q->tail;
    Element *newTail = q->tail->prev;
    if (newTail == NULL) {
      q->tail = NULL;
      q->head = NULL;
    }
    else {
      newTail->next = NULL;
      q->tail = newTail;
    }
    free(oldTail);
    return true;
  }
  else {
    return false;
  }
}

bool q_peek(Queue *q, int *data)
{
  if (q->head != NULL) {
    *data = q->tail->data;
    return true;
  }
  else {
    return false;
  }
}

void q_destroy(Queue *q)
{
  Element *deleteMe = q->head;
  while (deleteMe != NULL) {
    Element *deleteMeNext = deleteMe->next;
    free(deleteMe);
    deleteMe = deleteMeNext;
  }
  free(q);
}

