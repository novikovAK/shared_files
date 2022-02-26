#include "testlib.h"
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    int t = stoi(argv[1]);
    int n1 = stoi(argv[2]);
    int m1 = stoi(argv[3]);
    int n = n1;
    int m = m1;
    cout << t << endl;
    if (t == n * m) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << i << " " << j << endl;
            }
        } 
    } else {
        for (int i = 0; i < t; i++) {
            cout << n << " " << m << endl;
            n = rnd.next(1, n1);
            m = rnd.next(1, m1);
        }
    }
    return 0;
}
