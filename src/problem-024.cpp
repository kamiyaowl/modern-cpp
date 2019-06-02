#include <iostream>
#include <vector>
#include <cstdint>
#include <string>

using namespace std;
void toByteVector(const string& src, vector<uint8_t>& dst) {
    for(int i = 0 ; i < src.size() / 2 ; ++i) {
        auto str = src.substr(i * 2 , 2);
        int num = std::stoi(str, 0, 16);
        dst.push_back(static_cast<uint8_t>(num));
    }
}

int main(void) {
    auto ex1 = "baadf00d";
    auto ex2 = "010203040506";

    vector<uint8_t> dst1, dst2;
    toByteVector(ex1, dst1);
    toByteVector(ex2, dst2);

    for(const auto i : dst1) {
        cout << "dst1:" << std::hex << static_cast<int>(i) << endl;
    }
    for(const auto i : dst2) {
        cout << "dst2:" << std::hex << static_cast<int>(i) << endl;
    }
}