#include <iostream>
#include <boost/circular_buffer.hpp>

int main(void) {
    const int BUF_SIZE = 3;
    boost::circular_buffer<int> buf(BUF_SIZE);

    for(int i = 0 ; i < BUF_SIZE * 3 ; i++) {
        std::cout << "empty:"     << buf.empty() 
                  << " full:"     << buf.full() 
                  << " size:"     << buf.size()
                  << " capacity:" << buf.max_size()
                  << std::endl;
        for(const auto& item : buf) {
            std::cout << item << ",";
        }
        std::cout << std::endl;
        // insert
        buf.push_back(i);
    }

    return 0;
}