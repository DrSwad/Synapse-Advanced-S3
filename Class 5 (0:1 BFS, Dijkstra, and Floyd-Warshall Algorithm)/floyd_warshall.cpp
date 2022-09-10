#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // Inputs
  int n, m;
  cin >> n >> m;

  // Algorithm
  const int INF = 1000000000;
  vector<vector<int>> d(n, vector<int>(n, INF));

  for (int i = 0; i < n; i++) d[i][i] = 0;

  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    d[u][v] = min(d[u][v], w);
    d[v][u] = min(d[v][u], w);
  }

  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }

  // Outputs
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << d[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}