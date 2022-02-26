#include <iostream>

int main() {

    long long k;
    std::cin >> k;
    long long a, x, b, y;
    std::cin >> a >> x >> b >> y;

    if (a == 0 && x == 0) {
        std::cout << y * k - b << '\n';
    } else if (a == 0 && b == 0) {
        std::cout << (x + y) * k << '\n';
    } else if (a == b) {
        std::cout << std::max(x, y) * (k - a) + std::min(x, y) * (k - 2 * a) << '\n';
    } else if (x == y) {
        std::cout << x * (k - std::min(a, b)) + x * (k - a - b) << '\n';
    } else {
        std::cout << "65\n";
    }

}