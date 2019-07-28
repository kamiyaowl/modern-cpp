#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
constexpr vector<tuple<T,T>> zip(const vector<T>& vec1, const vector<T>& vec2) noexcept {
    vector<tuple<T,T>> dst;
    auto itr1 = vec1.begin();
    auto itr2 = vec2.begin();
    for(;
        itr1 != vec1.end() &&     itr2 != vec2.end() ;
        itr1++             ,     itr2++
    ) {
        dst.push_back(std::make_tuple(*itr1, *itr2));
    }
    return dst;
}
int main(void) {
    vector<int> vec1 = {1,2,3};
    vector<int> vec2 = {4,5,6,10};
    auto dst = zip(vec1, vec2);

    for(const auto [a,b]: dst) {
        cout << "{ " <<  a << ", " << b << "}, ";
    }
    cout << endl;
    // { 1, 4}, { 2, 5}, { 3, 6}, 
    
    return 0;
}
