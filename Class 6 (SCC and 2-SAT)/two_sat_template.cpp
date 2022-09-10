// Usage:
// TwoSat two_sat(n);
// two_sat.either(i, j); // i, j both 1-indexed
// two_sat.either(i, -j); // i, j both 1-indexed
// two_sat.solve(); // solves and returns true if solution exists
// two_sat.values; // get assignments in the solution

struct TwoSat {
  int n;
  vector<vector<int>> adj;
  vector<int> values; // 0 = false, 1 = true

  TwoSat(int n = 0) : n(n), adj(2 * n) {}

  void either(int i, int j) {
    i = 2 * (abs(i) - 1) + (i < 0);
    j = 2 * (abs(j) - 1) + (j < 0);
    adj[i ^ 1].push_back(j);
    adj[j ^ 1].push_back(i);
  }

  vector<int> enter, comp, curr_comp;
  int time = 0;
  int dfs(int at) {
    int low = enter[at] = ++time;
    curr_comp.push_back(at);
    for (int to : adj[at]) {
      if (!comp[to]) {
        low = min(low, enter[to] ? enter[to] : dfs(to));
      }
    }
    if (low == enter[at]) {
      int v;
      do {
        v = curr_comp.back();
        curr_comp.pop_back();
        comp[v] = low;
        if (values[v >> 1] == -1) values[v >> 1] = !(v & 1);
      } while (v != at);
    }
    return enter[at] = low;
  }

  bool solve() {
    values.assign(n, -1);
    enter.assign(2 * n, 0);
    comp = enter;
    for (int i = 0; i < 2 * n; i++) {
      if (!comp[i]) dfs(i);
    }
    for (int i = 0; i < n; i++) {
      if (comp[2 * i] == comp[2 * i + 1]) return false;
    }
    return true;
  }
};