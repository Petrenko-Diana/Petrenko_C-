#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double x, y;
    
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;

    double result = pow(x, y);

    cout << "Decimal: " << fixed << setprecision(4) << result << endl;
    cout << "Scientific: " << scientific << setprecision(4) << result << endl;

    return 0;
}