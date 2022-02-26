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

int solve(int a, int b, int c, int d, int az, int bz) {
  if (b == 0) {
    if (d == 0) return 1LL * fact[a - 1] * (a - az) % MOD;
    return 0;
  }

  int ansAB = 1;
  ansAB = 1LL * ansAB * fact[c] % MOD;
  ansAB = 1LL * ansAB * fact[a + b] % MOD;
  ansAB = 1LL * ansAB * fact[d + b - 1] % MOD;
  ansAB = 1LL * ansAB * ofact[b - 1] % MOD;

  int ansB = 1;
  ansB = 1LL * ansB * fact[b] % MOD;
  ansB = 1LL * ansB * fact[c] % MOD;
  ansB = 1LL * ansB * fact[a + b - 1] % MOD;
  ansB = 1LL * ansB * fact[d + b - 1] % MOD;
  ansB = 1LL * ansB * ofact[b - 1] % MOD;
  ansB = 1LL * ansB * ofact[b - 1] % MOD;

  int ansA = (ansAB - ansB + MOD) % MOD;

  if (a > 0) {
    ansA = 1LL * ansA * inv(a) % MOD;
    ansA = 1LL * ansA * (a - az) % MOD;
  }
  ansB = 1LL * ansB * inv(b) % MOD;
  ansB = 1LL * ansB * (b - bz) % MOD;

  return (ansA + ansB) % MOD;
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
