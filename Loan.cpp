#pragma once
#include <iostream>
#include <string>
#include "member.cpp"  
using namespace std;

class Loan : public Member {
private:
    int loanId;
    string loanDate;
    string returnDate;

public:
    Loan() : Member() {
        loanId = 0;
        loanDate = "unknown";
        returnDate = "unknown";
    }

   
    Loan(int uId, string uName, string uGender, string uPhone, string uEmail, string uPassword,
         int lId, string lDate, string rDate)
      : Member(uId, uName, uGender, uPhone, uEmail, uPassword),
        loanId(lId), loanDate(lDate), returnDate(rDate) {}

    void setLoanId(int lId) {
        if (lId > 0) loanId = lId;
        else cout << "Loan Id must be Positive\n";
    }

    void setLoanDate(string lDate) {
        if (!lDate.empty()) loanDate = lDate;
        else cout << "Please input Loan Date\n";
    }

    void setReturnDate(string rDate) {
        if (!rDate.empty()) returnDate = rDate;
        else cout << "Please input Return Date\n";
    }

    int getLoanId() const { return loanId; }
    string getLoanDate() const { return loanDate; }
    string getReturnDate() const { return returnDate; }

    void input() override {
        Member::input();
        cout << "Enter Loan Id: ";
        cin >> loanId;
        cin.ignore();
        cout << "Enter Loan Date: ";
        getline(cin, loanDate);
        cout << "Enter Return Date: ";
        getline(cin, returnDate);
    }

    void display() override {
        Member::display();
        cout << "Loan Id: " << loanId << endl;
        cout << "Loan Date: " << loanDate << endl;
        cout << "Return Date: " << returnDate << endl;
    }
    ~Loan() {}
};
