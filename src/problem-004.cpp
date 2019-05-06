#include <iostream>
#include <vector>

using namespace std;

int solve(int n) {
    assert(n > 2);
    // エラトステネスの篩
    int last;
    vector<bool> table(n, false);
    table[0] = false;
    table[1] = false;
    for(int i = 2 ; i < n ; ++i) {
        if (table[i]) continue; // すでに何かの倍数となっている
        last = i;
        for(int x = i; x < n ; x += i) {
            table[x] = true;
        } 
    }
    return last;
}

int main(void){
    // もうめんどいのでcpp_int使うのやめた、問題の書き方が悪い
    int n;
    cin >> n;
    auto result = solve(n);
    cout << result << endl;
    return 0;
}