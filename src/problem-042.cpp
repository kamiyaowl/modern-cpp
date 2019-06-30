#include <iostream>
#include <string>
#include <cmath>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace std;
using namespace boost::gregorian;

int main(void) {
    date d1 = date_from_iso_string("20160622");

    cout << d1.day()<< endl;
    cout << d1.week_number()<< endl;
    
    return 0;
}