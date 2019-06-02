#include <iostream>
#include <string>
#include <cstdint>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

string toHexStr(const vector<uint8_t>& src) {
    stringstream ss;
    for(const auto& i : src) {
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(i);
    }
    return ss.str();
}
int main(void){
    vector<uint8_t> example1 { 0xBA, 0xAD, 0xF0, 0x0D };
    vector<uint8_t> example2 { 1,2,3,4,5,6 };

    auto dst1 = toHexStr(example1);
    auto dst2 = toHexStr(example2);
    cout << dst1 << endl;
    cout << dst2 << endl;
    return 0;
}