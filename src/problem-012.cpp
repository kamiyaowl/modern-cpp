#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;
using namespace std;

template<typename T>
T collatz_len(T n) { 
    T count;
    for(count = 1 ; n != 1 ; ++count) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
    }
    return count;
}

template<typename T>
void solve(T n) {
    T max_index = -1;
    T max_length = 0;
    for(T i = 1 ; i < n; ++i) {
        auto len = collatz_len<T>(i);
        if(max_length < len) {
            max_length = len;
            max_index = i;
        }
    }
    cout << max_index << "\tlen:" << max_length << endl;
}
int main(void){
    solve<mp::cpp_int>(1000000);
    
    return 0;
}