#include <bits/stdc++.h>

using namespace std;

// returns (d, x, y) such that ax + by = gcd(a, b) = d
tuple<int, int, int> exgcd(int a, int b) {
  if(b == 0) {
    return {a, 1, 0};
  }
  auto [d, _x, _y] = exgcd(b, a % b);
  // b * _x + (a - b (a/b) ) * _y
  // a * _y + b(_x - (a/b)_y)
  int x = _y;
  int y = _x - (a / b) * _y;
  return {d, x, y};
}

int main() {

  auto [d, x, y] = exgcd(3, 5);

  cout << d << ' ' << x << ' ' << y << '\n';

  return 0;
}