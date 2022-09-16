#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(int n, const string &s) { // O(n)
  vector<int> p(n, 0);
  int k = 0; // k = π(i - 1)
  for (int i = 1; i < n; i++) {
    while (k > 0 && !(s[i] == s[k])) {
      k = p[k - 1];
    }
    if (s[i] == s[k]) {
      k++;
    }
    p[i] = k;
  }
  return p;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  int n = s.length();

  vector<int> p = prefix_function(n, s);
  for (int i : p) cerr << i << " ";

  return 0;
}