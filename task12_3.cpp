#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "+";
    for (int i = 0; i < n * 8; ++i) cout << "-";
    cout << "+" << endl;

    for (int i = 1; i <= n; ++i) {
        cout << setw(8) << i;
    }
    cout << endl;

    cout << "+";
    for (int i = 0; i < n * 8; ++i) cout << "-";
    cout << "+" << endl;

    for (int i = 1; i <= n; ++i) {
        double root = sqrt(i);
        double rounded = round(root * 100) / 100;
        
        cout << setw(8) << fixed;
        if (rounded == floor(rounded)) {
            cout << setprecision(0);
        } else {
            cout << setprecision(2);
        }
        cout << root;
    }
    cout << endl;

    cout << "+";
    for (int i = 0; i < n * 8; ++i) cout << "-";
    cout << "+" << endl;

    return 0;
}