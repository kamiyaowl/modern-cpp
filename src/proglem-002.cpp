#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;
using namespace std;

void solve(mp::cpp_int a, mp::cpp_int b) {
    auto result = boost::math::gcd(a, b);
    cout << result << endl;
}

int main(void){
    mp::cpp_int a,b;
    cin >> a >> b;
    
    return 0;
}