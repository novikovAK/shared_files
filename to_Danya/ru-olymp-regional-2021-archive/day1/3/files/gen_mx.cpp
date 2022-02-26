#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = atoi(argv[1]);
    int mx = atoi(argv[2]);
    int q = atoi(argv[3]);
    string kek = "ACGT";
    vector<int> mas;
    if (mx > 0) {
	    mas.push_back(mx);
    	n -= mx;
    } else {
    	mx = n;
    }
    int cnt = 1;
    while (n) {
    	cerr << n << " " << mx << endl;
    	int x = rnd.next(1, min(n, mx));
    	mas.push_back(x);
    	n -= x;
    	cnt += (x > 4);
    }
    shuffle(mas.begin(), mas.end());
    int last = -1;
    int mem = rnd.next(1, 2 * cnt);
    if (q)
    	mem = 2 * cnt;
    for (int i = 0; i < (int)mas.size(); i++) {
    	int x = 0;
    	do {
    		x = rnd.next(0, 3);
    	} while (x == last);
    	if (mas[i] > 4) {
    		mem--;
    		if (mem == 0) {
    			int lol = rnd.next(2, mas[i] - 3);
    			int y = 0;
    			do {
    				y = rnd.next(0, 3);
    			} while (x == y);
    			cout << lol << kek[x] << kek[y] << mas[i] - lol - 1 << kek[x];
    			last = x;
    			continue;
    		}
    	}
    	if (mas[i] > 1)
    		cout << mas[i];
    	cout << kek[x];
    	last = x;
    }
    cout << endl;
}