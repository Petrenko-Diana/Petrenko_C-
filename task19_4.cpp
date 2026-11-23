#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

int main() {
    int n, m;
    std::cout << "Enter rows (n) and columns (m): ";
    std::cin >> n >> m;

    std::vector<std::list<int>> matrix(n);

    std::cout << "Enter matrix elements:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int val;
            std::cin >> val;
            matrix[i].push_back(val);
        }
    }

    for (int i = 0; i < n; ++i) {
        matrix[i].sort();
    }

    std::sort(matrix.begin(), matrix.end(), [](const std::list<int>& a, const std::list<int>& b) {
        return a.back() > b.back();
    });

    std::cout << "\nMatrix after sorting rows by max element:\n";
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }

    return 0;
}