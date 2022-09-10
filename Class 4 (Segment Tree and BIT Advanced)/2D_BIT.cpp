#include <bits/stdc++.h>
using namespace std;

class BIT {
public:
  int n;
  vector<int> f;
  BIT(int n) : n(n) {
    f.resize(n + 1, 0);
  }
  void update(int p, int v) {
    while (p <= n) f[p] += v, p += p & -p;
  }
  int pref(int p) {
    p++;
    int ret = 0;
    while (p) ret += f[p], p -= p & -p;
    return ret;
  }
  int range(int l, int r) {
    return pref(r) - pref(l - 1);
  }
};

class BIT2D {
public:
  int n, m;
  vector<BIT> f;
  BIT2D(int n, int m) : n(n) {
    f.resize(n + 1, BIT(m));
  }
  void update(int p, int q, int v) {
    while (p <= n) f[p].update(q, v), p += p & -p;
  }
  int pref(int p, int q) {
    int ret = 0;
    while (p) ret += f[p].pref(q), p -= p & -p;
    return ret;
  }
  int range(int x1, int y1, int x2, int y2) {
    return pref(x2, y2) - pref(x2, y1 - 1) - pref(x1 - 1, y2) + pref(x1 - 1, y1 - 1);
  }
};