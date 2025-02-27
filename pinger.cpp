#include <iostream>
#include <cstdlib>

using namespace std;

bool ping(string ip) {
    string command = "ping -c 1 " + ip + " > /dev/null 2>&1"; // Linux/macOS
    return system(command.c_str()) == 0;
}

int main() {
    int temp = 26;  // Number of IPs to test
    string junk;

    for (int i = 11; i < temp; i++) {
        junk = "192.168.1." + to_string(i); // Convert int to string

        if (ping(junk)) {
            cout << "Ping to " << junk << " was successful!\n";
        } else {
            cout << "Ping to " << junk << " failed.\n";
        }
    }

    return 0;
}
