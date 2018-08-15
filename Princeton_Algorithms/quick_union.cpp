#ifndef _QUICK_UNION_H_
#define _QUICK_UNION_H_

class QuickUnion {
public:
  void Initialize() {
    int i;
    for (i = 0; i < 10; i++) {
      array[i] = i;
    }
  }
  void Union(int a, int b);
  bool Connect(int a, int b);
private:
  int array[10] = { };
  int Root(int num) {
    while (num != array[num]) {
      num = array[num];
    }
    return num;
  }
};

void QuickUnion::Union(int a, int,b) {
  int p = Root(a);
  int q = Root(b);
  array[p] = q;
}
bool QuickUnion::Connect(int a, int b) {
  if (Root(a) == Root(b)) {
    return true;
  } else {
    return false;
  }
}
#endif
