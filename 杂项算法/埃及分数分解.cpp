#include <iostream>
using namespace std;

int main() {
  int p = 4;
  int q = 5;
  int i = 2;
  int j;
  while (p > 0) {
    j = p * i - q;
    if (j >= 0) {
      p = j;
      q *= i;
      j = MaxFactor(p, q);
      p /= j;
      q /= j;
      cout << "1/" << i << "+";
    }
    ++i;
  }
  return 0;
}
