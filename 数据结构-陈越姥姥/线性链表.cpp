#include <iostream>

typedef struct Node {
  int data_value;
  struct Node *next;
} List;

List *ptrL;

int Lenth(List *ptrL) {
  List *p = ptrL;
  int lenth = 0;
  while (p) {
    p = p->next;
    ++lenth;
  }
  return lenth;
}

int main() {
  Lenth(ptrL);
  return 0;
}
