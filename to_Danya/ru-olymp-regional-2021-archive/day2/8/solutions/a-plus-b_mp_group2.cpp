#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())

const int MOD = 1000000007;

using namespace std;

int main() {
  string a, b, c;
  cin >> a >> b >> c;

  int n = sz(a);
  vector<int> createCarry(n), needCarry(n);
  for (int i = 0; i < n; ++i) {
    int x = a[i] - '0';
    int y = b[i] - '0';
    int z = c[i] - '0';
    needCarry[i] = (x + y) % 10 != z;
    createCarry[i] = x + y + needCarry[i] >= 10;
    if (x + y + needCarry[i] - createCarry[i] * 10 != z) {
      cout << "0\n";
      return 0;
    }
  }

  vector<vector<int>> d(n, vector<int>(1 << n, 0));

  for (int mask = 1; mask < 1 << n; ++mask)
    for (int v = 0; v < n; ++v)
      if (mask & (1 << v)) {
        int pmask = mask ^ (1 << v);
        int &cd = d[v][mask];
        if (pmask == 0)
          cd = a[v] != '0' && b[v] != '0' && c[v] != '0' && !createCarry[v];
        else
          for (int pv = 0; pv < n; ++pv)
            if (pmask & (1 << pv))
              if (createCarry[v] == needCarry[pv])
                (cd += d[pv][pmask]) %= MOD;
      }

  int ans = 0;
  for (int i = 0; i < n; ++i)
    if (!needCarry[i]) 
      (ans += d[i][(1 << n) - 1]) %= MOD;

  cout << ans << "\n";
}
