#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll bigMod(ll a, ll e, ll mod) {
  if(e == 0) return 1LL;
  ll ret = bigMod(a, e >> 1LL, mod);
  ret = (__int128) ret * ret % mod;
  if(e & 1) {
    return (__int128) ret * a % mod;
  }
  return ret;
}

bool is_composite(ll n, ll a, ll d, ll s) {
  ll x = bigMod(a % n, d, n);

  if(x == 1 or x == n - 1) return false;

  for(int r = 1; r < s; r++) {
    x = (__int128) x * x % n;
    if(x == n - 1) return false;
  }
  return true;
}

bool miller_rabin(ll n, int trial = 10) {
  if(n < 4) {
    return n == 2 or n == 3;
  }

  if(n % 2 == 0) {
    return false;
  }

  int s = 0;
  ll d = n - 1;
  while((d & 1) == 0) {
    s++;
    d >>= 1LL;
  }

  while (trial--) {
    ll a = 2 + rand() % (n - 2);
    if(is_composite(n, a, d, s)) return false;
  }
  return true;
}

int main() {

  int t;
  cin >> t;

  while(t--) {
    ll n;
    cin >> n;

    if(miller_rabin(n)) cout << "YES\n";
    else cout << "NO\n";
  }

  return 0;
}