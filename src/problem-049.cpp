#include<iostream>
#include<string>
#include<map>

void print_hist(const std::string& src) {
    std::map<char, int> counts;
    for(const auto& c: src) {
        // 記号とか数字は無視するらしい
        if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) {
            if(counts.count(c) > 0) {
                counts[c]++;
            } else {
                counts[c] = 1;
            }
        }
    }
    for(const auto& [key, value]: counts) {
        std::cout << key << ": ";
        for(int i = 0 ; i < value ; ++i) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}
int main(void) {
    std::string src = "We, the japanese people, acting through our duly elected representatives in the national diet, ...";
    print_hist(src);
    return 0;
}