#include <iostream>
#include <vector>
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace std;
using namespace boost::posix_time;


// target_time: utc
void print_invitation_time(const ptime& target_time, const vector<time_duration>& times) noexcept {
    for(const auto& t : times) {
        auto local_time = target_time + t;
        cout << "UTC:" << t.hours() << "\tbegin at:" << local_time << endl;
    }
}
int main(void) {
    ptime invitation_time = second_clock::local_time(); // test time
    vector<time_duration> timezone_vector = {
        hours(-3),
        hours(0),
        hours(3),
        hours(7),
        hours(9),
    };
    print_invitation_time(invitation_time, timezone_vector);

    return 0;
}