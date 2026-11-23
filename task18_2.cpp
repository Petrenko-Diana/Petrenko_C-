#include <iostream>
#include <vector>
#include <stack>

namespace MyNamespace {

template <typename T>
class MyStack {
private:
    std::vector<T> data;

public:
    void push(const T& value) {
        data.push_back(value);
    }

    void pop() {
        if (!data.empty()) {
            data.pop_back();
        }
    }

    T top() const {
        return data.back();
    }

    bool empty() const {
        return data.empty();
    }

    size_t size() const {
        return data.size();
    }
};

int readUntilZero(std::vector<int>& outArray) {
    int val;
    outArray.clear();
    std::cout << "Enter integers (0 to stop):\n";
    while (std::cin >> val && val != 0) {
        outArray.push_back(val);
    }
    return static_cast<int>(outArray.size());
}

}

int main() {
    std::cout << "Custom Stack\n";

    std::vector<int> numbers;
    int count = MyNamespace::readUntilZero(numbers);
    
    std::cout << "Read " << count << " elements.\n";

    MyNamespace::MyStack<int> customStack;
    std::stack<int> stlStack;

    for (int n : numbers) {
        customStack.push(n);
        stlStack.push(n);
    }

    std::cout << "Custom Stack top: " << customStack.top() << "\n";
    std::cout << "STL Stack top: " << stlStack.top() << "\n";

    std::cout << "Popping all elements from Custom Stack: ";
    while (!customStack.empty()) {
        std::cout << customStack.top() << " ";
        customStack.pop();
    }
    std::cout << "\n";

    return 0;
}