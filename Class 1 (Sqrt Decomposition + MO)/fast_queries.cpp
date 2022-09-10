#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;
int a[N];
int q;
int block_size;
int distinct_numbers;
int freq[N];
int ans[N];

struct Query {
  int id;
  int l, r;
  int ans;
  Query() {}
  Query(int _id, int _l, int _r) {
    id = _id, l = _l, r = _r;
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
  freq[a[id]]++;
  if (freq[a[id]] == 1) {
    distinct_numbers++;
  }
}

void remove(int id) {
  freq[a[id]]--;
  if (freq[a[id]] == 0) {
    distinct_numbers--;
  }
}

int get_ans() {
  return distinct_numbers;
}

void reset() {
  distinct_numbers = 0;
  for (int i = 0; i < N; i++) {
    freq[i] = 0;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  for (int cs = 1; cs <= t; cs++) {
    reset();
    cout << "Case " << cs << ":\n";

    cin >> n >> q;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    block_size = sqrt(n);

    for (int i = 0; i < q; i++) {
      int l, r;
      cin >> l >> r;
      l--, r--;
      query[i] = Query(i, l, r);
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
      ans[query[i].id] = query[i].ans;
    }

    for (int i = 0; i < q; i++) {
      cout << ans[i] << "\n";
    }
  }

  return 0;
}