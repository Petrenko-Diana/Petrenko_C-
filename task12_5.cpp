#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    string filePath = "C:\\Users\\user\\Desktop\\MyProjectsC.C\\12_c+h\\input.txt";
    
    ifstream inFile(filePath);
    
    if (!inFile.is_open()) {
        cerr << "Error: Cannot open file at " << filePath << endl;
        return 1;
    }

    vector<unsigned long long> numbers;
    unsigned long long num;

    while (inFile >> num) {
        numbers.push_back(num);
    }
    inFile.close();

    cout << fixed << setprecision(3);

    for (int i = numbers.size() - 1; i >= 0; --i) {
        double root = sqrt(static_cast<double>(numbers[i]));
        cout << root << endl;
    }

    return 0;
}