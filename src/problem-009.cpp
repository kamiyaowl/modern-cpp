#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;
using namespace std;

template<typename T>
void solve(const T n, vector<T>& ret) {
    for(T i = 2 ; i < n / 2 ; ++i) {
        if(n % i == 0) {
            ret.push_back(i);
            solve<T>(n / i, ret);
            return;
        }
    }
    // もう無い場合
    ret.push_back(n);
    return;
}

int main(void){
    mp::cpp_int n;
    cin >> n;
    vector<mp::cpp_int> result;
    solve<mp::cpp_int>(n, result);

    for(const auto& r: result) {
        cout << r << endl;
    }
    return 0;
}