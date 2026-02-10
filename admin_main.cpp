#pragma once
#include "Book.cpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include "Admin.cpp"
using namespace std;

void admin_manu()
{
    int option;
    char addMore;
    Book book;
    do
    {
        cout << "\n=====| Admin Menu |=====\n";
        cout << "|      1. Add New Book    |\n";
        cout << "|      2. View All Books  |\n";
        cout << "|      3. Delete Book     |\n";
        cout << "|      4. Exit            |\n";
        cout << "=========================\n";
        cout << "Select an option: ";
        int option;
        cin >> option;
        cin.ignore();

        if (option == 1)
        {

            ofstream outFile("books.txt", ios::app);
            if (outFile.is_open())
            {
                book.input();
                outFile << book.getBookId() << "\t|" << book.getBookTitle() << "\t|" << book.getAuthor() << "\t|"
                        << book.getIsbn() << "\t|" << book.getCategory() << "\t|" << book.getBorrowStatus() << "\n";
                outFile.close();
                cout << "Book added successfully!\n";
            }
            else
            {
                cout << "Error opening file for writing!" << endl;
            }
        }
        else if (option == 2)
        {
            ifstream inFile("books.txt");
            if (inFile.is_open())
            {
                string line;
                while (getline(inFile, line))
                {
                    if (line.empty())
                        continue;

                    string idStr, title, author, isbn, borrowStr, category;
                    stringstream ss(line);

                    getline(ss, idStr, '|');
                    getline(ss, title, '|');
                    getline(ss, author, '|');
                    getline(ss, isbn, '|');
                    getline(ss, category, '|');
                    getline(ss, borrowStr);

                        bool available = (borrowStr == "1");

                    cout << "ID: " << idStr
                         << "\tTitle: " << title
                         << "\tAuthor: " << author
                         << "\tISBN: " << isbn
                         << "\tCategory: " << category
                         << "\tStatus: " << (available ? "Available" : "Borrowed")
                         << "\n";
                }
            }
            else if (option == 3)
            {
                cout << "Exiting Admin Menu. Goodbye!\n";
                break;
            }
            else
            {
                cout << "Error opening file for reading!" << endl;
            }
            inFile.close();
        }
        else if (option == 3)
        {
            cout << "Deleteting a book...\n";
            ifstream inFile("books.txt");
            ofstream tempFile("temp.txt");
            if (inFile.is_open() && tempFile.is_open())
            {
                int deleteId;
                cout << "Enter Book ID to delete: ";
                cin >> deleteId;
                cin.ignore();

                string line;
                bool found = false;
                while (getline(inFile, line))
                {
                    if (line.empty())
                        continue;

                    string idStr;
                    stringstream ss(line);
                    if (!getline(ss, idStr, '|'))
                        continue;

                    int id = stoi(idStr);
                    if (id == deleteId)
                    {
                        found = true;
                        continue;
                    }
                    tempFile << line << "\n";
                }
                inFile.close();
                tempFile.close();

                if (found)
                {
                    remove("books.txt");
                    rename("temp.txt", "books.txt");
                    cout << "Book deleted successfully!\n";
                }
                else
                {
                    remove("temp.txt");
                    cout << "Book ID not found. No deletion performed.\n";
                }
            }
            else
            {
                cout << "Error opening file for deletion!" << endl;
            }
        }
        else if (option == 4)
        {
            cout << "Exiting Admin Menu. Goodbye!\n";
            return;
        }
        else
        {
            cout << "Invalid option! Please try again.\n";
        }
        cout << "Do you want to perform another action? (y/n): ";
        cin >> addMore;
    } while (addMore == 'y' || addMore == 'Y');
}
