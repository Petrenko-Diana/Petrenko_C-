#include <iostream>
#include <list>

int main() {
    std::list<int> numbers;
    int val;

    std::cout << "Enter integers (enter any letter to stop):\n";
    while (std::cin >> val) {
        numbers.push_back(val);
    }

    std::cout << "Original list: ";
    for (int n : numbers) {
        std::cout << n << " ";
    }
    std::cout << "\n";

    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        if (*it != 0) {
            it = numbers.insert(it, -1);
            ++it; 
        }
        
        if (*it == 2) {
            auto next_it = std::next(it);
            numbers.insert(next_it, 0);
        }
    }

    std::cout << "Modified list: ";
    for (int n : numbers) {
        std::cout << n << " ";
    }
    std::cout << "\n";

    return 0;
}