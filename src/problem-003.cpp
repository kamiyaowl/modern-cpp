#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;
using namespace std;

template<typename T>
T solve(T a, T b) {
    auto result = boost::math::lcm(a, b);
    return result;
}

int main(void){
    mp::cpp_int a,b;
    cin >> a >> b;
    auto result = solve(a,b);
    cout << result << endl;
    
    return 0;
}