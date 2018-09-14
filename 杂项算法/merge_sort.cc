#include <iostream>
using namespace std;

int a[9] = {1, 5, 6, 4, 3, 8, 9, 2, 7};

void MemeryArray(int a[], int first, int mid, int last, int temp[]) {
  int i = first, j = mid + 1, n = mid, m = last;
  int k = 0;
  while (i <= n && j <= m) {
    if (a[i] < a[j]) {
      temp[k] = a[i];
      ++k;
      ++i;
    } else {
      temp[k] = a[j];
      ++k;
      ++j;
    }
  }
  while (i <= n) {
    temp[k] = a[i];
    ++k;
    ++i;
  }
  while (j <= m) {
    temp[k] = a[j];
    ++k;
    ++j;
  }
  for (i = 0; i < k; ++i) {
    a[first + i] = temp[i];
  }
}

void MergeSort(int a[], int first, int last, int temp[]) {
  if (first < last) {
    int mid = (first + last) / 2;
    MergeSort(a, first, mid, temp);
    MergeSort(a, mid+1, last, temp);
    MemeryArray(a, first, mid, last, temp);
  }
}

int main() {
  int p[9] = { };
  MergeSort(a, 0, 8, p);
  int i;
  for (i = 0; i < 9; ++i) {
    cout << a[i] << ends;
  }
  return 0;
}
