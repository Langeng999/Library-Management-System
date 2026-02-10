#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include "admin.cpp"
#include "admin_info.cpp"
#include "admin_main.cpp"
#include "member_info.cpp"
#include "member_main.cpp"
#include "member.cpp"
using namespace std;

class EmployeeSystem
{
public:
    void run()
    {
        Admin admin;
        Member member;
        int choice;
        do
        {
            cout << "\nWelcome to the Library Management System!\n";
            cout << "=========================================\n";
            cout << "|          1. Admin                     |\n";
            cout << "|          2. Member                    |\n";
            cout << "|          0. Exit                      |\n";
            cout << "=========================================\n";
            cout << "Enter your choice: ";

            cin >> choice;

            if (choice == 1)
            {
                cout << "Do you have an existing admin account? (y/n): ";
                char hasAccount;
                cin >> hasAccount;

                // ---- Register admin ----
                if (hasAccount == 'n' || hasAccount == 'N')
                {
                    cout << "Creating new admin account...\n";
                    admin.input();

                    ofstream file("admin_info.txt", ios::app);
                    if (!file.is_open())
                    {
                        cout << "Error creating admin file!\n";
                        continue;
                    }

                    file << admin.getMemberID() << '|'
                         << admin.getAdminUsername() << '|'
                         << admin.getMemberGender() << '|'
                         << admin.getMemberPhone() << '|'
                         << admin.getMemberEmail() << '|'
                         << admin.getAdminRole() << '|'
                         << admin.getMemberPassword() << '\n';

                    file.close();
                    cout << "Admin account created! Please login again.\n";
                    continue; // back to main menu
                }
                else if (hasAccount == 'y' || hasAccount == 'Y')
                {
                    if (AdminInfo())
                    {
                        cout << "Login successful! Welcome, Admin.\n";
                        admin_manu(); 
                        continue;    
                    }
                }

                else
                {
                    cout << "Invalid choice!\n";
                    continue;
                }
                char again;
                cout << "Back to main menu? (y/n): ";
                cin >> again;
                if (again != 'y' && again != 'Y')
                    break;
            }

            else if (choice == 2)
            {
                cout << "Do you have an existing member account? (y/n): ";
                char hasAccount;
                cin >> hasAccount;
                if (hasAccount == 'n' || hasAccount == 'N')
                {
                    cout << "Creating new member account...\n";
                    member.input();
                    ofstream file("member_info.txt", ios::app);
                    if (!file)
                    {
                        cout << "Error creating member file!\n";
                    }
                    file << member.getMemberID() << "|" << member.getMemberName() << "|"
                         << member.getMemberGender() << "|" << member.getMemberPhone() << "|"
                         << member.getMemberEmail() << "|" << "Member" << "|"
                         << member.getMemberPassword() << "\n";
                    file.close();
                    cout << "Member account created! Please login again.\n";
                    continue;
                }
                else if (hasAccount == 'y' || hasAccount == 'Y')
                {
                    if (MemberInfo())
                    {
                        cout << "Login successful! Welcome, Member.\n";
                        member_manu(int(member.getMemberID()));
                        continue;
                    }
                }
                else
                {
                    cout << "Innvalid choice!\n";
                }

                char again;
                cout << "Back to main menu? (y/n): ";
                cin >> again;
                if (again != 'y' && again != 'Y')
                    break;
            }
        } while (choice != 0);
    }
};