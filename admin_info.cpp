#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "Admin.cpp"
using namespace std;

bool AdminInfo() { 
    
    ifstream checkFile("admin_info.txt");
    if (checkFile.is_open()) {
        string username, password;
        cout << "Username: "; cin >> username;
        cout << "Password: "; cin >> password;
        
        string line;
        while (getline(checkFile, line)) {
            stringstream ss(line);
            string id, uname, gender, phone, email, role, pass;
            getline(ss, id, '|'), getline(ss, uname, '|'), getline(ss, gender, '|');
            getline(ss, phone, '|'), getline(ss, email, '|'), getline(ss, role, '|');
            getline(ss, pass, '|');
            
            if (uname == username && pass == password) {
                checkFile.close();
                return true;  // Login success!
            }
        }
        checkFile.close();
        cout << "Invalid username or password!\n";
        return false;
    }
    
    // No file exists - create new admin
    cout << "\nNo admin found. Create first admin:\n";
    Admin admin;
    admin.input();
    
    ofstream file("admin_info.txt", ios::app);
    if (!file) {
        cout << "Error creating admin file!\n";
        return false;
    }
    
    file << admin.getMemberID() << "|" << admin.getAdminUsername() << "|" 
         << admin.getMemberGender() << "|" << admin.getMemberPhone() << "|" 
         << admin.getMemberEmail() << "|" << admin.getAdminRole() << "|" 
         << admin.getMemberPassword() << "\n";
    
    file.close();
    cout << "Admin created! Use these credentials to login next time.\n";
    return true;
}