#include <iostream>
#include <string>
#include <numeric>

namespace MyNamespace {

class Rational {
private:
    long long num;
    long long den;

public:
    Rational(long long n, long long d) : num(n), den(d) {
        if (den == 0) den = 1;
    }

    bool operator<(const Rational& other) const {
        return (num * other.den) < (other.num * den);
    }

    friend std::ostream& operator<<(std::ostream& os, const Rational& r) {
        os << r.num << "/" << r.den;
        return os;
    }
};

template <typename T>
T findMax(T a, T b) {
    return (a < b) ? b : a;
}

}

int main() {
    std::cout << "Max Template\n";

    int i1 = 5, i2 = 10;
    std::cout << "Max(int): " << MyNamespace::findMax(i1, i2) << "\n";

    double d1 = 3.14, d2 = 2.71;
    std::cout << "Max(double): " << MyNamespace::findMax(d1, d2) << "\n";

    std::cout << "Max(string): " << MyNamespace::findMax(std::string("Apple"), std::string("Banana")) << "\n";

    MyNamespace::Rational r1(1, 2);
    MyNamespace::Rational r2(3, 4);
    std::cout << "Max(Rational): " << MyNamespace::findMax(r1, r2) << "\n";

    return 0;
}