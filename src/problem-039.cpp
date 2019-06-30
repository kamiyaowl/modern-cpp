#include <iostream>
#include <chrono>
#include <functional>

using namespace std;

template<typename T>
constexpr double measure_duration(function<T> f) noexcept {
    auto start = chrono::system_clock::now();
    f();
    auto end = chrono::system_clock::now();
    return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

int main(void) {
    cout << "elapsed: " << measure_duration<void()>([](){
        cout << "start task" << endl;
        cout << "end task" << endl;
    }) << endl;
    return 0;
}