#pragma once
#include <iostream>
#include "member.cpp"
using namespace std;
class Admin : public Member{
    private:
    string adminRole;

    public:
    Admin() : Member(){
        adminRole = "unknown";
    }
    Admin(int uId, string uName, string uGender, string uPhone, string uEmail, string role, string password)
    : Member(uId, uName, uGender, uPhone, uEmail,password), adminRole(role){
        adminRole = role;
    }
    //setter
    void setAdminRole(string role){
        if(!role.empty()){
            adminRole = role;
        }else{
            cout << "Please input Admin Role" <<endl;
        }
    }
   
    //getter
    string getAdminRole()const{
        return adminRole;
    }
    string getAdminUsername()const{
        return userName;
    }

    void input() override {
        Member::input();
        cout << "Enter Admin Role: ";
        cin >> adminRole;
        
    }
    void display() override {
        Member::display();
        cout << "Admin Role: " << adminRole << endl;
    }
    ~Admin(){}
};