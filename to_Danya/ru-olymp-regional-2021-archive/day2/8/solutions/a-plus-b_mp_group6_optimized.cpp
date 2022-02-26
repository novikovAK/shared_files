#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())

const int MOD = 1000000007;

using namespace std;

void addMod(int &a, int b) {
  if (b >= MOD) b -= MOD;
  if ((a += b) >= MOD) a -= MOD;
}

int solve(int na, int nb, int nc, int nd, int naz, int nbz) {
  if (nb != nc) return 0;
  struct State {
    int ac = 0, bd = 0;
  };
  vector<vector<vector<State>>> dp[2] = {
    vector<vector<vector<State>>>(nc + 1, vector<vector<State>>(2, vector<State>(nd + 1))),
    vector<vector<vector<State>>>(nc + 1, vector<vector<State>>(2, vector<State>(nd + 1)))
  };
  if (na) dp[1][0][0][0].ac = 1LL * (na - naz) * (nb ? nb : 1) % MOD;
  if (nb) dp[0][0][1][0].bd = 1LL * (nb - nbz) * (na ? na : 1) % MOD;;

  for (int a = 0; a <= na; ++a)
    for (int c = 0; c <= nc; ++c)
      for (int cb = 0; cb <= 1 && c + cb <= nb; ++cb)
        for (int d = 0; d <= nd; ++d) {
          int b = c + cb;
          auto & cd = dp[a&1][c][cb][d];
          if (b != nb && cb == 0) {
            addMod(dp[a&1][c][1][d].bd, cd.ac);
          }
          if (c != nc && cb == 1) {
            addMod(dp[a&1][c+1][0][d].ac, cd.bd);
          }
          if (d != nd) {
            addMod(dp[a&1][c][cb][d+1].bd, cd.bd);
          }
          if (a != na) {
            addMod(dp[(a&1)^1][c][cb][d].ac, cd.ac);
            cd.ac = cd.bd = 0;
          }
        }

  int ans = dp[na&1][nc][0][nd].ac;
  for (int i = 1; i < na; ++i) ans = 1LL * ans * i % MOD;
  for (int i = 1; i < nb; ++i) ans = 1LL * ans * i % MOD;
  for (int i = 1; i <= nc; ++i) ans = 1LL * ans * i % MOD;
  for (int i = 1; i <= nd; ++i) ans = 1LL * ans * i % MOD;
  return ans;
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
