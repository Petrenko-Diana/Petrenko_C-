#include <iostream>
#include <vector>
#include <cmath>

class Point {
private:
    double x;
    double y;
    static int point_count;

public:
    Point(double x_val = 0.0, double y_val = 0.0) : x(x_val), y(y_val) {
        point_count++;
    }

    ~Point() {
        point_count--;
    }

    static void counter() {
        std::cout << "Current number of points: " << point_count << "\n";
    }

    double distanceTo(const Point& other) const {
        return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
    }
    
    void input() {
        std::cout << "Enter X coordinate: ";
        std::cin >> x;
        std::cout << "Enter Y coordinate: ";
        std::cin >> y;
    }
};

int Point::point_count = 0;

int main() {
    std::vector<Point> polygon;
    char answer;

    std::cout << "=== Polygon Creation ===\n";

    do {
        Point p;
        p.input();
        polygon.push_back(p);

        std::cout << "Add another vertex? (Y/N): ";
        std::cin >> answer;
    } while (answer == 'Y' || answer == 'y');

    Point::counter();

    if (polygon.size() < 2) {
        std::cout << "At least 2 vertices are required for a perimeter.\n";
    } else {
        double perimeter = 0.0;
        for (size_t i = 0; i < polygon.size(); ++i) {
            perimeter += polygon[i].distanceTo(polygon[(i + 1) % polygon.size()]);
        }
        std::cout << "Polygon perimeter: " << perimeter << "\n";
    }

    return 0;
}