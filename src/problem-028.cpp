#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// 偶数だった場合に強引に奇数にする
string insert_dummy(const string& src, char dummy) {
    stringstream dst;
    dst << dummy;
    for(const char c: src) {
        dst << c << dummy;
    }
    return dst.str();
}

// 偶数入れるな
vector<int> manacher(const string& src) {
    vector<int> radius(src.size());
    for(int i = 0 , j = 0, k = 0 ; i < src.size() ; i += k, j -= k) {
        // iを中心に長さを求める
        for( ; i - j >= 0 && i + j < src.size() && src[i - j] == src[i + j] ; ++j) {
        }
        radius[i] = j;
        // 計算済値で構築して
        for(k = 1; i + k < src.size() && k + radius[i - k] < j ; ++k) {
            radius[i + k] = radius[i - k];
        }
    }
    return radius;
}

string get_max_palindrome(const string& str) {
    const char dummy = static_cast<const char>(255); // 標準入力とかはしないやろ
    // 偶数対策
    string src = (str.length() % 2 != 0) ? str : insert_dummy(str, dummy);
    // 各位置での回文長を取得
    auto radius = manacher(src);
    // 一番長いところの文字列を切り出す
    std::vector<int>::iterator iter = std::max_element(radius.begin(), radius.end());
    size_t index = std::distance(radius.begin(), iter);
    int r = radius[index];
    size_t begin = index - (r - 1);
    size_t len   =  r * 2 - 1;
    // 奇数文字列はおわり
    auto dst = src.substr(begin, len);
    if (str.length() % 2 != 0) {
        return dst;
    }
    // 偶数はdummyを消す
    string removed;
    std::copy_if(dst.cbegin(), dst.cend(), std::back_inserter(removed), [&](char c){ return c != dummy; });
    return removed;
}

int main(void) {
    string src;
    cin >> src;
    auto result = get_max_palindrome(src);
    cout << result << endl;

    return 0;
}