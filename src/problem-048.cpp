#include<iostream>
#include<vector>
#include<map>

template<typename T>
constexpr std::pair<T, int> search_most_freq(const std::vector<T> src) {
    std::map<T, int> counts;
    for(const auto& v: src) {
        if(counts.count(v) > 0) {
            counts[v]++;
        } else {
            counts[v] = 1;
        }
    }
    auto ptr = *std::max_element(
        std::begin(counts), std::end(counts),
        [] (const std::pair<T, int>& p1, const std::pair<T, int>& p2) {
            return p1.second < p2.second;
        }
    );
    return ptr;
}
int main(void) {
    std::vector<int> src = { 1,2,2,3,3,4,4,4,4,5,5,5,5,5,6,7, };

    auto dst = search_most_freq(src);
    std::cout << dst.first << ":" << dst.second << std::endl;

    return 0;
}