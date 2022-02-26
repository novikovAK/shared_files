#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {

    registerGen(argc, argv, 1);

    int k = atoi(argv[1]);
    int ab = atoi(argv[2]), x = atoi(argv[3]), y = atoi(argv[4]);

    println(rnd.next(0, k));
    int ab_t = rnd.next(0, ab);
    println(ab_t, rnd.next(0, x));
    println(ab_t, rnd.next(0, y));

}