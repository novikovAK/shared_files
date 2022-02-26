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
        for (int i = 1; i <= m; i++) {
            long long now_sum = 0;
            for (int j = 1; j <= n; j++) {
                for (int l = 1; l < i; l++) {
                    now_sum += (j - 1) * m + l; 
                }
            }
            if (abs(now_sum - (sumAll - now_sum)) < best) {
                x = 'V';
                y = i;
                best = abs(now_sum - (sumAll - now_sum));
            }
        }
        for (int i = 1; i <= n; i++) {
            long long now_sum = 0;
            for (int j = 1; j < i; j++) {
                for (int l = 1; l <= m; l++) {
                    now_sum += (j - 1) * m + l; 
                }
            }
            if (abs(now_sum - (sumAll - now_sum)) < best) {
                x = 'H';
                y = i;
                best = abs(now_sum - (sumAll - now_sum));
            }
        }
        cout << x << " " << y << endl;
    }
}