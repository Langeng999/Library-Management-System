#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdio>
#include <limits>

#include "loan_info.cpp"

using namespace std;

bool isAvailable(const string &s)
{
    return (!s.empty() && s[0] == '1');
}

void member_manu(int memberId)
{
    int option = 0;
    char addMore = 'y';

    do
    {
        cout << "\n=====| Member Menu |=====\n";
        cout << "|      1. View All Books  |\n";
        cout << "|      2. Check Out Book  |\n";
        cout << "|      3. Return Book     |\n";
        cout << "|      4. Exit            |\n";
        cout << "=========================\n";
        cout << "Select an option: ";

        cin >> option;

        // ------------------ 1) VIEW ------------------
        if (option == 1)
        {
            ifstream inFile("books.txt");
            if (!inFile.is_open())
            {
                cout << "Error opening books.txt!\n";
            }
            else
            {
                bool foundAny = false;
                string line;

                while (getline(inFile, line))
                {
                    if (line.empty())
                        continue;

                    string idStr, title, author, isbn, category, status;
                    stringstream ss(line);

                    if (!getline(ss, idStr, '|'))
                        continue;
                    if (!getline(ss, title, '|'))
                        continue;
                    if (!getline(ss, author, '|'))
                        continue;
                    if (!getline(ss, isbn, '|'))
                        continue;
                    if (!getline(ss, category, '|'))
                        continue;
                    if (!getline(ss, status))
                        continue;

                    cout << "ID: " << idStr
                         << "\tTitle: " << title
                         << "\tAuthor: " << author
                         << "\tISBN: " << isbn
                         << "\tCategory: " << category
                         << "\tStatus: " << (isAvailable(status) ? "Available" : "Borrowed")
                         << "\n";
                    
                    foundAny = true;
                }
                
                if (!foundAny)
                    cout << "No books found!\n";
                inFile.close();
            }
        }

        else if (option == 2)
        {
            int targetId;
            cout << "Enter Book ID to check out: ";
            cin >> targetId;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            ifstream in("books.txt");
            ofstream out("tmp.txt");

            if (!in.is_open() || !out.is_open())
            {
                cout << "File error!\n";
            }
            else
            {
                string line;
                bool found = false;
                bool changed = false;

                while (getline(in, line))
                {
                    if (line.empty())
                    {
                        out << "\n";
                        continue;
                    }

                    string idStr, title, author, isbn, category, status;
                    stringstream ss(line);

                    if (!getline(ss, idStr, '|') ||
                        !getline(ss, title, '|') ||
                        !getline(ss, author, '|') ||
                        !getline(ss, isbn, '|') ||
                        !getline(ss, category, '|') ||
                        !getline(ss, status))
                    {
                        out << line << "\n";
                        continue;
                    }

                    int idInt = 0;
                    stringstream sid(idStr);
                    sid >> idInt;

                    if (idInt == targetId)
                    {
                        found = true;

                        if (!isAvailable(status))
                        {
                            cout << "Already borrowed!\n";
                        }
                        else
                        {
                            status = "0";
                            changed = true;
                            cout << "Checked out successfully!\n";
                        }
                    }

                    out << idStr << "\t|"
                        << title << "\t|"
                        << author << "\t|"
                        << isbn << "\t|"
                        << category << "\t|"
                        << status << "\n";
                }

                in.close();
                out.close();

                if (!found)
                {
                    remove("tmp.txt");
                    cout << "Book ID not found!\n";
                }
                else if (!changed)
                {
                    remove("tmp.txt");
                }
                else
                {
                    remove("books.txt");
                    rename("tmp.txt", "books.txt");

                    createLoan(memberId, targetId);
                }
            }
        }

        // ------------------ 3) RETURN ------------------
        else if (option == 3)
        {
            int targetId;
            cout << "Enter Book ID to return: ";
            cin >> targetId;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            ifstream in("books.txt");
            ofstream out("tmp.txt");

            if (!in.is_open() || !out.is_open())
            {
                cout << "File error!\n";
            }
            else
            {
                string line;
                bool found = false;
                bool changed = false;

                while (getline(in, line))
                {
                    if (line.empty())
                    {
                        out << "\n";
                        continue;
                    }

                    string idStr, title, author, isbn, category, status;
                    stringstream ss(line);

                    if (!getline(ss, idStr, '|') ||
                        !getline(ss, title, '|') ||
                        !getline(ss, author, '|') ||
                        !getline(ss, isbn, '|') ||
                        !getline(ss, category, '|') ||
                        !getline(ss, status))
                    {
                        out << line << "\n";
                        continue;
                    }

                    int idInt = 0;
                    stringstream sid(idStr);
                    sid >> idInt;

                    if (idInt == targetId)
                    {
                        found = true;

                        if (isAvailable(status))
                        {
                            cout << "Already available!\n";
                        }
                        else
                        {
                            status = "1";
                            changed = true;
                            cout << "Returned successfully!\n";
                        }
                    }

                    out << idStr << "\t|"
                        << title << "\t|"
                        << author << "\t|"
                        << isbn << "\t|"
                        << category << "\t|"
                        << status << "\n";
                }

                in.close();
                out.close();

                if (!found)
                {
                    remove("tmp.txt");
                    cout << "Book ID not found!\n";
                }
                else if (!changed)
                {
                    remove("tmp.txt");
                }
                else
                {
                    remove("books.txt");
                    rename("tmp.txt", "books.txt");

                    closeLoan(memberId, targetId);
                }
            }
        }
        else if (option == 4)
        {
            cout << "Exiting Member Menu. Goodbye!\n";
            return;
        }
        else
        {
            cout << "Invalid option!\n";
        }

        cout << "Do you want to perform another action? (y/n): ";
        cin >> addMore;

    } while (addMore == 'y' || addMore == 'Y');
}

