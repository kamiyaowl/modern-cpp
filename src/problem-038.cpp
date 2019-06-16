#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class logger {
    string path;
    ofstream ofs;
    bool is_persistence = false;
public:
    logger(string path): path(path) {
        ofs = ofstream(path);
    }
    logger(string path, bool is_persistence): path(path), is_persistence(is_persistence) {
        ofs = ofstream(path);
    }
    void write(const string& data) {
        ofs << data << endl;
    }
    ~logger() {
        ofs.close();
        if (!is_persistence) {
            std::remove(path.c_str());
        }
    }
};

int main(void) {
    logger l1("temp1.log");
    l1.write("volatile");

    logger l2("temp2.log", true);
    l2.write("non volatile");
    
    return 0;
}