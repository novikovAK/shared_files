#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = atoi(argv[1]);
    string kek = "ACGT";
    int last = -1;
    for (int i = 0; i < n; i++) {
    	int x = 0;
    	do {
    		x = rnd.next(0, 3);
    	} while (x == last);
    	cout << kek[x];
    	last = x;
    }
    cout << endl;
}