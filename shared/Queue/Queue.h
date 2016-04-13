typedef struct Element_ {
  int data;
  Element_ *prev;
  Element_ *next;
} Element;

typedef struct Queue_ {
  Element *head;
  Element *tail;
} Queue;


// Things will fail horribly if q is ever NULL

bool q_init(Queue **q);

bool q_enqueue(Queue *q, int data);

bool q_dequeue(Queue *q, int *data);

bool q_peek(Queue *q, int *data);

void q_destroy(Queue *q);

