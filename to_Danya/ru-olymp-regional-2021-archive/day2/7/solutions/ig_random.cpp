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

mt19937 rnd(228);

int cnt[10][10][3];
int a[10][10];

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, c;
  cin >> n >> m >> c;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      a[i][j] = rnd() % c;
    }
  }
  auto cost = [&] () {
    for (int i = 0; i < m; i++) for (int j = 0; j < m ;j++) cnt[i][j][0] = cnt[i][j][1] = cnt[i][j][2] = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        for (int k = j + 1; k < m; k++) {
          if (a[i][j] == a[i][k]) {
            sum += cnt[j][k][a[i][j]];
            cnt[j][k][a[i][j]]++;
          }
        }
      }
    }
    return sum;
  };
  while (true) {
    int me = cost();
    for (int it = 0; it < n * m; it++) {
      for (int i = 0; i < n; i++) {
        for (int j= 0; j < m; j++) {
          int was = a[i][j];
          a[i][j] = rnd() % c;
          int go = cost();
          if (go < me) {
            me = go;
          } else if (go > me) {
            a[i][j] = was;
          }
        }
      }
    }
    if (!me) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          cout << a[i][j] + 1 << ' ';
        }
        cout << '\n';
      }
      return 0;
    } else {
      for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) a[i][j] = rnd() % c;
    }
  }
}
