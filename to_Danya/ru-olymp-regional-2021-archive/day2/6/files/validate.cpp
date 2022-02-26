#include "testlib.h"

using namespace std;

long long maxx[5] = {1000, 100000, 100000000000000000LL, 100000, 100000000000000000LL};
long long maxk[5] = {1, 0, 0, 1, 1};

int main(int argc, char **argv)
{
    registerValidation(argc, argv);
    int g = validator.group() == "" ? 4 : validator.group()[0] - '0';

    long long x = inf.readLong(1, maxx[g], "x");
    inf.readEoln();
    int k = inf.readInt(0, maxk[g], "k");
    inf.readEoln();
    inf.readEof();

    return 0;
}
