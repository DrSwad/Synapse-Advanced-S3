#include <bits/stdc++.h>
using namespace std;

const int N = 100;
const int LOGN = 7;

int n;
int a[N];

int bit[N];

void update(int p, int v) {
  while (p <= n) {
    bit[p] += v;
    p += p & -p;
  }
}

int query(int p) {
  int ans = 0;
  while (p) {
    ans += bit[p];
    p -= p & -p;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; i++) {
    update(i, a[i]);
  }

  int q;
  cin >> q;

  while (q--) {
    string type;
    cin >> type;

    if (type == "Update") {
      int p, v;
      cin >> p >> v;
      update(p, v);
    }
    else {
      int qsum;
      cin >> qsum;

      int p = 0, psum = 0;
      for (int jump = LOGN - 1; jump >= 0; jump--) {
        int new_p = p + (1 << jump);
        if (new_p <= n and psum + bit[new_p] < qsum) {
          psum += bit[new_p];
          p = new_p;
        }
      }

      cout << p + 1 << "\n";
    }
  }

  return 0;
}