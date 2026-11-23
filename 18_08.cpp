#include <iostream>
#include <utility>
#include <string>
#include <vector>

template <typename T>
class Interval {
private:
    std::pair<T, T> bounds;
    bool left_inclusive;
    bool right_inclusive;

public:
    Interval(T left, T right, bool l_inc, bool r_inc) 
        : bounds(left, right), left_inclusive(l_inc), right_inclusive(r_inc) {}

    bool isEmpty() const {
        if (bounds.first == bounds.second) {
            return !(left_inclusive && right_inclusive);
        }
        return bounds.first > bounds.second;
    }

    void print() const {
        std::cout << (left_inclusive ? "[" : "(") 
                  << bounds.first << ", " << bounds.second 
                  << (right_inclusive ? "]" : ")");
    }

    bool intersects(const Interval<T>& other) const {
        if (isEmpty() || other.isEmpty()) return false;

        if (bounds.second < other.bounds.first || other.bounds.second < bounds.first) {
            return false;
        }

        if (bounds.second == other.bounds.first) {
            return right_inclusive && other.left_inclusive;
        }
        if (other.bounds.second == bounds.first) {
            return other.right_inclusive && left_inclusive;
        }

        return true;
    }

    Interval<T> intersection(const Interval<T>& other) const {
        if (!intersects(other)) {
            return Interval<T>(T(), T(), false, false);
        }

        T new_left = (bounds.first > other.bounds.first) ? bounds.first : other.bounds.first;
        T new_right = (bounds.second < other.bounds.second) ? bounds.second : other.bounds.second;

        bool new_l_inc = (bounds.first == other.bounds.first) ? (left_inclusive && other.left_inclusive) : 
                         (bounds.first > other.bounds.first ? left_inclusive : other.left_inclusive);
        bool new_r_inc = (bounds.second == other.bounds.second) ? (right_inclusive && other.right_inclusive) : 
                         (bounds.second < other.bounds.second ? right_inclusive : other.right_inclusive);

        return Interval<T>(new_left, new_right, new_l_inc, new_r_inc);
    }

    Interval<T> unite(const Interval<T>& other) const {
        if (!intersects(other)) {
            return Interval<T>(T(), T(), false, false);
        }

        T new_left = (bounds.first < other.bounds.first) ? bounds.first : other.bounds.first;
        T new_right = (bounds.second > other.bounds.second) ? bounds.second : other.bounds.second;

        bool new_l_inc = (bounds.first == other.bounds.first) ? (left_inclusive || other.left_inclusive) : 
                         (bounds.first < other.bounds.first ? left_inclusive : other.left_inclusive);
        bool new_r_inc = (bounds.second == other.bounds.second) ? (right_inclusive || other.right_inclusive) : 
                         (bounds.second > other.bounds.second ? right_inclusive : other.right_inclusive);

        return Interval<T>(new_left, new_right, new_l_inc, new_r_inc);
    }
};

int main() {
    std::cout << "=== Interval Operations ===\n";

    Interval<double> i1(1.0, 5.0, true, false);
    Interval<double> i2(4.0, 7.0, true, true);
    Interval<double> i3(6.0, 8.0, true, true);

    std::cout << "i1 = "; i1.print(); std::cout << "\n";
    std::cout << "i2 = "; i2.print(); std::cout << "\n";
    std::cout << "i3 = "; i3.print(); std::cout << "\n\n";

    std::cout << "i1 intersects i2: " << (i1.intersects(i2) ? "Yes" : "No") << "\n";
    std::cout << "i1 intersects i3: " << (i1.intersects(i3) ? "Yes" : "No") << "\n\n";

    std::cout << "Intersection of i1 and i2: ";
    i1.intersection(i2).print();
    std::cout << "\n";

    std::cout << "Union of i1 and i2: ";
    i1.unite(i2).print();
    std::cout << "\n\n";

    std::cout << "Finding Common Intersection for Array\n";
    std::vector<Interval<double>> intervals = {
        Interval<double>(1.0, 10.0, true, true),
        Interval<double>(3.0, 7.0, true, true),
        Interval<double>(5.0, 8.0, true, true),
        Interval<double>(2.0, 6.0, true, true)
    };

    std::cout << "Intervals:\n";
    for (const auto& inv : intervals) {
        inv.print();
        std::cout << "\n";
    }

    Interval<double> common = intervals[0];
    for (size_t i = 1; i < intervals.size(); ++i) {
        common = common.intersection(intervals[i]);
        if (common.isEmpty()) {
            std::cout << "\nNo common intersection for all intervals.\n";
            return 0;
        }
    }

    std::cout << "\nCommon intersection: ";
    common.print();
    std::cout << "\n";

    return 0;
}