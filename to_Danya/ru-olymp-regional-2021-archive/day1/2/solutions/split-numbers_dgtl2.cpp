#include <bits\stdc++.h>

using namespace std;

long long n, m, t;
vector<vector<int> > field;
int main() {
    cin >> t;
    for (int k = 0; k < t; k++) {
        cin >> n >> m;
        long long best = 1e18;
        char x = 'С';
        long long y = 0;
        long long sumAll = n * m * (n * m + 1) / 2;
        vector<int> prefV(n + 1, 0);
        vector<int> prefG(m + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefV[i] = prefV[i - 1];
            for (int j = 1; j <= m; j++) {
                prefV[i] += (i - 1) * m + j;
            }
        }
        for (int i = 1; i <= m; i++) {
            prefG[i] = prefG[i - 1];
            for (int j = 1; j <= n; j++) {
                prefG[i] += (j - 1) * m + i;
            }
        }
        for (int i = 1; i <= m; i++) {
            long long now_sum = prefG[i - 1];
            if (abs(now_sum - (sumAll - now_sum)) < best) {
                x = 'V';
                y = i;
                best = abs(now_sum - (sumAll - now_sum));
            }
        }
        for (int i = 1; i <= n; i++) {
            long long now_sum = prefV[i - 1];
            if (abs(now_sum - (sumAll - now_sum)) < best) {
                x = 'H';
                y = i;
                best = abs(now_sum - (sumAll - now_sum));
            }
        }
        cout << x << " " << y << endl;
    }
}