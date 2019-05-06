#include <iostream>
#include <vector>

using namespace std;

int divisor_sum(int n) {
    int sum = n; // その数自信は先に足す
    int end = n / 2;
    for(int i = 1 ; i <= end ; ++i) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum;
}
bool solve(int n) {
    for(int i = 2 ; i < n ; ++i) {
        int x = divisor_sum(i);
        if (x > i * 2) {
            cout << i << endl;
        }
    }
}

int main(void){
    int n;
    cin >> n;
    solve(n + 1); // 上限までの
    return 0;
}