#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
string join(const vector<string>& src, const string& del) {
    stringstream dst;
    for(const string& str: src) {
        dst << str << del;
    }
    return dst.str();
}

int main(void) {
    vector<string> src = {
        "this",
        "is",
        "an",
        "example",
    };
    auto dst = join(src, " ");
    cout << dst << endl;
    return 0;
}