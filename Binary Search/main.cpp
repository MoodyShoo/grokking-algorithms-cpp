#include <iostream>
#include <vector>

using namespace std;

template <typename T>
int BinarySearch(const vector<T>& vec, T target) {
    size_t left = 0;
    size_t right = vec.size() - 1;

    while (left <= right) {
        size_t mid = (left + right) / 2;
        T guess = vec[mid];

        if (guess > target) {
            right = mid - 1;
        } else if (guess < target) {
            left = mid + 1;
        } else {
            return static_cast<int>(mid);
        }
    }

    return -1;
}

int main() {
    // int
    vector<int> vec{1, 3, 5, 7, 9, 14, 20};
    cout << BinarySearch(vec, 5) << endl;

    // double
    vector<double> vec2{1.0, 1.5, 1.52, 1.9, 2.9, 2.90002};
    cout << BinarySearch(vec2, 2.9);
}