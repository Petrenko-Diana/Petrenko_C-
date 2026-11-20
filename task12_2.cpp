#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<unsigned long long> numbers(n);
    char digit;
    
    cout << "Enter " << 10 * n << " digits: ";
    
    for (int i = 0; i < n; ++i) {
        unsigned long long num = 0;
        for (int j = 0; j < 10; ++j) {
            cin >> digit;
            num = num * 10 + (digit - '0');
        }
        numbers[i] = num;
    }

    unsigned long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += numbers[i];
    }

    cout << "Sum: " << sum << endl;

    return 0;
}