#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    int* m = new int[n];
    cout << "Enter " << n << " integer numbers (m_i): ";
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
    }

    ofstream outFile("input.txt");
    if (!outFile) {
        cerr << "Error creating file." << endl;
        delete[] m;
        return 1;
    }
    
    cout << "Enter " << n << " real numbers (x_i): ";
    for (int i = 0; i < n; ++i) {
        double x;
        cin >> x;
        outFile << x << " ";
    }
    outFile.close();

    ifstream inFile("input.txt");
    if (!inFile) {
        cerr << "Error opening file." << endl;
        delete[] m;
        return 1;
    }

    vector<double> x(n);
    for (int i = 0; i < n; ++i) {
        if (!(inFile >> x[i])) {
            cerr << "Error reading from file or file is corrupted." << endl;
            inFile.close();
            delete[] m;
            return 1;
        }
    }
    inFile.close();

    ofstream resFile("output.txt");
    if (!resFile) {
        cerr << "Error creating output file." << endl;
        delete[] m;
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        double result = pow(x[i], m[i]);
        resFile << result << " ";
        cout << result << " ";
    }
    cout << endl;
    resFile.close();

    delete[] m;

    return 0;
}