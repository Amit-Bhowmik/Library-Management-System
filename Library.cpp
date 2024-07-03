#include <bits/stdc++.h>
using namespace std;

class Lis
{
public:
    string id, name, author, search;
    fstream file;

    void addBooks();
    void allBooks();
    void extractBooks();
    void deleteBook();
} obj;

void displayMenu()
{
    cout << "\n--------Library Management System--------" << endl;
    cout << "1) Show all books" << endl;
    cout << "2) Extract books" << endl;
    cout << "3) Add a Book" << endl;
    cout << "4) Delete a Book" << endl;
    cout << "5) Exit" << endl;
}

int main()
{
    char choice;
    do
    {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To ignore the newline character left in the input buffer

        switch (choice)
        {
        case '1':
            obj.allBooks();
            break;
        case '2':
            obj.extractBooks();
            break;
        case '3':
            obj.addBooks();
            break;
        case '4':
            obj.deleteBook();
            break;
        case '5':
            cout << "Exiting the system." << endl;
            return 0;
        default:
            cout << "Invalid Input. Please try again." << endl;
        }
    } while (choice != '5');

    return 0;
}

void Lis::addBooks()
{
    cout << "\nEnter Book ID: ";
    getline(cin, id);
    cout << "Enter Book name: ";
    getline(cin, name);
    cout << "Enter Book's Author name: ";
    getline(cin, author);
    file.open("bookData.txt", ios::out | ios::app);
    file << id << " * " << name << " * " << author << endl;
    cout << "Book added successfully." << endl;
    file.close();
}

void Lis::allBooks()
{
    file.open("bookData.txt", ios::in);
    if (!file)
    {
        cout << "No data found." << endl;
        return;
    }

    cout << "\n\n";
    cout << "Book ID" << "\t\t" << "Book Name" << "\t" << "Author's Name" << endl;
    while (getline(file, id, '*') && getline(file, name, '*') && getline(file, author))
    {
        cout << id << "\t\t" << name << "\t\t" << author << endl;
    }
    file.close();
}

void Lis::extractBooks()
{
    cout << "Enter Book ID to extract: ";
    getline(cin, search);

    file.open("bookData.txt", ios::in);
    if (!file)
    {
        cout << "No data found." << endl;
        return;
    }

    bool found = false;
    cout << "\n\n";
    cout << "Book ID" << "\t\t" << "Book Name" << "\t" << "Author's Name" << endl;

    while (getline(file, id, '*') && getline(file, name, '*') && getline(file, author))
    {
        if (search == id)
        {
            cout << id << "\t\t" << name << "\t\t" << author << endl;
            cout << "Book extracted successfully." << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Book ID not found." << endl;
    }

    file.close();
}

void Lis::deleteBook()
{
    cout << "Enter Book ID to delete: ";
    getline(cin, search);

    file.open("bookData.txt", ios::in);
    if (!file)
    {
        cout << "No data found." << endl;
        return;
    }

    fstream tempFile("temp.txt", ios::out);
    bool found = false;

    while (getline(file, id, '*') && getline(file, name, '*') && getline(file, author))
    {
        if (search == id)
        {
            cout << "Deleting book with ID: " << id << endl;
            found = true;
        }
        else
        {
            tempFile << id << " * " << name << " * " << author << endl;
        }
    }

    if (!found)
    {
        cout << "Book ID not found." << endl;
    }
    else
    {
        cout << "Book deleted successfully." << endl;
    }

    file.close();
    tempFile.close();
    remove("bookData.txt");
    rename("temp.txt", "bookData.txt");
}
