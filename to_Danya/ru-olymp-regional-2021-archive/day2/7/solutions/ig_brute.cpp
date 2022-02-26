#include <cmath>
#include <functional>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>
#include <cstring>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const int N  = 100;

int a[N][N];

int n, m, c;

int ans = 0;

void brute(int i, int j) {
  if (i == n) {
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cout << a[i][j] + 1 << " \n"[j == m - 1];
    exit(0);
    return;
  }
  if (j == m) {
    brute(i + 1, 0);
  } else {
    for (int x = 0; x < c; x++) {
      bool bad = false;
      for (int rs = 0; rs < i; rs++) {
        if (bad) break;
        for (int cs = 0; cs < j; cs++) {
          if (a[rs][j] == x && a[rs][cs] == x && a[i][cs] == x) {
            bad = true;
            break;
          }
        }
      }
      if (bad) continue;
      a[i][j] = x;
      brute(i, j + 1);
    }
  }
}

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> c;
  brute(0, 0);
  cout << ans << '\n';
}
