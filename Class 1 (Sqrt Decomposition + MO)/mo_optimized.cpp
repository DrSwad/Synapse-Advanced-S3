#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;

int n;
int a[N];
int q;
int block_size;
int range_ans;

struct Query {
  int l, r;
  int ans;
  Query() {}
  Query(int _l, int _r) {
    l = _l, r = _r;
  }
  bool operator<(Query &other) const {
    int curr_block = l / block_size;
    int other_block = other.l / block_size;
    if (curr_block != other_block) {
      return curr_block < other_block;
    }
    else {
      return r < other.r;
    }
  }
} query[N];

void include(int id) {
  range_ans += a[id];
}

void remove(int id) {
  range_ans -= a[id];
}

int get_ans() {
  return range_ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  block_size = sqrt(n);

  cin >> q;
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    query[i] = Query(l, r);
  }

  sort(query, query + q);

  int L = 0, R = -1;
  for (int i = 0; i < q; i++) {
    int ql = query[i].l;
    int qr = query[i].r;

    while (R < qr) {
      R++;
      include(R);
    }
    while (L > ql) {
      L--;
      include(L);
    }
    while (L < ql) {
      remove(L);
      L++;
    }
    while (R > qr) {
      remove(R);
      R--;
    }

    query[i].ans = get_ans();
  }

  for (int i = 0; i < q; i++) {
    cout << query[i].ans << "\n";
  }

  return 0;
}