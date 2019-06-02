#include <iostream>
#include <string>
#include <sstream>
#include <istream>

using namespace std;
string capitalize(const string& src) {
    stringstream ss {src};
    stringstream dst;
    string token;
    while(std::getline(ss, token, ' ')) {
        if('a' <= token[0] && token[0] <= 'z') {
            token[0] += ('A' - 'a');
        }
        dst << token << " ";
    }
    return dst.str();
}

int main(void) {
    cout << capitalize("the c++ challenger") << endl;

    return 0;
}