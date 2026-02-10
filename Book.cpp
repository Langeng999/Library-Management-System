#pragma once
#include <iostream>
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
        cout << "Enter Book ID: ";
        while (!(cin >> bookId) || bookId <= 0)
        {
            cout << "Invalid ID. Enter positive number: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        cin.ignore();

        cout << "Enter Book Title: ";
        getline(cin, bookTitle);
        cout << "Enter Book Author: ";
        getline(cin, bookAuthor);
        cout << "Enter ISBN: ";
        getline(cin, isbn);
        cout << "Enter Category: ";
        getline(cin, category);
        cout << "Available? (1/0): ";
        int status;
        cin >> status;
        isBorrow = (status == 1);
        cin.ignore();
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