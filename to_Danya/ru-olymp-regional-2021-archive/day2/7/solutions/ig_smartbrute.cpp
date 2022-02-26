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

typedef unsigned long long ll;

mt19937_64 rnd(228);

const int N  = 100;

int a[N][N];
int cnt[N][N][3];
ll h[N][N][3];
unordered_set <ll> q[N];

int n, m, c;

int ans = 0;

ll s= 0; 

void brute(int i, int j) {
  if (i == n) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << a[i][j] + 1 << ' ';
      }
      cout << '\n';
    }
    exit(0);
    ans++;
    return;
  }
  if (j == m) {
    if (q[i].count(s)) return;
    brute(i + 1, 0);
    q[i].insert(s);
  } else {
    int grs = 0;
    vector <int> ord = {0,1,2};
    shuffle(ord.begin(),ord.end(),rnd);
    for(int x:ord){
      if (x >= c) continue;
      bool bad = false;
      for (int cs = 0; cs < j; cs++) {
        if (a[i][cs] == x) {
          if (cnt[cs][j][x]) {
            bad = true;
            break;
          }
        }
      }
      if (bad) continue;
      a[i][j] = x;
      for (int cs = 0; cs < j; cs++) {
        if (a[i][cs] == x) cnt[cs][j][x]++, s += h[cs][j][x];
      }
      brute(i, j + 1);
      for (int cs = 0; cs < j; cs++) {
        if (a[i][cs] == x) cnt[cs][j][x]--, s -= h[cs][j][x];
      }
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
  for (int i = 0; i < m; i++) for (int j = i +1 ; j < m; j++) for (int x = 0; x < c; x++) h[i][j][x] = rnd();
  brute(0, 0);
  cout << ans << '\n';
}

