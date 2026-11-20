#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <cctype>

using namespace std;

bool isValidNumberPart(const string& s) {
    if (s.empty()) return false;
    for (char c : s) {
        if (!isdigit(c) && c != '+' && c != '-' && c != '.' && c != 'e' && c != 'E') {
            return false;
        }
    }
    return true;
}

int main() {
    string input;
    cout << "Enter string (e.g., A=123.45, B=1.2E3, C=45.6789):\n";
    getline(cin, input);

    size_t posA = input.find("A=");
    size_t posB = input.find("B=");
    size_t posC = input.find("C=");
    size_t posComma1 = input.find(',');
    size_t posComma2 = input.find(',', posComma1 + 1);

    if (posA == string::npos || posB == string::npos || posC == string::npos ||
        posComma1 == string::npos || posComma2 == string::npos) {
        cout << "Error: Invalid string format." << endl;
        return 1;
    }

    if (!(posA < posComma1 && posComma1 < posB && posB < posComma2 && posComma2 < posC)) {
        cout << "Error: Invalid string format." << endl;
        return 1;
    }

    string strA = input.substr(posA + 2, posComma1 - (posA + 2));
    string strB = input.substr(posB + 2, posComma2 - (posB + 2));
    string strC = input.substr(posC + 2);

    size_t endC = strC.find_last_not_of(" \t\r\n");
    if (endC != string::npos) {
        strC.erase(endC + 1);
    }

    while (!strA.empty() && isspace(strA.front())) strA.erase(0, 1);
    while (!strA.empty() && isspace(strA.back())) strA.pop_back();
    
    while (!strB.empty() && isspace(strB.front())) strB.erase(0, 1);
    while (!strB.empty() && isspace(strB.back())) strB.pop_back();

    if (!isValidNumberPart(strA) || !isValidNumberPart(strB) || !isValidNumberPart(strC)) {
        cout << "Error: Invalid characters in numbers." << endl;
        return 1;
    }

    try {
        double a = stod(strA);
        double b = stod(strB);
        double c = stod(strC);

        if (a == 0 || b == 0 || c == 0) {
            cout << "Error: Harmonic mean is impossible because one of the numbers is zero." << endl;
            return 0;
        }

        double denominator = (1.0 / a) + (1.0 / b) + (1.0 / c);

        if (denominator == 0) {
            cout << "Error: Harmonic mean is impossible (sum of inverses is zero)." << endl;
            return 0;
        }

        double harmonic_mean = 3.0 / denominator;

        cout << "Normal format:     " << fixed << setprecision(6) << harmonic_mean << endl;
        cout << "Scientific format: " << scientific << setprecision(6) << harmonic_mean << endl;

    } catch (const exception& e) {
        cout << "Error: Could not convert string to number." << endl;
    }

    return 0;
}