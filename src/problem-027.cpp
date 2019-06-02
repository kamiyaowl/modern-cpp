#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(const string& src, const string& tokens) {
    vector<string> dst;
    string tmp;
    for(const char c: src) {
        if(tokens.find(c) != string::npos) {
            if (tmp.size() > 0) {
                dst.push_back(tmp);
                tmp = string();
            }
        } else {
            tmp.push_back(c);
        }
    }
    // last token
    if (tmp.size() > 0) {
        dst.push_back(tmp);
    }
    return dst;
}

int main(void) {
    auto dst = split("this is an example", ",.! ");
    for(const auto& str: dst) {
        cout << str << endl;
    }

    return 0;
}