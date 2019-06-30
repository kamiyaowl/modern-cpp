#include <iostream>
#include <string>
#include <cmath>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace std;
using namespace boost::gregorian;

int num_of_days(const date& d1, const date& d2) noexcept {
    return abs((d1 - d2).days());
}
int main(void) {
    date d1, d2;
    d1 = date_from_iso_string("20160622");
    d2 = date_from_iso_string("20160624");

    cout << num_of_days(d1, d2) << endl;
    
    return 0;
}