#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
    registerTestlibCmd(argc, argv);

    int n = inf.readInt();
    int m = inf.readInt();
    int c = inf.readInt();
    vector <vector <int> > a(n,vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        a[i][j] = ouf.readInt();
        if (a[i][j] <= 0 || a[i][j] > c) quitf(_wa, "Incorrect color of the cell (%d, %d)", i + 1, j + 1);
      }
    }
    for (int x1 = 0; x1 < n; x1++) {
      for (int x2 = x1 + 1; x2 < n; x2++) {
        for (int y1 = 0; y1 < m; y1++) {
          for (int y2 = y1 + 1; y2 < m; y2++) {
            vector <int> cls = {a[x1][y1], a[x1][y2], a[x2][y1], a[x2][y2]};
            bool bad = false;
            for (int i = 1; i <( int) cls.size(); i++) if (cls[i] != cls[i - 1]) bad = true;
            if (!bad) {
              quitf(_wa, "Bad rectangle with two corners in (%d, %d) (%d, %d)", x1 + 1, y1 + 1, x2 + 1, y2 + 1);
            }
          }
        }
      }
    }
    quitf(_ok, "Good job!");

    return 0;
}
