#include <bits/stdc++.h>
using namespace std;

long long num(int len, int d, int pos, int d2) {
    long long res = 0;
    for (int i = 0; i < len; i++) {
        if (i == pos) {
            res = res * 10 + d2;
        } else {
            res = res * 10 + d;
        }
    }
    return res;
}

int main() {
    long long x;
    cin >> x;
    int k;
    cin >> k;

    long long ans = -1;
    if (k == 0) {
        for (int i = 1; i <= 18; i++) {
            for (int d = 1; d < 10; d++) {
                long long y = num(i, d, 0, d);
                if (y >= x && (ans == -1 || y < ans)) {
                    ans = y;
                }
            }
        }
    } else {
        for (int i = 1; i <= 18; i++) {
            for (int d = 0; d < 10; d++) {
                for (int p = 0; p < i; p++) {
                    for (int d2 = 0; d2 < 10; d2++) {
                        long long y = num(i, d, p, d2);
                        if (y >= x && (ans == -1 || y < ans)) {
                            ans = y;
                        }
                    }
                }
            }
        }
    }

    cout << ans << endl;
}
