#include <iostream>
#include <cstdlib>

using namespace std;

bool ping(string ip) {
    string command = "ping -c 1 " + ip + " > /dev/null 2>&1"; // Linux/macOS
    return system(command.c_str()) == 0;
}

int main() {

    string fw_out_cypod1 = "192.168.1.1";
    string fw_in_cypod1 = "172.21.1.254";

    if (ping(fw_out_cypod1)){
        cout << "Successfully pinged outside firewall of cypod 1" << endl;
        if (ping(fw_in_cypod1)){
            cout << "Successfully pinged router of cypod 1" << endl;
        }
        else {
            cout << "Ping to " << fw_in_cypod1 << " failed.\n";
        }
    }
    else {
        cout << "Ping to " << fw_out_cypod1 << " failed.\n";
    }



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
