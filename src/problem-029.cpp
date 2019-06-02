#include <iostream>
#include <string>
#include <regex>

using namespace std;
std::regex number_plate_re(R"([A-Z]{3}-[A-Z]{2}\s\d{3}\d?)");

bool match(const string& src) {
    return regex_match(src, number_plate_re);
}
vector<string> search_all(const string& src) {
    vector<string> dst;
    auto iter = src.cbegin();
    auto end = src.cend();
    std::smatch m;

    while (regex_search(iter, end, m, number_plate_re)) {
        dst.push_back(m.str());
        iter = m[0].second;
    }
    return dst;
}
int main(void) {
    string src = "ABC-DF 1234 GHI-JK 123 abc-de 1234 ABC-DF 1233";

    auto is_match = match(src);
    cout << (is_match ? "Match" : "Miss") << endl;
    auto matches = search_all(src);

    for(const auto& str: matches) {
        cout << str << endl;
    }
    return 0;
}