#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;
int a[N];
int block_size;
int block_ans[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  block_size = sqrt(n);
  int total_blocks = ((n + (block_size - 1)) / block_size);

  for (int block_id = 0; block_id < total_blocks; block_id++) {
    int l = block_id * block_size;
    int r = min(n, (block_id + 1) * block_size);
    for (int i = l; i < r; i++) {
      block_ans[block_id] += a[i];
    }
  }

  int q;
  cin >> q;

  while (q--) {
    int l, r;
    cin >> l >> r;
    l--, r--;

    int ans = 0;
    int block_l = l / block_size;
    int block_r = r / block_size;

    if (block_l == block_r) {
      for (int i = l; i <= r; i++) {
        ans += a[i];
      }
    }
    else {
      for (int i = l; i < (block_l + 1) * block_size; i++) {
        ans += a[i];
      }
      for (int i = block_r * block_size; i <= r; i++) {
        ans += a[i];
      }
      for (int block_id = block_l + 1; block_id < block_r; block_id++) {
        ans += block_ans[block_id];
      }
    }

    cout << ans << "\n";
  }

  return 0;
}