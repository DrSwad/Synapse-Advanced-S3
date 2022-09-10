#include <bits/stdc++.h>
using namespace std;

const int N = 100;
const int K = 20;

int n;
vector<int> e[N];
int h[N];
int sp[K][N];

void dfs(int at, int from) {
  sp[0][at] = from;
  for (int k = K - 1; k > 0; k--) {
    sp[k][at] = sp[k - 1][sp[k - 1][at]];
  }

  for (int to : e[at]) {
    if (to != from) {
      h[to] = h[at] + 1;
      dfs(to, at);
    }
  }
}

int lca(int u, int v) {
  if (h[v] > h[u]) swap(u, v);
  for (int k = K - 1; k >= 0; k--) {
    if (h[u] - (1 << k) >= h[v]) u = sp[k][u];
  }

  if (u == v) return u;

  for (int k = K - 1; k >= 0; k--) {
    if (sp[k][u] != sp[k][v]) u = sp[k][u], v = sp[k][v];
  }

  return sp[0][u];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    e[u].push_back(v);
    e[v].push_back(u);
  }

  dfs(0, 0);

  int q;
  cin >> q;

  while (q--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    
    cout << lca(u, v) + 1 << "\n";
  }

  return 0;
}