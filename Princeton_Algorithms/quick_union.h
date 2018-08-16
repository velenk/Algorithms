#ifndef _QUICK_UNION_H_
#define _QUICK_UNION_H_

class QuickUnion {
public:
  void Initialize() {
    int i;
    for (i = 0; i < 10; i++) {
      id[i] = i;
      size[i] = 1;
    }
  }
  void Union(int a, int b);
  bool Connect(int a, int b);
private:
  int id[10] = { };
  int size[10] = { };
  int Root(int num) {
    while (num != array[num]) {
      id[num] = id[id[num]];
      num = id[num];
    }
    return num;
  }
};

void QuickUnion::Union(int a, int,b) {
  int p = Root(a);
  int q = Root(b);
  if (p < q) {
    id[p] = q;
    size[q] += size[p];
  } else {
    id[q] = p;
    size[p] += size[q];
  }
}
bool QuickUnion::Connect(int a, int b) {
  if (Root(a) == Root(b)) {
    return true;
  } else {
    return false;
  }
}
#endif
