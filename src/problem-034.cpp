#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

string remove_empty_line(const string& path) {
    stringstream ss;
    ifstream ifs;
    ifs.open(path);
    while(!ifs.eof()) {
        string line;
        getline(ifs, line);
        // 空白だけはだめっぽい
        if(line.length() > 0 && line.find_first_not_of(' ') != line.npos) {
            ss << line << endl;
        }
    }
    ifs.close();

    return ss.str();
}
int main(void) {
    cout << remove_empty_line("problem-034.cpp") << endl;

    return 0;

}