#include <iostream>
#include <vector>

using namespace std;

vector<int> print_pascal_tri(int n, const vector<int>& src) {
    vector<int> dst {1};
    if (n <= 0) {
        return src;
    } else if (src.size() > 0) {
        // とりあえず両端は無視
        for(int i = 1 ; i < src.size() ; ++i) {
            auto a = src[i - 1];
            auto b = src[i];
            dst.push_back(a + b);
        }
        // 両端
        dst.push_back(1);
    }
    // 表示
    for(const auto& i: dst) {
        cout << i << " ";
    }
    cout << endl;

    // 再帰
    return print_pascal_tri(n - 1, dst);
}
int main(void) {
    vector<int> a{};
    print_pascal_tri(10, a);

    return 0;
}