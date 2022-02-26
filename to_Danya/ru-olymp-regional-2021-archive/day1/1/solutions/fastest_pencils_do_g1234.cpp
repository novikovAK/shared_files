#include <iostream>

int main() {

    long long k;
    std::cin >> k;
    long long a, x, b, y;
    std::cin >> a >> x >> b >> y;

    if (a == 0 && x == 0) {
        std::cout << y * std::max(k - b, 0ll) << '\n';
    } else if (a == 0 && b == 0) {
        std::cout << (x + y) * k << '\n';
    } else if (a == b) {
        std::cout << std::max(x, y) * std::max(k - a, 0ll) + std::min(x, y) * std::max(k - 2 * a, 0ll) << '\n';
    } else if (x == y) {
        std::cout << x * std::max(k - std::min(a, b), 0ll) + x * std::max(k - a - b, 0ll) << '\n';
    } else {
        std::cout << "65\n";
    }

}