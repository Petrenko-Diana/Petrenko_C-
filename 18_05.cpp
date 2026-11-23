//(є)

#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
class Array {
private:
    size_t size;
    T* data;

    void merge(T* arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        T* L = new T[n1];
        T* R = new T[n2];

        for (int i = 0; i < n1; i++) L[i] = arr[left + i];
        for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;

        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }

        delete[] L;
        delete[] R;
    }

    void mergeSortRecursive(T* arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSortRecursive(arr, left, mid);
            mergeSortRecursive(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }

public:
    Array(size_t s) : size(s) {
        data = new T[size];
    }

    ~Array() {
        delete[] data;
    }

    void set(size_t index, T value) {
        if (index < size) {
            data[index] = value;
        }
    }

    T get(size_t index) const {
        if (index < size) {
            return data[index];
        }
        throw std::out_of_range("Index out of bounds");
    }

    size_t getSize() const {
        return size;
    }

    void print() const {
        for (size_t i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << "\n";
    }

    void mergeSort() {
        if (size > 1) {
            mergeSortRecursive(data, 0, size - 1);
        }
    }

    static void mergeSort(T* arr, size_t n) {
        if (n > 1) {
            Array<T> temp(n);
            for (size_t i = 0; i < n; ++i) temp.set(i, arr[i]);
            temp.mergeSortRecursive(temp.data, 0, temp.size - 1);
            for (size_t i = 0; i < n; ++i) arr[i] = temp.get(i);
        }
    }
};

int main() {
    std::cout << "Binary Merge Sort\n";

    std::cout << "\nTesting non-static method\n";
    Array<int> arr1(8);
    int values1[] = {38, 27, 43, 3, 9, 82, 10, 1};
    for (int i = 0; i < 8; ++i) arr1.set(i, values1[i]);

    std::cout << "Original array: ";
    arr1.print();

    arr1.mergeSort();

    std::cout << "Sorted array:   ";
    arr1.print();

    std::cout << "\nTesting static method\n";
    double raw_arr[] = {3.14, 1.41, 2.71, 0.57, 1.61};
    size_t n = sizeof(raw_arr) / sizeof(raw_arr[0]);

    std::cout << "Original array: ";
    for (size_t i = 0; i < n; ++i) std::cout << raw_arr[i] << " ";
    std::cout << "\n";

    Array<double>::mergeSort(raw_arr, n);

    std::cout << "Sorted array:   ";
    for (size_t i = 0; i < n; ++i) std::cout << raw_arr[i] << " ";
    std::cout << "\n";

    return 0;
}