#pragma once
#include <iostream>
#include <stdexcept>
#include <limits>
#include <string>
using namespace std;
class Book
{
private:
    int bookId;
    string bookTitle;
    string bookAuthor;
    string isbn;
    bool isBorrow = true;
    string category;

public:
    Book()
    {
        bookId = 0;
        bookTitle = "";
        bookAuthor = "";
        isbn = "";
        isBorrow = true;
        category = "";
    }
    Book(int id, string title, string author, string isbnNum, bool borrow, string cat)
    {
        bookId = id;
        bookTitle = title;
        bookAuthor = author;
        isbn = isbnNum;
        borrow ? isBorrow = true : isBorrow = false;
        category = cat;
    }
    // setter
    void setBookId(int id)
    {
        if (id > 0)
        {
            bookId = id;
        }
        else
        {
            cout << "Invalid Book ID" << endl;
        }
    }
    void setBookTitle(string title)
    {
        if (!title.empty())
        {
            bookTitle = title;
        }
        else
        {
            cout << "Book title cannot be empty" << endl;
        }
    }
    void setBookAuthor(string author)
    {
        if (!author.empty())
        {
            bookAuthor = author;
        }
        else
        {
            cout << "Book author cannot be empty" << endl;
        }
    }
    void setIsbn(string isbnNum)
    {
        if (!isbnNum.empty())
        {
            isbn = isbnNum;
        }
        else
        {
            cout << "ISBN cannot be empty" << endl;
        }
    }
    void setCategory(string cat)
    {
        if (!cat.empty())
        {
            category = cat;
        }
        else
        {
            cout << "Category cannot be empty" << endl;
        }
    }
    void setBorrowStatus(bool status)
    {
        isBorrow = status;
    }

    // getter
    int getBookId() const
    {
        return bookId;
    }
    string getBookTitle() const
    {
        return bookTitle;
    }
    string getAuthor() const
    {
        return bookAuthor;
    }
    string getIsbn() const
    {
        return isbn;
    }
    bool getBorrowStatus() const
    {
        return isBorrow;
    }
    string getCategory() const
    {
        return category;
    }

   void input()
{
    while (true) {
        try {
            cout << "Enter Book ID: ";
            cin >> bookId;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Book ID must be a number!");
            }

            if (bookId <= 0) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Book ID must be a positive number!");
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
        catch (const exception& e) {
            cout << e.what() << "\n";
        }
    }

    // ---- Title ----
    while (true) {
        try {
            cout << "Enter Book Title: ";
            getline(cin, bookTitle);

            if (bookTitle.empty())
                throw invalid_argument("Book title cannot be empty!");

            break;
        }
        catch (const exception& e) {
            cout << e.what() << "\n";
        }
    }

    // ---- Author ----
    while (true) {
        try {
            cout << "Enter Book Author: ";
            getline(cin, bookAuthor);

            if (bookAuthor.empty())
                throw invalid_argument("Book author cannot be empty!");

            break;
        }
        catch (const exception& e) {
            cout << e.what() << "\n";
        }
    }

    // ---- ISBN ----
    while (true) {
        try {
            cout << "Enter ISBN: ";
            getline(cin, isbn);

            if (isbn.empty())
                throw invalid_argument("ISBN cannot be empty!");

            break;
        }
        catch (const exception& e) {
            cout << e.what() << "\n";
        }
    }

    // ---- Category ----
    while (true) {
        try {
            cout << "Enter Book Category: ";
            getline(cin, category);

            if (category.empty())
                throw invalid_argument("Category cannot be empty!");

            break;
        }
        catch (const exception& e) {
            cout << e.what() << "\n";
        }
    }

    // ---- Borrow Status ----
    while (true) {
        try {
            int statusInput;
            cout << "Enter Borrow Status (1 for Available, 0 for Borrowed): ";
            cin >> statusInput;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Borrow status must be a number (0 or 1)!");
            }

            if (statusInput != 0 && statusInput != 1) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Borrow status must be 0 or 1!");
            }

            isBorrow = (statusInput == 1);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
        catch (const exception& e) {
            cout << e.what() << "\n";
        }
    }
}
    void display() const
    {
        cout << "\n=== Book Info ===\n";
        cout << "ID: " << bookId << "\nTitle: " << bookTitle
             << "\nAuthor: " << bookAuthor << "\nISBN: " << isbn
             << "\nCategory: " << category
             << "\nStatus: " << (isBorrow ? "Available" : "Borrowed") << endl;
    }
    ~Book(){};
    };