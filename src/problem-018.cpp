#include <iostream>
#include <functional>

// 特殊化(2値の場合はこっち)
template<typename T>
T minimum(T a, T b) {
    return a < b ? a : b;
}
template<typename HEAD, typename ...TAIL>
HEAD minimum(HEAD head, TAIL ...tail) {
    return minimum(head, minimum(tail...));
}

template<typename T>
T minimum2(std::function<bool(T,T)> cond, T a, T b) {
    return cond(a,b) ? a : b;
}
template<typename HEAD, typename ...TAIL>
HEAD minimum2(std::function<bool(HEAD,HEAD)> cond, HEAD head, TAIL ...tail) {
    return minimum2(cond, head, minimum2(cond, tail...));
}

int main(void) {
    auto result = minimum(1,2,4,5,6,7,8,9);
    std::cout << result << std::endl;
    // 一番でかいのが出るはず
    std::function<bool(int,int)> cond = [](int a, int b){ return a > b; };
    auto result2 = minimum2(cond, 1,2,4,5,6,7,8,9);
    std::cout << result2 << std::endl;
    return 0;
}