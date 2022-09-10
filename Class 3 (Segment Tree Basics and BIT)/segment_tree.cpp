#include <bits/stdc++.h>
using namespace std;

const int N = 100;

int n;
int a[N];
int tree[4 * N];

void build(int ti, int tl, int tr) {
  if (tl == tr) {
    tree[ti] = a[tl];
    return;
  }

  int tm = (tl + tr) / 2;
  build(ti << 1, tl, tm);
  build(ti << 1 | 1, tm + 1, tr);
  tree[ti] = max(tree[ti << 1], tree[ti << 1 | 1]);
}

void update(int ti, int tl, int tr, int pos, int val) {
  if (tl == tr) {
    a[pos] = val;
    tree[ti] = val;
    return;
  }

  int tm = (tl + tr) / 2;
  if (pos <= tm) update(ti << 1, tl, tm, pos, val);
  else update(ti << 1 | 1, tm + 1, tr, pos, val);
  tree[ti] = max(tree[ti << 1], tree[ti << 1 | 1]);
}

int query(int ti, int tl, int tr, int ql, int qr, int k) {
  if (ql <= tl and tr <= qr) return tree[ti]; // completely in

  int tm = (tl + tr) / 2;
  if (qr <= tm) return query(ti << 1, tl, tm, ql, qr);
  else if (ql > tm) return query(ti << 1 | 1, tm + 1, tr, ql, qr);
  else {
    int res_l = query(ti << 1, tl, tm, ql, qr);
    int res_r = query(ti << 1 | 1, tm + 1, tr, ql, qr);
    return max(res_l, res_r);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  build(1, 1, n);

  int q;
  cin >> q;

  while (q--) {
    int type;
    cin >> type;

    if (type == 1) {
      int pos, val;
      cin >> pos >> val;
      update(1, 1, n, pos, val);
    }
    else {
      int l, r;
      cin >> l >> r;
      cout << query(1, 1, n, l, r) << "\n";
    }
  }

  return 0;
}