#include <iostream>
using namespace std;
int main() {
  int i, j, count, x;
  cin >> count;
  int number[count] = {};
  for (i = 0; i < count; ++i) {
    cin >> number[i];
  }
  for (i = count; i > 1; --i) {
    for (j = 0; j < i-1; ++j) {
      if (number[j] < number[j+1]) {
        x = number[j+1];
        number[j+1] = number[j];
        number[j] = x;
      }
    }
  }
  for (i = 0; i < count; ++i) {
    cout << number[i] << endl;
  }
  return 0;
}
