//Counting Divisors in O(N^(1/3))

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

bool square(ll n) {
  ll root = sqrt(n);
  for(ll from = root - 2; from <= root + 2; from++){
    if(from * from == n) return true;
  }
  return false;
}

ll count_divisors(ll n) {
  //divide n with primes <= n^(1/3) and update answer
  ll ans = 1LL;

  for (int p = 2; 1LL * p * p * p <= n; p++){
    int exp = 0;
    while(n % p == 0){
      n /= p; exp++;
    }
    ans *= (exp + 1);
  }

  //If n doesn't contain any prime factors anymore then we are done
  if(n == 1) return ans;

  //Check if n is prime
  if(miller_rabin(n)) {
    ans *= 2LL; //add contribution to answer 
  }
  //Check if n is a square of a prime
  else if(square(n)) {
    ans *= 3LL;
  }
  //else n is product of two different primes 
  else {
    ans *= 4LL;
  }

  return ans;
}
int main() {
  ll n;
  cin >> n;

  cout << count_divisors(n) << '\n';
}