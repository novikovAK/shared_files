#include "testlib.h"

using namespace std;

int maxm[7] = {100, 1, 1, 100, 100, 100, 100};
int maxd[7] = {100, 1, 100, 100, 100, 100, 100};
int maxi[7] = {100, 100, 100, 1, 100, 100, 100};
int maxk[7] = {10000, 1000000000, 10000000, 1000000000, 1, 100, 1000000000};

int main(int argc, char** argv)
{
    registerValidation(argc, argv);
    int g = validator.group() == "" ? 6 : validator.group()[0] - '0';

    int d = inf.readInt(1, maxd[g], "d");
    inf.readSpace();
    int m = inf.readInt(1, maxm[g], "m");
    inf.readSpace();
    int w = inf.readInt(1, 26, "w");
    inf.readEoln();
    int i = inf.readInt(1, min(maxi[g], d), "i");
    inf.readSpace();
    int j = inf.readInt(1, min(maxi[g], m), "j");
    inf.readSpace();
    int k = inf.readInt(1, maxk[g], "k");
    inf.readEoln();
    inf.readEof();

    return 0;
}
