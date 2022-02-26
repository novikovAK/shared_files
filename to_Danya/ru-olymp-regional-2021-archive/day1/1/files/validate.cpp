#include <string>
#include "testlib.h"

using namespace std;

constexpr int limit = 1000'000'000;

pair<int, int> read_pencil(std::string f, std::string s) {
    int a = inf.readInt(0, limit, f);
    inf.readSpace();
    int x = inf.readInt(0, limit, s);
    inf.readEoln();
    return {a, x};
}

int main(int argc, char *argv[]) {

    registerValidation(argc, argv);
    int g = validator.group() == "" ? 5 : validator.group()[0] - '0';

    inf.readInt(0, limit, "k");
    inf.readEoln();
    auto ax = read_pencil("a", "x");
    auto by = read_pencil("b", "y");
    
    if (g == 1) {
        ensuref(ax.first == 0 && ax.second == 0, "Group 1 condition failed");
    } else if (g == 2) {
        ensuref(ax.first == 0 && by.first == 0, "Group 2 condition failed");
    } else if (g == 3) {
        ensuref(ax.first == by.first, "Group 3 condition failed");
    } else if (g == 4) {
        ensuref(ax.second == by.second, "Group 4 condition failed");
    }

    inf.readEof();

}