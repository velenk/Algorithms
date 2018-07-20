#include <iostream>

const int k_MaxSize = 100

typedef struct {
  int data_value[k_MaxSize];
  int last;
} List;

List *MakeEmpty() {
  List *ptrL;
  ptrL = (List*)malloc(sizeof(List));
  ptrL->last = -1;
  return ptrL;
}

int FindElement(int x, List *ptrL) {
  int i = 0;
  while ( ) {
    if (i == ptrL->last) {
      i = -1;
      break;
    }
    if (ptrL->data_value[i] == x) {
      break;
    }
    i++;
  }
  return i;
}

