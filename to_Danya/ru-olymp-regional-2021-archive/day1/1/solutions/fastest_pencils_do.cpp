#include <iostream>

long long count(long long k, long long a, long long x, long long b, long long y) {
    long long first = a <= k ? k - a : 0L;
    long long second = a + b <= k ? k - a - b : 0L;
    return first * x + second * y;
}

int main() {

    long long k;
    std::cin >> k;
    long long a, x, b, y;
    std::cin >> a >> x >> b >> y;

    std::cout << std::max(
            count(k, a, x, b, y),
            count(k, b, y, a, x)
    ) << '\n';

}