#include <iostream>
#include <set>
#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;
using namespace std;

template<typename T>
T divisor_sum(T n) {
    auto sum = n; // その数自信は先に足す
    auto end = n / 2;
    for(auto i = 1 ; i <= end ; ++i) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum;
}

template<typename T>
void solve(T n) {
    set<T> detected;
    for(T i = 2 ; i < n ; ++i) {
        if (detected.count(i)) continue; // すでにペアを探索済

        auto x = divisor_sum(i) - i;
        if (i == x) continue; // x == iの場合、ペアにならない

        auto y = divisor_sum(x) - x;
        if (i == y) {
            cout << i << "," << x << endl;
            detected.insert(i);
            detected.insert(x);
        }
    }
}

int main(void){
    solve(1000000UL + 1UL);
    
    return 0;
}