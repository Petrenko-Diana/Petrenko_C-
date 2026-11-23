#include <iostream>
#include <fstream>
#include <cmath>

class Polynomial {
private:
    int degree;
    double* coeffs;

public:
    Polynomial(int n) {
        degree = (n > 0) ? n - 1 : 0;
        coeffs = new double[degree + 1];
        for (int i = 0; i <= degree; ++i) {
            coeffs[i] = 0.0;
        }
    }

    Polynomial(int n, const double* initial_coeffs) {
        degree = (n > 0) ? n - 1 : 0;
        coeffs = new double[degree + 1];
        for (int i = 0; i <= degree; ++i) {
            coeffs[i] = initial_coeffs[i];
        }
    }

    Polynomial(const Polynomial& other) {
        degree = other.degree;
        coeffs = new double[degree + 1];
        for (int i = 0; i <= degree; ++i) {
            coeffs[i] = other.coeffs[i];
        }
    }

    Polynomial& operator=(const Polynomial& other) {
        if (this != &other) {
            delete[] coeffs;
            degree = other.degree;
            coeffs = new double[degree + 1];
            for (int i = 0; i <= degree; ++i) {
                coeffs[i] = other.coeffs[i];
            }
        }
        return *this;
    }

    ~Polynomial() {
        delete[] coeffs;
    }

    void setCoefficient(int index, double value) {
        if (index >= 0 && index <= degree) {
            coeffs[index] = value;
        } else {
            std::cerr << "Error: index out of bounds.\n";
        }
    }

    void print() const {
        bool first = true;
        for (int i = degree; i >= 0; --i) {
            if (coeffs[i] == 0.0) continue;
            
            if (!first && coeffs[i] > 0.0) std::cout << " + ";
            else if (coeffs[i] < 0.0) std::cout << " - ";
            
            double abs_val = std::abs(coeffs[i]);
            if (abs_val != 1.0 || i == 0) std::cout << abs_val;
            
            if (i > 0) {
                std::cout << "x";
                if (i > 1) std::cout << "^" << i;
            }
            first = false;
        }
        if (first) std::cout << "0";
        std::cout << "\n";
    }

    friend void saveToBinary(const Polynomial& p, const char* filename);
    friend void loadFromBinary(Polynomial& p, const char* filename);
};

void saveToBinary(const Polynomial& p, const char* filename) {
    std::ofstream out(filename, std::ios::binary);
    if (!out) {
        std::cerr << "Error opening file for writing.\n";
        return;
    }
    out.write(reinterpret_cast<const char*>(&p.degree), sizeof(p.degree));
    out.write(reinterpret_cast<const char*>(p.coeffs), (p.degree + 1) * sizeof(double));
    out.close();
    std::cout << "Saved to " << filename << "\n";
}

void loadFromBinary(Polynomial& p, const char* filename) {
    std::ifstream in(filename, std::ios::binary);
    if (!in) {
        std::cerr << "Error opening file for reading.\n";
        return;
    }
    int new_degree;
    in.read(reinterpret_cast<char*>(&new_degree), sizeof(new_degree));
    
    delete[] p.coeffs;
    p.degree = new_degree;
    p.coeffs = new double[p.degree + 1];
    
    in.read(reinterpret_cast<char*>(p.coeffs), (p.degree + 1) * sizeof(double));
    in.close();
    std::cout << "Loaded from " << filename << "\n";
}

int main() {
    std::cout << "=== Polynomial Testing ===\n";
    
    double initial[] = {1.0, -3.0, 2.0}; 
    Polynomial p1(3, initial); 
    std::cout << "p1(x) = ";
    p1.print();

    Polynomial p2 = p1; 
    p2.setCoefficient(0, 5.0); 
    std::cout << "p2(x) = ";
    p2.print();

    std::cout << "\n--- Binary File I/O ---\n";
    saveToBinary(p2, "poly.bin");

    Polynomial p3(1);
    std::cout << "p3(x) initial = ";
    p3.print();
    
    loadFromBinary(p3, "poly.bin");
    std::cout << "p3(x) after load = ";
    p3.print();

    return 0;
}