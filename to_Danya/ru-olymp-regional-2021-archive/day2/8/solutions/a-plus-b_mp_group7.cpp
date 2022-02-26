#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())

const int MOD = 1000000007;

using namespace std;

vector<int> fact;
vector<int> ofact;

int inv(int a) {
  int r = 1;
  for (int b = MOD - 2; b; b >>= 1, a = 1LL * a * a % MOD) {
    if (b & 1) r = 1LL * r * a % MOD;
  }
  return r;
}

int solve(int a, int b, int c, int d, int, int) {
  if (b != c) return 0;
  if (b == 0) {
    if (d == 0) return fact[a];
    return 0;
  }
  int ans = 1;

  ans = 1LL * ans * fact[c] % MOD;
  ans = 1LL * ans * fact[a + b] % MOD;
  ans = 1LL * ans * fact[d + b - 1] % MOD;
  ans = 1LL * ans * ofact[b - 1] % MOD;

  return ans;
}

int main() {
  string a, b, c;
  cin >> a >> b >> c;

  int n = sz(a);

  fact.resize(n + 3);
  fact[0] = 1;
  for (int i = 1; i <= n + 2; ++i)
    fact[i] = 1LL * i * fact[i - 1] % MOD;
  ofact.resize(n + 3);
  ofact[n + 2] = inv(fact[n + 2]);
  for (int i = n + 2; i >= 1; --i)
    ofact[i - 1] = 1LL * ofact[i] * i % MOD;

  int na = 0, nb = 0, nc = 0, nd = 0, naz = 0, nbz = 0;
  for (int i = 0; i < n; ++i) {
    int x = a[i] - '0';
    int y = b[i] - '0';
    int z = c[i] - '0';
    int needCarry = (x + y) % 10 != z;
    int createCarry = x + y + needCarry >= 10;
    if (x + y + needCarry - createCarry * 10 != z) {
      cout << "0\n";
      return 0;
    }
    if (!needCarry && !createCarry) {
      ++na;
      if (x == 0 || y == 0 || z == 0) ++naz;
    } else if (needCarry && !createCarry) {
      ++nb;
      if (x == 0 || y == 0 || z == 0) ++nbz;
    } else if (!needCarry) {
      ++nc;
    } else {
      ++nd;
    }
  }

  cout << solve(na, nb, nc, nd, naz, nbz) << "\n";
}
