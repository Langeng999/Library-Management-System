#pragma once 
#include <iostream>
using namespace std;
class Member{
    protected:
    int userId;
    string userName;
    string userGender;
    string userPhone;
    string userEmail;
    string password;

    public:
    Member(){
        userId = 0;
        userName = "unknown";
        userGender = "unknown";
        userPhone = "unknown";
        userEmail = "unknown";
        password = "unknown";
    }
    Member(int uId, string uName, string uGender, string uPhone, string uEmail, string upassword){
        userId = uId;
        userName = uName;
        userGender = uGender;
        userPhone = uPhone;
        userEmail = uEmail;
        password = upassword;
    }
    //setter
    void setMemberId(int uId){
        if(userId > 0){
            userId = uId;
        }else{
            cout << "User Id must be Postive " << endl;
        }
    }
    void setMemberName(string uName){
        if(!userName.empty()){
            userName = uName;
        }else{
            cout << "Please input Username" <<endl;
        }
    }
    void setMemberGender(string uGender){
        if(!userGender.empty()){
            userGender = uGender;
        }else{
            cout << "Please input gender" <<endl;
        }
    }
    void setMemberPhone(string uPhone){
        if(!userPhone.empty()){
            userPhone = uPhone;
        }else{
            cout << "Please input phone Number" <<endl;
        }
    }
    void setMemberEmail(string uEmail){
        if(!userEmail.empty()){
            userEmail = uEmail;
        }else{
            cout << "Please input Your Email" <<endl;
        }
    }
    void setMemberPassword(string upassword){
        if(!password.empty()){
            password = upassword;
        }else{
            cout << "Please input Your Password" <<endl;
        }
    }
    //getter
    int getMemberID()const{
        return userId;
    }
    string getMemberName()const{
        return userName;
    }
    string getMemberGender()const{
        return userGender;
    }
    string getMemberPhone()const{
        return userPhone;
    }
    string getMemberEmail()const{
        return userEmail;
    }
    string getMemberPassword() const{
        return password;
    }

    virtual void input(){
        cout << "Enter User Id: ";
        cin >> userId; cin.ignore();
        cout << "Enter User Name: ";
        getline(cin,userName);
        cout << "Enter User Gender: ";
        cin >> userGender;
        cout << "Enter User Phone Number:";
        cin >> userPhone;
        cout << "Enter User Email: ";
        cin >> userEmail;
        cout << "Enter User Password: ";
        cin >> password;
    }
    virtual void display(){
        cout << "User ID: " <<userId <<endl;
        cout << "User Name: " <<userName <<endl;
        cout << "User Gender: " <<userGender <<endl;
        cout << "User PhoneNumber: " <<userPhone <<endl;
        cout << "User Email: " <<userEmail <<endl;
        cout << "User Password: " <<password << endl;
    }
    
    ~Member() {};
};