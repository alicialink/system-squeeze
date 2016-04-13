typedef struct Element_ {
  int data;
  Element_ *next;
} Element;

typedef struct Stack_ {
  Element *head;
} Stack;

// Stack *s should never be NULL or bad things will happen

bool s_init(Stack **target);

bool s_push(Stack *s, int data);

bool s_pop(Stack *s, int *data);

void s_destroy(Stack *s);

bool s_peek(Stack *s, int *data);

