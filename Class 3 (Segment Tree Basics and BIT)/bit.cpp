#include <bits/stdc++.h>
using namespace std;

const int N = 100;

int n;
int a[N + 1];
int bit[N + 1];

int query(int pos) {
  int res = 0;
  while (pos) {
    res += bit[pos];
    pos -= pos & -pos;
  }
  return res;
}

void update(int pos, int val) {
  while (pos <= n) {
    bit[pos] += val;
    pos += pos & -pos;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    update(i, a[i]);
  }

  int q;
  cin >> q;

  while (q--) {
    int type;
    cin >> type;

    if (type == 1) {
      int pos, val;
      cin >> pos >> val;
      update(pos, val);
    }
    else {
      int l, r;
      cin >> l >> r;
      cout << query(r) - query(l - 1) << "\n";
    }
  }

  return 0;
}