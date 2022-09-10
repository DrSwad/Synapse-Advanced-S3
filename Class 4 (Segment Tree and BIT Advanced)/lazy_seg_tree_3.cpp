#include <bits/stdc++.h>
using namespace std;

const int N = 100;

int n;
int a[N];
int ans[4 * N], lazy[4 * N];

void build(int v, int tl, int tr) {
  lazy[v] = 0;

  if (tl == tr) {
    ans[v] = a[tl];
    return;
  }

  int tm = (tl + tr) / 2;
  build(v << 1, tl, tm);
  build(v << 1 | 1, tm + 1, tr);

  ans[v] = max(ans[v << 1], ans[v << 1 | 1]);
}

void pushdown(int v, int tl, int tr) {
  int tm = (tl + tr) / 2;
  lazy[v << 1] += lazy[v];
  ans[v << 1] += lazy[v];
  lazy[v << 1 | 1] += lazy[v];
  ans[v << 1 | 1] += lazy[v];
  lazy[v] = 0;
}

void pullup(int v, int tl, int tr) {
  ans[v] = max(ans[v << 1], ans[v << 1 | 1]);
}

void update(int v, int tl, int tr, int l, int r, int x) {
  if (tr < l or r < tl) {
    return;
  }

  if (l <= tl and tr <= r) {
    lazy[v] += x;
    ans[v] += x;
    return;
  }

  pushdown(v, tl, tr);

  int tm = (tl + tr) / 2;
  update(v << 1, tl, tm, l, r, x);
  update(v << 1 | 1, tm + 1, tr, l, r, x);

  pullup(v, tl, tr);
}

int query(int v, int tl, int tr, int l, int r) {
  if (tr < l or r < tl) {
    return -1e9;
  }

  if (l <= tl and tr <= r) {
    return ans[v];
  }

  pushdown(v, tl, tr);

  int tm = (tl + tr) / 2;
  int left_ans = query(v << 1, tl, tm, l, r);
  int right_ans = query(v << 1 | 1, tl, tm, l, r);
  return max(left_ans, right_ans);
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
      int l, r;
      cin >> l >> r;
      cout << query(1, 0, n - 1, l, r) << "\n";
    }
  }

  return 0;
}