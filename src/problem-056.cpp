#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

template<typename T, typename U, typename F>
constexpr vector<U> select(const vector<T> src, F pred) noexcept {
    vector<T> dst;
    for(const auto& item: src) {
        dst.push_back(pred(item));
    }
    return dst;
}
int main(void) {
    vector<int> vec1 = {1,2,3,4,5};
    auto dst = select<int,int>(vec1, [](int x){ return x * 2; });

    for(const auto a: dst) {
        cout << a << ", ";
    }
    cout << endl;
    // 2, 4, 6, 8, 10, 
    
    return 0;
}
