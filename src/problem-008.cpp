#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
    for(int i = 0 ; i < 10 ; ++i) 
    for(int j = 0 ; j < 10 ; ++j) 
    for(int k = 1 ; k < 10 ; ++k) { // 3桁の値
        int x = i + j * 10 + k * 100;
        int y = 0;
        // xを上間らない間はループする
        for(int n = 2 ; y < x ; ++n) {
            int current_y = roundtol(pow(i, n) + pow(j, n) + pow(k, n));
            if (y == current_y) break; // 0,1だけで構成されてると+∞に収束しない
            y = current_y;

            if (x == y) {
                cout << x << endl;
                break;
            }
        }
    }
    return 0;
}