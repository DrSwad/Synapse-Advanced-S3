#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m;
vector<vector<int>> adj, adj_rev;
vector<bool> visited;
vector<int> order, component;

vector<int> roots(n, 0);
vector<int> root_nodes;
vector<int> components[N];
vector<vector<int>> adj_scc(n);

void dfs1(int at) {
  visited[at] = true;
  for (int to : adj[at]) {
    if (!visited[to]) {
      dfs1(to);
    }
  }
  order.push_back(at);
}

void dfs2(int at) {
  visited[at] = true;
  component.push_back(at);
  for (auto to : adj_rev[at]) {
    if (!visited[to]) {
      dfs2(to);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;

  adj.resize(n);
  adj_rev.resize(n);

  while (m--) {
    int from, to;
    cin >> from >> to;
    from--, to--;
    adj[from].push_back(to);
    adj_rev[to].push_back(from);
  }

  visited.assign(n, false);
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      dfs1(i);
    }
  }

  visited.assign(n, false);
  reverse(order.begin(), order.end());

  for (int i : order) {
    if (!visited[i]) {
      dfs2(i);

      int root = component.front();
      for (int u : component) roots[u] = root;
      components[root] = component;
      root_nodes.push_back(root);

      component.clear();
    }
  }

  for (int v = 0; v < n; v++) {
    for (int u : adj[v]) {
      int root_v = roots[v];
      int root_u = roots[u];
      if (root_u != root_v) {
        adj_scc[root_v].push_back(root_u);
      }
    }
  }

  return 0;
}
