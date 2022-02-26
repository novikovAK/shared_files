#include <bits/stdc++.h>
using namespace std;

int main() {
    int d, m, w;
    long long i, j, k;

    cin >> d >> m >> w >> i >> j >> k;

    long long day = (k - 1) * m * d + (j - 1) * d + (i - 1);
    char ans = 'a' + day % w;
    cout << ans << endl;
}
