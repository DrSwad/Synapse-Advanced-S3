#include <bits/stdc++.h>
using namespace std;

vector<int> restore_path(int s, int t, const vector<int> &p) {
  vector<int> path;

  for (int v = t; v != s; v = p[v]) path.push_back(v);
  path.push_back(s);

  reverse(path.begin(), path.end());
  return path;
}

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
  const int INF = 1000000000;
  vector<int> d(n, INF), p(n, -1);

  d[s] = 0;
  using pii = pair<int, int>;
  priority_queue<pii, vector<pii>, greater<pii>> q;
  q.push({0, s});
  while (!q.empty()) {
    int v = q.top().second;
    int d_v = q.top().first;
    q.pop();
    if (d_v != d[v]) continue;

    for (auto [to, w] : adj[v]) {
      if (d[v] + w < d[to]) {
        d[to] = d[v] + w;
        p[to] = v;
        q.push({d[to], to});
      }
    }
  }

  // Outputs
  for (int i = 0; i < n; i++) {
    cout << d[i] << " ";
  }

  return 0;
}