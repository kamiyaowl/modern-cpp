#include <iostream>

using namespace std;

template<typename T>
T solve(T n) {
    T sum = 0;
    for(T i = 3 ; i < n ; ++i) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    return sum;
}
int main(void){
    int n;
    cin >> n;
    auto result = solve(n + 1); // 上限までの
    cout << result << endl;
    
    return 0;
}