#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // Inputs
  int n, m, s;
  cin >> n >> m >> s;
  s--;

  vector<vector<pair<int, int>>> adj(n);
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  // Algorithm
  int INF = n;
  vector<int> d(n, INF);
  d[s] = 0;
  deque<int> q;
  q.push_front(s);

  while (!q.empty()) {
    int v = q.front();
    q.pop_front();

    for (auto [u, w] : adj[v]) {
      if (d[v] + w < d[u]) {
        d[u] = d[v] + w;
        if (w == 1) q.push_back(u);
        else q.push_front(u);
      }
    }
  }

  // Outputs
  for (int i = 0; i < n; i++) {
    cout << d[i] << " ";
  }

  return 0;
}