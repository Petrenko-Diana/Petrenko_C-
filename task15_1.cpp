#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

class Rational {
private:
    long long numerator;
    long long denominator;

    void simplify() {
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
        long long gcd_val = std::gcd(std::abs(numerator), denominator);
        numerator /= gcd_val;
        denominator /= gcd_val;
    }

public:
    Rational() : numerator(0), denominator(1) {}

    Rational(long long num, long long den) {
        if (den == 0) {
            std::cerr << "Error: denominator cannot be zero. Set to 1.\n";
            den = 1;
        }
        numerator = num;
        denominator = den;
        simplify();
    }

    void input() {
        std::cout << "Enter numerator: ";
        std::cin >> numerator;
        std::cout << "Enter denominator: ";
        std::cin >> denominator;
        if (denominator == 0) {
            std::cerr << "Error: denominator cannot be zero. Set to 1.\n";
            denominator = 1;
        }
        simplify();
    }

    void print() const {
        std::cout << numerator << "/" << denominator;
    }

    Rational operator+(const Rational& other) const {
        return Rational(numerator * other.denominator + other.numerator * denominator,
                        denominator * other.denominator);
    }

    Rational operator*(const Rational& other) const {
        return Rational(numerator * other.numerator, denominator * other.denominator);
    }

    bool operator<(const Rational& other) const {
        return (numerator * other.denominator) < (other.numerator * denominator);
    }
};

void findMinimum() {
    std::cout << "\n--- Find Minimum ---\n";
    std::vector<Rational> arr;
    int n;
    std::cout << "How many numbers to enter? ";
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cout << "Number " << i + 1 << ":\n";
        Rational r;
        r.input();
        arr.push_back(r);
    }
    
    if (arr.empty()) return;

    Rational min_val = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }
    std::cout << "Minimum number: ";
    min_val.print();
    std::cout << "\n";
}

void calculateSeries() {
    std::cout << "\n--- Series Calculation ---\n";
    double sum = 0.0;
    double term = 1.0;
    int n = 1;
    double epsilon = 0.01; 
    
    while (std::abs(term) >= epsilon) {
        term = 1.0 / (n * n);
        if (n % 2 == 0) {
            sum -= term;
        } else {
            sum += term;
        }
        n++;
    }
    
    double target = (M_PI * M_PI) / 12.0;
    std::cout << "Calculated sum: " << sum << "\n";
    std::cout << "Reference value (pi^2/12): " << target << "\n";
    std::cout << "Difference: " << std::abs(sum - target) << "\n";
}

int main() {
    std::cout << "=== Rational Class Testing ===\n";
    
    Rational a(1, 2);
    Rational b(1, 3);
    
    std::cout << "a = "; a.print(); std::cout << "\n";
    std::cout << "b = "; b.print(); std::cout << "\n";
    
    std::cout << "a + b = "; (a + b).print(); std::cout << "\n";
    std::cout << "a * b = "; (a * b).print(); std::cout << "\n";
    
    findMinimum();
    calculateSeries();

    return 0;
}