#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m;
vector<vector<int>> adj, adj_rev;
vector<bool> visited;
vector<int> order;
vector<int> component_id;
vector<bool> assignment;

void dfs1(int at) {
  visited[at] = true;
  for (int to : adj[at]) {
    if (!visited[to]) {
      dfs1(to);
    }
  }
  order.push_back(at);
}

void dfs2(int at, int cid) {
  visited[at] = true;
  component_id[at] = cid;
  for (auto to : adj_rev[at]) {
    if (!visited[to]) {
      dfs2(to, cid);
    }
  }
}

bool solve_2SAT() {
  visited.assign(2 * n, false);
  for (int i = 0; i < 2 * n; ++i) {
    if (!visited[i]) {
      dfs1(i);
    }
  }

  visited.assign(2 * n, false);
  component_id.assign(2 * n, -1);
  for (int i = 2 * n - 1, cid = 0; i >= 0; i--) {
    int root = order[i];
    if (!visited[root]) {
      dfs2(root, cid++);
    }
  }

  assignment.resize(n);
  for (int i = 0; i < n; i++) {
    if (component_id[2 * i] == component_id[2 * i + 1]) return false;
    assignment[i] = component_id[2 * i] > component_id[2 * i + 1];
  }

  return true;
}

void add_disjunction(int a, bool na, int b, bool nb) {
  // na and nb signify whether a and b are to be negated
  a = 2 * a + na;
  b = 2 * b + nb;
  int neg_a = a ^ 1;
  int neg_b = b ^ 1;
  adj[neg_a].push_back(b);
  adj[neg_b].push_back(a);
  adj_rev[b].push_back(neg_a);
  adj_rev[a].push_back(neg_b);
}

int main() {
  // cin >> n >> m;

  // adj.resize(2 * n);
  // adj_rev.resize(2 * n);

  // while (m--) {
  //   add_disjunction(...);
  // }

  // bool possible = solve_2SAT();

  // if (possible) {
  //   for (int i = 0; i < n; i++) {
  //     assignment[i];
  //   }
  // }
  // else {
  // }

  return 0;
}
