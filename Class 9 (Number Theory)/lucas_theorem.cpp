#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5 + 5;

int f[N], inv_f[N];

void init(int n, int mod) {

  //first calucalte i^(-1)
  inv_f[1] = 1;
  for(int i = 2; i <= n; i++){
    inv_f[i] = mod - 1LL * (mod / i) * inv_f[mod % i] % mod;
  } 

  //Calculate Inverse factorial and factorial
  inv_f[0] = f[0] = f[1] = 1;
  for(int i = 2; i <= n; i++){
    f[i] = ( 1LL * f[i - 1] * i) % mod;
    inv_f[i] = (1LL * inv_f[i] * inv_f[i - 1]) % mod;
  }
}

int nCr(int n, int r, int mod) {
  if(r > n) return 0;
  return (((1LL * f[n] * inv_f[n - r]) % mod) * inv_f[r]) % mod;
} 

//Convert n to some base
vector<int> toBase(ll n, int base) {
  vector<int> digits;
  while(n) {
    digits.push_back(n % base);
    n /= base;
  }
  return digits;
}

int lucas(ll n, ll r, int mod) {
  if(r > n) return 0;
  
  // convert n and r to base mod
  vector<int> N = toBase(n, mod);
  vector<int> R = toBase(r, mod);

  //make lengths equal by filling leading digits of R with zeros
  while(R.size() < N.size()){
    R.push_back(0);
  }

  //Calculate answer
  int ans = 1;
  for(int i = 0; i < N.size(); i++) {
    ans = (1LL * ans * nCr(N[i], R[i], mod)) % mod;
  }
  return ans;
}

int main() {
  
  ll n, r, p;
  cin >> n >> r >> p;
  init(p - 1, p);
  cout << lucas(n, r, p) << '\n';
}