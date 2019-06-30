#include <iostream>
#include <string>
#include <cmath>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace std;
using namespace boost::gregorian;

void print_calendar(const date& d) noexcept {
    const int day_of_month = d.end_of_month().day();
    const int day_of_week  = (d.end_of_month().day_of_week().as_number() - (day_of_month % 7) + 1);
    const int today = d.day() - 1;
    int count = 0;

    cout << "Sun\tMon\tTue\tWed\tThu\tFri\tSat" << endl;
    for(int d = -day_of_week ; d < day_of_month ; d++) {
        if (d < 0) {
            // padding
            cout << " " << "\t";
        } else if(d == today) {
            cout << "\033[4m*" << (d + 1) << "*\033[m" << "\t";
        } else {
            cout << (d + 1) << "\t";
        }
        // week
        count++;
        if ((count % 7) == 0) {
            cout << endl;
        }
    }
}
int main(void) {
    date d1 = date_from_iso_string("20190702");
    print_calendar(d1);
/*

Sun     Mon     Tue     Wed     Thu     Fri     Sat
        1       *2*     3       4       5       6
7       8       9       10      11      12      13
14      15      16      17      18      19      20
21      22      23      24      25      26      27
28      29      30      31

 */
    return 0;
}