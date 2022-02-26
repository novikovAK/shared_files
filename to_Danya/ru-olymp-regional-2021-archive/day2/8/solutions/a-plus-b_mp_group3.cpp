#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())

const int MOD = 1000000007;

using namespace std;

int solve(int na, int nb, int nc, int nd, int, int) {
  struct State {
    int a = 0, b = 0, c = 0, d = 0;
  };
  vector<vector<vector<vector<State>>>> dp(na + 1, vector<vector<vector<State>>>(nb + 1, vector<vector<State>>(nc + 1, vector<State>(nd + 1))));
  if (na) dp[1][0][0][0].a = na;
  if (nb) dp[0][1][0][0].b = nb;

  for (int a = 0; a <= na; ++a)
    for (int b = 0; b <= nb; ++b)
      for (int c = 0; c <= nc; ++c)
        for (int d = 0; d <= nd; ++d) {
          auto const& cd = dp[a][b][c][d];
          if (a != na) {
            (dp[a+1][b][c][d].a += 1LL * (cd.a + cd.c) * (na - a) % MOD) %= MOD;
          }
          if (b != nb) {
            (dp[a][b+1][c][d].b += 1LL * (cd.a + cd.c) * (nb - b) % MOD) %= MOD;
          }
          if (c != nc) {
            (dp[a][b][c+1][d].c += 1LL * (cd.b + cd.d) * (nc - c) % MOD) %= MOD;
          }
          if (d != nd) {
            (dp[a][b][c][d+1].d += 1LL * (cd.b + cd.d) * (nd - d) % MOD) %= MOD;
          }
        }

  return (dp[na][nb][nc][nd].a + dp[na][nb][nc][nd].c) % MOD;
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
