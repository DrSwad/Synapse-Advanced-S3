#include <bits/stdc++.h>
using namespace std;

const int N = 100;

int n;
int a[N];
int lazy[4 * N];

void build(int v, int tl, int tr) {
  if (tl == tr) {
    lazy[v] = a[tl];
    return;
  }

  int tm = (tl + tr) / 2;
  build(v << 1, tl, tm);
  build(v << 1 | 1, tm + 1, tr);

  lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int x) {
  if (tr < l or r < tl) {
    return;
  }

  if (l <= tl and tr <= r) {
    lazy[v] += x;
    return;
  }

  int tm = (tl + tr) / 2;
  update(v << 1, tl, tm, l, r, x);
  update(v << 1 | 1, tm + 1, tr, l, r, x);
}

int query(int v, int tl, int tr, int id) {
  if (tl == tr) {
    return lazy[v];
  }

  int tm = (tl + tr) / 2;
  if (id <= tm) return query(v << 1, tl, tm, id) + lazy[v];
  else return query(v << 1 | 1, tm + 1, tr, id) + lazy[v];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];

  build(1, 0, n - 1);

  int q;
  cin >> q;

  while (q--) {
    string type;
    cin >> type;

    if (type == "Update") {
      int l, r, x;
      cin >> l >> r >> x;
      update(1, 0, n - 1, l, r, x);
    }
    else {
      int id;
      cin >> id;
      cout << query(1, 0, n - 1, id) << "\n";
    }
  }

  return 0;
}