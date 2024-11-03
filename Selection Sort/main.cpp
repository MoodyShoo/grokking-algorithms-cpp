#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
ostream& operator<<(ostream& out, const vector<T>& vec) {
    for (const auto& elem : vec) {
        out << elem << ' ';
    }
    out << endl;

    return out;
}

template <typename T>
vector<T> SelectionSort(vector<T>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        auto offset_begin = arr.begin() + static_cast<int>(i);

        auto min = min_element(offset_begin, arr.end());

        if (min != offset_begin) {
            std::swap(*min, arr[i]);
        }
    }

    return arr;
}

int main() {
    vector<int> arr{5, 3, 6, 2, 10, 15, 8, 1};
    cout << SelectionSort(arr);
}