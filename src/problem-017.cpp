#include <iostream>
#include <array>
#include <iterator>
#include <algorithm>

using namespace std;

template<typename T, size_t ROW_N, size_t COL_N>
class array2d {
    array<array<T, COL_N>, ROW_N> data;
public:
    array2d() {}

    T at(size_t r, size_t c) {
        return data[r][c];
    }
    void fill(const T src){
        for(auto& row: data) {
            row.fill(src);
        }
    }
    void swap(array2d<T, ROW_N, COL_N>& target) {
        std::swap(this->data, target.data);
    }
    T operator()(size_t r, size_t c) {
        return at(r,c);
    }
    auto begin() {
        return this->data.begin();
    }
    auto end() {
        return this->data.end();
    }
};

int main() {
    // initializer list
    array2d<int, 2, 3> arr; 
    // indexer access
    cout << arr(1,1) << endl;
    // iterator
    for(const auto& row: arr) {
        for(const auto& item : row) {
            cout << item << endl;
        }
    }
    array2d<int, 2, 3> arr2;
    arr2.fill(0xff);
    // swap
    arr.swap(arr2);
    // move
    array2d<int, 2, 3> arr3(std::move(arr)); 

    // 0xffnfillがでてくればせいかい
    for(const auto& row: arr3) {
        for(const auto& item : row) {
            cout << item << endl;
        }
    }

}

