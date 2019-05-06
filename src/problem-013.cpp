#include <iostream>
#include <stdint.h>
#include <random>

using namespace std;

double mcs_pi(int n) {
    random_device rnd; // 32bit:0x0 ~ 0xffffffff
    int hit = 0;
    for(int i = 0 ; i < n ; ++i) {
        double x = static_cast<uint32_t>(rnd()) / static_cast<double>(0xffffffff);
        double y = static_cast<uint32_t>(rnd()) / static_cast<double>(0xffffffff);
        if(x * x + y * y <= 1) { ++hit; }
    }
    return 4.0 * hit / static_cast<double>(n);
}
int main(void) {
    auto result = mcs_pi(1000000);
    cout << result << endl;
    return 0;
}