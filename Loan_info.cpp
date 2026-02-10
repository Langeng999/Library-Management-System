#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdio>
#include <ctime>
#include "Loan.cpp"
using namespace std;

// loans.txt format:
// loanId|memberId|bookId|loanDate|returnDate|status
// status: ACTIVE or CLOSED

string todayDate() {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    int y = 1900 + ltm->tm_year;
    int m = 1 + ltm->tm_mon;
    int d = ltm->tm_mday;

    string yy = to_string(y);
    string mm = (m < 10 ? "0" + to_string(m) : to_string(m));
    string dd = (d < 10 ? "0" + to_string(d) : to_string(d));

    return yy + "-" + mm + "-" + dd;
}

int nextLoanId() {
    ifstream in("loans.txt");
    if (!in.is_open()) return 1;

    string line;
    int maxId = 0;

    while (getline(in, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string idStr;
        getline(ss, idStr, '|');

        int id;
        stringstream s(idStr);
        if (s >> id) {
            if (id > maxId) maxId = id;
        }
    }
    in.close();
    return maxId + 1;
}

void createLoan(int memberId, int bookId) {
    int loanId = nextLoanId();
    string loanDate = todayDate();

    ofstream out("loans.txt", ios::app);
    if (!out.is_open()) {
        cout << "Error opening loans.txt!\n";
        return;
    }

    out << loanId << "|"
        << memberId << "|"
        << bookId << "|"
        << loanDate << "|"
        << "N/A" << "|"
        << "ACTIVE" << "\n";

    out.close();
    cout << "Loan created! LoanID: " << loanId << " Date: " << loanDate << "\n";
}

void closeLoan(int memberId, int bookId) {
    ifstream in("loans.txt");
    ofstream out("loans_tmp.txt");

    if (!in.is_open() || !out.is_open()) {
        cout << "Loan file error!\n";
        return;
    }

    string returnDate = todayDate();
    string line;
    bool found = false;

    while (getline(in, line)) {
        if (line.empty()) { out << "\n"; continue; }

        stringstream ss(line);
        string loanId, mId, bId, loanDate, rDate, status;

        getline(ss, loanId, '|');
        getline(ss, mId, '|');
        getline(ss, bId, '|');
        getline(ss, loanDate, '|');
        getline(ss, rDate, '|');
        getline(ss, status);

        // convert mId and bId safely (no try/catch)
        int mid, bid;
        stringstream s1(mId), s2(bId);

        if (!(s1 >> mid) || !(s2 >> bid)) {
            // bad line, keep it unchanged
            out << line << "\n";
            continue;
        }

        // handle "ACTIVE\r"
        bool isActive = (status.size() >= 6 && status.substr(0, 6) == "ACTIVE");

        if (mid == memberId && bid == bookId && isActive) {
            found = true;
            rDate = returnDate;
            status = "CLOSED";
        }

        out << loanId << "|" << mId << "|" << bId << "|"
            << loanDate << "|" << rDate << "|" << status << "\n";
    }

    in.close();
    out.close();

    if (!found) {
        cout << "No ACTIVE loan found for this member/book.\n";
        remove("loans_tmp.txt");
        return;
    }

    remove("loans.txt");
    rename("loans_tmp.txt", "loans.txt");
    cout << "Loan closed! Return Date: " << returnDate << "\n";
}
