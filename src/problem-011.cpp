#include <iostream>
#include <vector>
#include <string>

using namespace std;

const vector<pair<int, string>> roman_number_table {
    make_pair(1000, "M"),
    make_pair( 900, "CM"),
    make_pair( 800, "DCCC"),
    make_pair( 700, "DCC"),
    make_pair( 600, "DC"),
    make_pair( 500, "D"),
    make_pair( 400, "CD"),
    make_pair( 300, "CCC"),
    make_pair( 200, "CC"),
    make_pair( 100, "C"),
    make_pair(  90, "XC"),
    make_pair(  80, "LXXX"),
    make_pair(  70, "LXX"),
    make_pair(  60, "LX"),
    make_pair(  50, "L"),
    make_pair(  40, "XL"),
    make_pair(  30, "XXX"),
    make_pair(  20, "XX"),
    make_pair(  10, "X"),
    make_pair(   9, "IV"),
    make_pair(   8, "VIII"),
    make_pair(   7, "VII"),
    make_pair(   6, "VI"),
    make_pair(   5, "V"),
    make_pair(   4, "IV"),
    make_pair(   3, "III"),
    make_pair(   2, "II"),
    make_pair(   1, "I"),
};
template<typename T>
void print_roman(T x) {
    for(const auto& [num, str]: roman_number_table) {
        while(x >= num) {
            cout << str;
            x -= num;
        }
    }
}

int main(void) {
    int x;
    cin >> x;
    print_roman(x);

    return 0;
}