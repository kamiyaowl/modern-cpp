#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <map>

namespace mp = boost::multiprecision;
using namespace std;

// 遅いのでメモ化再帰
map<mp::cpp_int, mp::cpp_int> memo { {1, 1} };
mp::cpp_int collatz_len(mp::cpp_int n) { 
    if (memo.count(n)) { return memo[n]; }
    auto result = 1 + ((n % 2 == 0) ? collatz_len(n / 2) : collatz_len(3 * n + 1));
    memo[n] = result;
    return result;
}

template<typename T>
void solve(T n) {
    T max_index = -1;
    T max_length = 0;
    for(T i = 1 ; i < n; ++i) {
        auto len = collatz_len(i);
        if(max_length < len) {
            max_length = len;
            max_index = i;
        }
    }
    cout << max_index << "\tlen:" << max_length << endl;
}
int main(void){
    solve<mp::cpp_int>(1000000); // 実行結果/ 37799  len:525
    
    return 0;
}