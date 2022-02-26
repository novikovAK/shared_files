#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {

    registerGen(argc, argv, 1);

    int k = atoi(argv[1]);
    int a = atoi(argv[2]), b = atoi(argv[3]), xy = atoi(argv[4]);

    println(rnd.next(0, k));
    int xy_t = rnd.next(0, xy);
    println(rnd.next(0, a), xy_t);
    println(rnd.next(0, b), xy_t);

}