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

    void set(uint8_t a, uint8_t b, uint8_t c, uint8_t d) {
        data[0] = a;
        data[1] = b;
        data[2] = c;
        data[3] = d;
    }
    void set(uint32_t raw) {
        data[0] = (raw >> 24) & 0xff;
        data[1] = (raw >> 16) & 0xff;
        data[2] = (raw >> 8)  & 0xff;
        data[3] = (raw >> 0)  & 0xff;
    }
    uint32_t to_uint32() const {
        return (data[0] << 24) | (data[1] << 16) | (data[2] << 8) | (data[3] << 0);
    }
    // inc, dec
    void inc() {
        // little endianで連結した結果をインクリすればok
        auto current = this->to_uint32();
        current++;
        this->set(current);
    }
    void dec() {
        auto current = this->to_uint32();
        current--;
        this->set(current);
    }
    // 比較系
    friend bool operator==(const ipv4& a, const ipv4& b) {
        return a.to_uint32() == b.to_uint32();
    }
    friend bool operator!=(const ipv4& a, const ipv4& b) {
        return a.to_uint32() != b.to_uint32();
    }
    friend bool operator<(const ipv4& a, const ipv4& b) {
        return a.to_uint32() < b.to_uint32();
    }
    friend bool operator>(const ipv4& a, const ipv4& b) {
        return a.to_uint32() > b.to_uint32();
    }
    friend bool operator<=(const ipv4& a, const ipv4& b) {
        return a.to_uint32() <= b.to_uint32();
    }
    friend bool operator>=(const ipv4& a, const ipv4& b) {
        return a.to_uint32() >= b.to_uint32();
    }
    // stream演算子とか
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
    ipv4 a,b;

    cout << "ip address1 here" << endl;
    cin >> a;
    cout << "ip address2 here" << endl;
    cin >> b;

    ipv4 tmp(a);
    for(ipv4 tmp(a) ; tmp <= b ; tmp.inc()) {
        cout << tmp << endl;
    }
    return 0;
}