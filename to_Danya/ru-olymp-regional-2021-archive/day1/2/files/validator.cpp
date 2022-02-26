#include "testlib.h"

const int MAXT[] = {
    10,           // sample
    1,            // 1
    1,            // 2
    10,           // 3
    2000,         // 4
    100000,       // 5
    100000        // 6
};


const long long MAXNM[] = {
    100,          // sample
    100,          // 1
    2000,         // 2
    10000000,     // 3
    10000,        // 4
    1000000000,   // 5
    1000000000    // 6
};

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    auto gr = validator.group().empty() ? 0 : validator.group()[0] - '0';

    int t = inf.readInt(1ll, MAXT[gr], "t");
    inf.readEoln();
    for (int i = 0; i < t; i++) {
        long long n = inf.readLong(1ll, MAXNM[gr], "n");
        inf.readSpace();
        long long m = inf.readLong(1ll, MAXNM[gr], "m");
        ensuref(n * m >= 2, "not 1 x 1");
        if (gr == 4) {
            ensuref(n * m <= MAXNM[gr], "group 4");
        }
        ensuref(n * m <= 1e9, "nm");
        if (gr == 5) {
            ensuref(n == 1, "group 5");
        }
        inf.readEoln();
    }
    inf.readEof();
    return 0;
}
