#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);

  int a, b, c, d;
  a = atoi(argv[1]);
  b = atoi(argv[2]);
  c = atoi(argv[3]);
  d = atoi(argv[4]);
  if (c == -1) c = b;
  int n = a + b + c + d;

  int az, bz, cz, dz;
  az = a > 1 ? rnd.next(1, a / 2) : 0;
  bz = b > 1 ? rnd.next(1, b / 2) : 0;
  cz = c > 0 ? rnd.next(1, max(1, c - 1)) : 0;
  dz = d > 0 ? rnd.next(1, max(1, d - 1)) : 0;

  bool zeros = true;
  bool badDigit = false;
  for (int i = 5; i < argc; ++i) {
    if (!strcmp(argv[i], "allZero")) {
      az = a;
      bz = b;
    } else if (!strcmp(argv[i], "noZero")) {
      zeros = false;
      az = bz = cz = dz = 0;
    } else if (!strcmp(argv[i], "badDigit")) {
      badDigit = true;
    }
  }

  string sa, sb, sc;

  struct Triple {
    int x, y, z;
  };
  vector<Triple> variants[2][2][2];

  for (int x = 0; x < 10; ++x)
    for (int y = 0; y < 10; ++y)
      for (int need = 0; need < 2; ++need) {
        int z = x + y + need;
        int create = z / 10;
        z %= 10;
        variants[x == 0 || y == 0 || z == 0][create][need].push_back({x, y, z});
      }

  auto addDigits = [&](int m, int mz, int create, int need) {
    for (int i = 0; i < m; ++i) {
      Triple t = rnd.any(variants[i < mz][create][need]);
      if (badDigit) {
        badDigit = false;
        do {
          t.z = (t.z + rnd.next(2, 8)) % 10;
        } while (!zeros && t.z == 0);
      }
      sa += '0' + t.x;
      sb += '0' + t.y;
      sc += '0' + t.z;
    }
  };
  addDigits(b, bz, 0, 1);
  addDigits(d, dz, 1, 1);
  addDigits(a, az, 0, 0);
  addDigits(c, cz, 1, 0);

  vector<int> pp(n);
  iota(pp.begin(), pp.end(), 0);
  shuffle(pp.begin(), pp.end());
  for (int i = 0; i < n; ++i)
    cout << sa[pp[i]];
  cout << "\n";
  for (int i = 0; i < n; ++i)
    cout << sb[pp[i]];
  cout << "\n";
  for (int i = 0; i < n; ++i)
    cout << sc[pp[i]];
  cout << "\n";

  return 0;
}
