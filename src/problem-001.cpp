#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;
using namespace std;

void solve(mp::cpp_int n) {
    mp::cpp_int sum = 0;
    for(mp::cpp_int i = 3 ; i < n ; ++i) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    cout << sum << endl;
}
int main(void){
    mp::cpp_int n;
    cin >> n;
    solve(n);

    return 0;
}