#include "Heap.h"
#include <stdlib.h>

int h_parent(int i)
{
  return (int)((i - 1) / 2);
}


int h_child_left(int i)
{
  return (2 * i) + 1;
}


int h_child_right(int i)
{
  return (2 * i) + 2;
}


bool h_create(Heap **h)
{
  Heap *newHeap = (Heap *)malloc(sizeof(Heap));

  if (newHeap == NULL) {
    return false;
  }
  else {
    newHeap->tree = NULL;
    newHeap->size = 0;
    *h = newHeap;
    return true;
  }
}


bool h_insert(Heap *h, int data)
{
  int *temp = (int *)realloc(h->tree, sizeof(int) * (h->size + 1));

  if (temp == NULL) {
    return false;
  }

  h->tree = temp;
  h->size++;
  h->tree[h->size - 1] = data;

  int child = h->size - 1;
  int parent = h_parent(child);

  while (child > 0 && h->tree[child] > h->tree[parent]) {
    int swap = h->tree[parent];
    h->tree[parent] = h->tree[child];
    h->tree[child] = swap;
    child = parent;
    parent = h_parent(child);
  }

  return true;
}


bool h_remove(Heap *h, int *data)
{
  if (h->tree == NULL) {
    return false;
  }

  if (h->size == 1) {
    *data = h->tree[0];
    free(h->tree);
    h->tree = NULL;
  }
  else {
    *data = h->tree[0];

    int oldEnd = h->tree[h->size - 1];
    int *temp = (int *)realloc(h->tree, sizeof(int) * (h->size - 1));

    if (temp == NULL) {
      return false;
    }

    h->size--;
    h->tree[0] = oldEnd;
    int parent = 0;
    int left = 0;
    int right = 0;
    int maximum = 0;

    while (true) {
      left = h_child_left(parent);
      right = h_child_right(parent);

      if (left < h->size && (h->tree[left] > h->tree[parent])) {
        maximum = left;
      }
      else {
        maximum = parent;
      }

      if (right < h->size && (h->tree[right] > h->tree[maximum])) {
        maximum = right;
      }

      if (maximum == parent) {
        break;
      }
      else {
        int swap = h->tree[maximum];
        h->tree[maximum] = h->tree[parent];
        h->tree[parent] = swap;
        parent = maximum;
      }
    }
  }

  return true;
}


void h_erase(Heap *h)
{
  if (h != NULL) {
    if (h->tree != NULL) {
      free(h->tree);
    }
    free(h);
  }
}
