#include <iostream>
#include <queue>

int main(void) {
    std::priority_queue<int> q;
    q.push(1);
    std::cout << q.top() << std::endl;
    std::cout << q.size() << std::endl;
    std::cout << q.empty() << std::endl;
    q.pop();
    std::cout << q.empty() << std::endl;

    return 0;
}