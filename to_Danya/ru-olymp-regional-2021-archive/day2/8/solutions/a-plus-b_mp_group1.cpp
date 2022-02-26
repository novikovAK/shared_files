#include <bits/stdc++.h>

using namespace std;

int main() {
  string a, b, c;
  cin >> a >> b >> c;

  int n = a.size();
  vector<int> p(n);
  iota(p.begin(), p.end(), 0);
  int ans = 0;
  do {
    int xa = 0, xb = 0, xc = 0;
    bool bad = false;
    for (int i = 0; i < n; ++i) {
      xa = xa * 10 + (a[p[i]] - '0');
      xb = xb * 10 + (b[p[i]] - '0');
      xc = xc * 10 + (c[p[i]] - '0');
      if (i == 0 && (xa == 0 || xb == 0 || xc == 0)) {
        bad = true;
        break;
      }
    }
    if (!bad && xa + xb == xc) ++ans;
  } while (next_permutation(p.begin(), p.end()));
  cout << ans << "\n";
}
