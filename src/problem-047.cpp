#include<iostream>

template<typename T>
class DoubleBuffer {
    private:
        T current;
        T stage;
    public:
        DoubleBuffer() {}
        DoubleBuffer(T initial) : current(initial) {}
        constexpr T    read() { return this->current; }
        constexpr void write(T data) { this->stage = data; }
        constexpr void flush() {this->current = this->stage; }
};

int main(void) {
    DoubleBuffer<int> buf(1);
    std::cout << buf.read() << std::endl;
    buf.write(2);
    std::cout << buf.read() << std::endl;
    buf.flush();
    std::cout << buf.read() << std::endl;

    return 0;
}