#include <iostream>
#include <list>
#include <algorithm> // any_of
#include <iomanip>   // setprecision (опційно)

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::list<double> a;
    for (int i = 0; i < n; ++i) {
        double x;
        std::cin >> x;
        a.push_back(x);
    }

    const bool hasLessThanMinus3 = std::any_of(a.begin(), a.end(),
        [](double v) { return v < -3.0; });

    if (hasLessThanMinus3) {
        for (double &v : a) {
            if (v < 0.0) v = v * v;   // замінюємо від’ємні на квадрати
        }
    } else {
        for (double &v : a) {
            v *= 0.1;                 // множимо всі на 0.1
        }
    }

    // Вивід у зворотному порядку: an, an-1, ..., a1
    // (можна налаштувати формат — опційно)
    // std::cout << std::fixed << std::setprecision(6);

    bool first = true;
    for (auto it = a.rbegin(); it != a.rend(); ++it) {
        if (!first) std::cout << ' ';
        std::cout << *it;
        first = false;
    }
    std::cout << "\n";

    return 0;
}