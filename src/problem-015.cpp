#include <iostream>
#include <string>
#include <cstdint>
#include <array>

using namespace std;

// friend: 非メンバでもメンバへのアクセスを許可

class ipv4 {
    array<uint8_t, 4> data;
public:
    ipv4(uint8_t a, uint8_t b, uint8_t c, uint8_t d): data{{a,b,c,d}} {}
    ipv4(): ipv4(0,0,0,0) {}

    friend istream& operator>>(istream& is, ipv4& dst) {
        char c1,c2,c3;
        int a,b,c,d;
        is >> a >> c1 >> b >> c2 >> c >> c3 >> d;
        if ((c1 == '.' && c2 == '.' && c3 == '.') &&
            (a >= 0 && b >= 0 && c >= 0 && d >= 0) &&
            (a <= 256 && b <= 256 && c <= 256 && d <= 256)
        ) {
            dst = ipv4(
                static_cast<uint8_t>(a & 0xff),
                static_cast<uint8_t>(b & 0xff),
                static_cast<uint8_t>(c & 0xff),
                static_cast<uint8_t>(d & 0xff)
            );
        } else {
            is.setstate(ios_base::failbit);
        }
        return is;
    }
    friend ostream& operator<<(ostream& os, const ipv4& src) {
        os <<  static_cast<int>(src.data[0]) << '.'
            << static_cast<int>(src.data[1]) << '.' 
            << static_cast<int>(src.data[2]) << '.' 
            << static_cast<int>(src.data[3]);
        return os;
    }
};
int main(void) {
    ipv4 src;

    cout << "ip address here" << endl;
    cin >> src;
    cout << src;
    return 0;
}