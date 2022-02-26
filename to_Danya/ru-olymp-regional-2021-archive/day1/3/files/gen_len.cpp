#include "testlib.h"
#include <iostream>

using namespace std;

int cnt(int x) {
	if (x == 1)
		return 0;
	int ans = 0;
	while (x) {
		x /= 10;
		ans++;
	}
	return ans;
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int delta[] = {0, 1, 9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999};
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    vector<int> mas;
    int len = cnt(m) + 1;
    mas.push_back(m);
    while (len < n) {
    	int t = min(n - len, 10);
    	int i = rnd.next(0, (int)mas.size() - 1);
    	if (mas[i] > 1) {
	    	int x = rnd.next(1, min(mas[i] - 1, delta[t]));
	    	len -= cnt(mas[i]);
	    	len += cnt(x);
	    	len += cnt(mas[i] - x);
	    	len++;
	    	mas[i] -= x;
	    	mas.push_back(x);
	    }
    }
    shuffle(mas.begin(), mas.end());
    string kek = "ACGT";
    int last = -1;
    for (int i = 0; i < (int)mas.size(); i++) {
    	int x = 0;
    	do {
    		x = rnd.next(0, 3);
    	} while (x == last);
    	if (mas[i] > 1)
    		cout << mas[i];
    	cout << kek[x];
    	last = x;
    }
    cout << endl;
}