#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    int n;
    std::cout << "Enter number of customers (n): ";
    std::cin >> n;

    if (n <= 0) return 0;

    std::vector<double> t(n);
    std::cout << "Enter service times for each customer:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> t[i];
    }

    std::vector<double> c(n);
    double current_time = 0.0;
    
    for (int i = 0; i < n; ++i) {
        double arrival_time = i * 1.0; 
        if (current_time < arrival_time) {
            current_time = arrival_time;
        }
        current_time += t[i];
        c[i] = current_time - arrival_time;
    }

    std::cout << "\nTime spent in queue (c_i):\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "Customer " << i + 1 << ": " << c[i] << " min\n";
    }

    int min_service_idx = 0;
    int max_wait_idx = 0;

    for (int i = 1; i < n; ++i) {
        if (t[i] < t[min_service_idx]) {
            min_service_idx = i;
        }
        if (c[i] > c[max_wait_idx]) {
            max_wait_idx = i;
        }
    }

    std::cout << "\nCustomer with minimum service time: " << min_service_idx + 1 << " (Time: " << t[min_service_idx] << ")\n";
    std::cout << "Customer who waited the longest: " << max_wait_idx + 1 << " (Wait: " << c[max_wait_idx] << ")\n";

    return 0;
}