#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int d, n;
    std::cout << "Enter dimension (d): ";
    std::cin >> d;
    std::cout << "Enter number of vectors (n): ";
    std::cin >> n;

    if (d <= 0 || n <= 0) return 0;

    std::vector<std::vector<double>> vectors(n, std::vector<double>(d));
    
    std::cout << "Enter " << n << " vectors of dimension " << d << ":\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < d; ++j) {
            std::cin >> vectors[i][j];
        }
    }

    double sum_of_norms = 0.0;

    for (int i = 0; i < n; ++i) {
        double sum_sq = 0.0;
        for (int j = 0; j < d; ++j) {
            sum_sq += vectors[i][j] * vectors[i][j];
        }
        double norm = std::sqrt(sum_sq);
        sum_of_norms += norm;
    }

    std::cout << "Sum of norms: " << sum_of_norms << "\n";

    return 0;
}