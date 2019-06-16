#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iomanip>

using namespace std;
enum class process_status {running, suspend};
class process {
public:
    string name;
    int id;
    process_status status;
    string account;
    int memByte;
    int operation_bits; // 32or64
    process(string name, int id, process_status status, string account, int memByte, int bits):
        name(name), id(id), status(status), account(account), memByte(memByte), operation_bits(bits) {
    }
    //sort
    int compare(const process& target) {
        return strcmp(name.c_str(), target.name.c_str());
    }
    bool operator<(const process& target) {
        return strcmp(name.c_str(), target.name.c_str()) < 0;
    }
    bool operator<=(const process& target) {
        return strcmp(name.c_str(), target.name.c_str()) <= 0;
    }
    bool operator>(const process& target) {
        return strcmp(name.c_str(), target.name.c_str()) > 0;
    }
    bool operator>=(const process& target) {
        return strcmp(name.c_str(), target.name.c_str()) >= 0;
    }
    bool operator==(const process& target) {
        return strcmp(name.c_str(), target.name.c_str()) == 0;
    }
    bool operator!=(const process& target) {
        return strcmp(name.c_str(), target.name.c_str()) != 0;
    }
    friend ostream& operator<<(ostream& os, const process& p) {
        os <<  std::left  << std::setw(20) << p.name;
        os <<  std::left  << std::setw(10) << p.id;
        os <<  std::left  << std::setw(10) << (p.status == process_status::running ? "Running" : "Suspend");
        os <<  std::right << std::setw(10) << p.memByte;
        os <<  std::right << std::setw(10) << p.operation_bits << "-bit";
        return os;
    }

};

int main(void) {
    vector<process> process_list = {
        {"chrome.exe"  ,  1044, process_status::running, "marius.bancila" ,  25180, 32},
        {"chrome.exe"  , 10100, process_status::running, "marius.bancila" , 227756, 32},
        {"cmd.exe"     ,   512, process_status::running, "SYSTEM"         ,     48, 64},
        {"explorer.exe",  7108, process_status::running, "marius.bancila" ,  29529, 64},
    };
    sort(process_list.begin(), process_list.end());
    for(const auto& p: process_list) {
        cout << p << endl;
    }
    return 0;
}