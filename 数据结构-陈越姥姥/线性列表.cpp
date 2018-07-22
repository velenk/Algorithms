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

void Insert(int x, List *prtL, int i) {
  int j;
  if (ptrL->last >= k_MaxSize) {
    std::cout << "Error: No place to insert" << std::endl;
    return;
  }
  if (i < 0 || i > ptrL->last + 1) {
    std::cout << "Error: Invalid subscript" << std::endl;
    return;
  }
  for (j = ptrL->last + 1;j >= i;--j) {
    ptrL->data_value[j] = ptrL->data_value[j-1];
  }
  ptrL->data_value[i] = x;
  ptrL->last++;
  return;
}

void Delete(List *prtL, int i) {
  int j;
  if (i < 0 || i > ptrL->last) {
    std::cout << "Error: Invalid subscript" << std::endl;
    return;
  }
  for (j = i;j < ptrL->last;++j) {
    ptrL->data_value[j] = ptrL->data_value[j+1];
  }
  ptrL->last--;
  return;
}

