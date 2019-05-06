#include <iostream>
#include <string>
#include <vector>

using namespace std;

//ISBN4-10-109205-x
bool is_isbn(string src) {
    vector<int> num(10);
    if(src.length() != 17) return false;
    if(src[0] != 'I') return false;
    if(src[1] != 'S') return false;
    if(src[2] != 'B') return false;
    if(src[3] != 'N') return false;
    num[0] = src[4] - '0';
    if(src[5] != '-') return false;
    num[1] = src[6] - '0';
    num[2] = src[7] - '0';
    if(src[8] != '-') return false;
    num[3] = src[ 9] - '0';
    num[4] = src[10] - '0';
    num[5] = src[11] - '0';
    num[6] = src[12] - '0';
    num[7] = src[13] - '0';
    num[8] = src[14] - '0';
    if(src[15] != '-') return false;
    num[9] = src[16] - '0';
    for(const auto& n: num) {
        if(n < 0 || 9 < n) return false;
    }
    // check digit
    int sum = 0;
    for(int i = 0 ; i < 9 ; ++i) {
        sum += num[i] * (10 - i);
    }
    int result = 11 - (sum % 11);
    return result == num[9] ? true : false;
}

int main(void) {
    string src;
    cin >> src;
    auto result = is_isbn(src);
    cout << (result ? "True": "False") << endl;
    return 0;
}