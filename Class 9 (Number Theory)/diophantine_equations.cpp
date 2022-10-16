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

// returns (true, x, y) if solution exists
// returns (false, 0, 0) otherwise

tuple<bool, int, int> diophantine(int a, int b, int c) {
  auto [d, _x, _y] = exgcd(a, b);
 
  if(c % d) {
    return {false, 0, 0};
  } else {
    int x = (c / d) * _x;
    int y = (c / d) * _y;
    return {true, x, y};
  }
}

int main() {

  int a = 5, b = -2, c = -1;
  auto [solution_exists, x, y] = diophantine(a, b, c);

  if(solution_exists) {
    cout << x << ' ' <<  y << endl;
  }

  return 0;
}