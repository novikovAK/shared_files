#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int MAX_L[] = {100, 10, 100, 1000, (int)1e5, (int)1e5};
int MAX_BIG_L[] = {100, 10, (int)1e4, (int)1e5, (int)1e7, (int)1e9};

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int gr = 0;
    if (!validator.group().empty()) {
        gr = atoi(validator.group().c_str());
    }
    string regex = "[0-9ACGT]{" + to_string(1) + ", " + to_string(MAX_L[gr]) + "}";
    string s = inf.readToken(regex, "s");
    inf.readEoln();
    int sum = 0;
    char last = 'B';
    for (int i = 0; i < (int)s.size(); i++) {
    	if ('0' <= s[i] && s[i] <= '9') {
    		long long x = 0;
    		while ('0' <= s[i] && s[i] <= '9') {
    			x = 10 * x + s[i] - '0';
    			ensuref(x <= (long long)MAX_BIG_L[gr], "too big number");
    			i++;
    		}
    		ensuref(last != s[i], "same letter");
    		sum += x;
    		last = s[i];
    	} else {
    		ensuref(last != s[i], "same letter");
    		last = s[i];
    		sum++;
    	}
    	ensuref(sum <= MAX_BIG_L[gr], "too long string");
    }
    inf.readEof();
}