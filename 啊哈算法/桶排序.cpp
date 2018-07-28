#include <iostream>
using namespace std;
int main() {
  int receptical[101] = {};
  int i, j, number, count;
  cin >> count;
  for (i = 0; i < count; ++i) {
    cin >> number;
    receptical[number] += 1;
  }
  for (i = 100; i >= 0; --i) {
    for (j = 0; j < receptical[i]; ++j) {
      cout << i << endl;
    }
  }
  return 0;
}
