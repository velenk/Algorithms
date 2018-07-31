#include <iostream>

typedef struct Node {
  int data_value = 0;
  struct Node *next = nullptr;
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

List *FindKth(int k, List *ptrl) {
  List *p = ptrl;
  int i = 0;
  while (p != nullptr && i < k) {
    p = p->next;
    ++i;
  }
  if (i == k) {
    return p;
  } else {
    return nullptr;
  }
}

List *FindX(int x, List *ptrl) {
  List *p = ptrl;
  while (p != nullptr && p->data_value != x) {
    p = p->next;
  }
  return p;
}

int main() {
  //a = Lenth(ptrL);
  return 0;
}
