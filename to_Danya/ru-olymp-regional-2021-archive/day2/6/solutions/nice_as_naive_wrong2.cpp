#include <bits/stdc++.h>
using namespace std;

bool good(long long x, int k) {
    int last = x % 10;
    int cnt = 0;
    while (x > 0) {
        int d = x % 10;
        x /= 10;
        if (d != last) {
            cnt++;
        }
        last = d;
    }

    return cnt <= k;
}

int main() {
    long long x;
    cin >> x;
    int k;
    cin >> k;

    while (!good(x, k)) {
        x++;
    }

    cout << x << endl;
}
