#include <iostream>
#include <list>
#include <cmath>
#include <numeric>

class Rational {
private:
    long long num, den;
public:
    Rational(long long n = 0, long long d = 1) : num(n), den(d) {
        if (den == 0) den = 1;
    }
    Rational operator+(const Rational& o) const { return Rational(num * o.den + o.num * den, den * o.den); }
    Rational operator*(const Rational& o) const { return Rational(num * o.num, den * o.den); }
    bool operator==(const Rational& o) const { return (num * o.den) == (o.num * den); }
    friend std::ostream& operator<<(std::ostream& os, const Rational& r) { os << r.num << "/" << r.den; return os; }
    friend std::istream& operator>>(std::istream& is, Rational& r) { is >> r.num >> r.den; return is; }
};

template <typename T>
class Polynomial {
private:
    std::list<T> coeffs;

public:
    void input(int degree) {
        coeffs.clear();
        std::cout << "Enter " << degree + 1 << " coefficients (from highest to lowest):\n";
        for (int i = 0; i <= degree; ++i) {
            T val;
            std::cin >> val;
            coeffs.push_back(val);
        }
    }

    void print() const {
        int degree = coeffs.size() - 1;
        bool first = true;
        for (const auto& c : coeffs) {
            if (!first) std::cout << " + ";
            std::cout << "(" << c << ")x^" << degree;
            degree--;
            first = false;
        }
        std::cout << "\n";
    }

    Polynomial<T> operator+(const Polynomial<T>& other) const {
        Polynomial<T> res;
        auto it1 = coeffs.rbegin();
        auto it2 = other.coeffs.rbegin();
        std::list<T> res_coeffs;
        
        while (it1 != coeffs.rend() || it2 != other.coeffs.rend()) {
            T c1 = (it1 != coeffs.rend()) ? *it1++ : T();
            T c2 = (it2 != other.coeffs.rend()) ? *it2++ : T();
            res_coeffs.push_front(c1 + c2);
        }
        res.coeffs = res_coeffs;
        return res;
    }

    T evaluate(T x) const {
        T result = T();
        int degree = coeffs.size() - 1;
        for (const auto& c : coeffs) {
            T term = c;
            for (int i = 0; i < degree; ++i) term = term * x;
            result = result + term;
            degree--;
        }
        return result;
    }
};

int main() {
    std::cout << "Polynomial with doubles\n";
    Polynomial<double> p1, p2;
    p1.input(2);
    p2.input(2);
    std::cout << "P1: "; p1.print();
    std::cout << "P2: "; p2.print();
    std::cout << "P1 + P2: "; (p1 + p2).print();
    std::cout << "P1(2.0) = " << p1.evaluate(2.0) << "\n";

    std::cout << "\nPolynomial with Rational\n";
    Polynomial<Rational> p3, p4;
    p3.input(1);
    p4.input(1);
    std::cout << "P3: "; p3.print();
    std::cout << "P4: "; p4.print();
    std::cout << "P3 + P4: "; (p3 + p4).print();

    return 0;
}