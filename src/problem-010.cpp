#include <iostream>
#include <stdint.h>

using namespace std;

void print_bin(uint32_t src, int width) {
    for(int i = 0 ; i < width ; ++i) {
        cout << (src & (0x1 << (width - 1 - i)) ? 0x1 : 0x0);
    }
}
uint32_t enc_gray(uint32_t src) {
    return src ^ (src >> 1);
}
uint32_t dec_gray(uint32_t src) {
    uint32_t dst = 0x0;
    // 初回だけループに乗らないのでやっておく
    bool bit31 = (src >> 31) & 0x1;
    bool current = bit31;
    if(current) { dst |=  0x80000000; }
    // 残りのビットは上位ビットとのxorで決まるのでループに乗せる
    for(int i = 0 ; i < 31 ; ++i) {
        int bit = (30 - i);
        bool next = ((current ? 0x1 : 0x0) ^ ((src >> bit) & 0x1)) == 0x1;
        if (next) { dst |= (1 << bit); }
        current = (next ? true : false);
    }
    return dst;
}

int main(void) {
    for(uint32_t i = 0 ; i < 0x20 ; ++i) {
        auto enc = enc_gray(i);
        auto dec = dec_gray(enc);

        print_bin(i, 5);
        cout << "\t";
        print_bin(enc, 5);
        cout << "\t" << dec << "\t" << endl;;
    }
    return 0;
}