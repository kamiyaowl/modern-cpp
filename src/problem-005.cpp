#include <iostream>
#include <vector>

using namespace std;

void solve(int n) {
    assert(n > 2);
    // エラトステネスの篩
    vector<bool> table(n, false); // true、すでにマーク済で素数ではない
    table[0] = true;
    table[1] = true;
    for(int i = 2 ; i < n ; ++i) {
        if (table[i]) continue;
        if (i > 5 && !table[i - 6]) {
            cout << "(" << i - 6 << "," << i << ")" << endl;
        }
        for(int x = i + i; x < n ; x += i) {
            table[x] = true;
        } 
    }
}

int main(void){
    // もうめんどいのでcpp_int使うのやめた、問題の書き方が悪い
    int n;
    cin >> n;
    solve(n);
    return 0;
}