typedef struct Heap_ {
  int size;
  int *tree;
} Heap;

int h_parent(int i);

int h_child_left(int i);

int h_child_right(int i);

bool h_create(Heap **h);

bool h_insert(Heap *h, int data);

bool h_remove(Heap *h, int *data);

void h_erase(Heap *h);

