#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string filePath = "C:\\Users\\user\\Desktop\\MyProjectsC.C\\14_c+h\\task1.txt";
    ifstream file(filePath);

    if (!file.is_open()) {
        cerr << "Error opening file: " << filePath << endl;
        return 1;
    }

    string expr;
    getline(file, expr);
    file.close();

    long long total = 0;
    long long currentNumber = 0;
    int sign = 1;
    bool inNumber = false;

    for (size_t i = 0; i < expr.length(); ++i) {
        char c = expr[i];
        if (isdigit(c)) {
            currentNumber = currentNumber * 10 + (c - '0');
            inNumber = true;
        } else if (c == '+' || c == '-') {
            if (inNumber) {
                total += sign * currentNumber;
                currentNumber = 0;
                inNumber = false;
            }
            sign = (c == '+') ? 1 : -1;
        }
    }
    
    if (inNumber) {
        total += sign * currentNumber;
    }

    cout << "Expression: " << expr << endl;
    cout << "Result: " << total << endl;

    return 0;
}