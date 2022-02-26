#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())

const int MOD = 1000000007;

using namespace std;

int solve(int na, int nb, int nc, int nd, int, int) {
  if (nb != nc) return 0;
  struct State {
    int a = 0, b = 0, c = 0, d = 0;
  };
  vector<vector<vector<vector<State>>>> dp(na + 1, vector<vector<vector<State>>>(nc + 1, vector<vector<State>>(2, vector<State>(nd + 1))));
  if (na) dp[1][0][0][0].a = na;
  if (nb) dp[0][0][1][0].b = nb;

  for (int a = 0; a <= na; ++a)
    for (int c = 0; c <= nc; ++c)
      for (int cb = 0; cb <= 1 && c + cb <= nb; ++cb)
        for (int d = 0; d <= nd; ++d) {
          int b = c + cb;
          auto const& cd = dp[a][c][cb][d];
          if (a != na) {
            (dp[a+1][c][cb][d].a += 1LL * (cd.a + cd.c) * (na - a) % MOD) %= MOD;
          }
          if (b != nb && cb == 0) {
            (dp[a][c][1][d].b += 1LL * (cd.a + cd.c) * (nb - b) % MOD) %= MOD;
          }
          if (c != nc && cb == 1) {
            (dp[a][c + 1][0][d].c += 1LL * (cd.b + cd.d) * (nc - c) % MOD) %= MOD;
          }
          if (d != nd) {
            (dp[a][c][cb][d+1].d += 1LL * (cd.b + cd.d) * (nd - d) % MOD) %= MOD;
          }
        }

  return (dp[na][nc][0][nd].a + dp[na][nc][0][nd].c) % MOD;
}

int main() {
  string a, b, c;
  cin >> a >> b >> c;

  int n = sz(a);
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
