#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {

    registerGen(argc, argv, 1);

    int k = atoi(argv[1]);
    int a = atoi(argv[2]), x = atoi(argv[3]);
    int b = atoi(argv[4]), y = atoi(argv[5]);

    println(rnd.next(0, k));
    println(rnd.next(0, a), rnd.next(0, x));
    println(rnd.next(0, b), rnd.next(0, y));

}