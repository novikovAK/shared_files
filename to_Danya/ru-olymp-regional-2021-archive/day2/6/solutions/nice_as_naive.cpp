#include <bits/stdc++.h>
using namespace std;

bool good(long long x, int k) {
    vector<int> cnt(10);
    while (x > 0) {
        int d = x % 10;
        cnt[d]++;
        x /= 10;
    }

    int ge1 = 0;
    int ge2 = 0;
    for (int i = 0; i < 10; i++) {
        if (cnt[i] > 0) {
            ge1++;
        }
        if (cnt[i] > 1) {
            ge2++;
        }
    }
    return (ge2 <= 1) && (ge1 <= 1 + k);
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
