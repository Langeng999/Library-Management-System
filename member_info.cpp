#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "member.cpp"
using namespace std;

bool MemberInfo() {
    ifstream file("member_info.txt");
    if (!file.is_open()) {
        cout << "Cannot open member_info.txt\n";
        return false;
    }

    string username, password;
    cout << "Username: "; cin >> username;
    cout << "Password: "; cin >> password;

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string id, uname, gender, phone, email, role, pass;

        getline(ss, id, '|');
        getline(ss, uname, '|');
        getline(ss, gender, '|');
        getline(ss, phone, '|');
        getline(ss, email, '|');
        getline(ss, role, '|');
        getline(ss, pass);

        if (uname == username && pass == password && role == "Member") {
            return true;
        }
        file.close();
        cout << "Invalid username or password!\n";
        return false;
    }
    return false;
}
