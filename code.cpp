#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Book {
    int bookID;
    string title;
    string author;
    int quantity;
};

void addbook(vector<Book>& books);
void searchbook(const vector<Book>& books);
void displaybook(const vector<Book>& books);
void saveToFile(const vector<Book>& books);
void loadFromFile(vector<Book>& books);

int main() {
    vector<Book> books;
    loadFromFile(books);

    int choice;
    do {
        cout << "\n1. Add book" << endl;
        cout << "2. Search book" << endl;
        cout << "3. Display books" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addbook(books);
                break;
            case 2:
                searchbook(books);
                break;
            case 3:
                displaybook(books);
                break;
            case 4:
                saveToFile(books);
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

void addbook(vector<Book>& books) {
    Book book;
    cout << "Enter book ID: ";
    cin >> book.bookID;
    cout << "Enter title: ";
    cin.ignore();
    getline(cin, book.title);
    cout << "Enter author: ";
    getline(cin, book.author);
    cout << "Enter quantity: ";
    cin >> book.quantity;
    books.push_back(book);
    cout << "Book added successfully." << endl;
}

void searchbook(const vector<Book>& books) {
    cout << "Search by:\n1. ID\n2. Title\nEnter your choice: ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        int searchID;
        cout << "Enter book ID: ";
        cin >> searchID;

        for (const auto& book : books) {
            if (book.bookID == searchID) {
                cout << "Title: " << book.title << endl;
                cout << "Author: " << book.author << endl;
                cout << "Quantity: " << book.quantity << endl;
                return;
            }
        }
        cout << "Book not found." << endl;
    } else if (choice == 2) {
        string searchTitle;
        cout << "Enter book title: ";
        cin.ignore();
        getline(cin, searchTitle);

        for (const auto& book : books) {
            if (book.title == searchTitle) {
                cout << "ID: " << book.bookID << endl;
                cout << "Author: " << book.author << endl;
                cout << "Quantity: " << book.quantity << endl;
                return;
            }
        }
        cout << "Book not found." << endl;
    } else {
        cout << "Invalid choice." << endl;
    }
}

void displaybook(const vector<Book>& books) {
    if (books.empty()) {
        cout << "No books available in the library." << endl;
        return;
    }

    cout << "\nBooks in the library:" << endl;
    for (const auto& book : books) {
        cout << "ID: " << book.bookID << ", Title: " << book.title
             << ", Author: " << book.author << ", Quantity: " << book.quantity << endl;
    }
}

void saveToFile(const vector<Book>& books) {
    ofstream file("books.txt", ios::out); // Explicitly specifying the mode
    if (!file) {
        cerr << "Error: Could not create or open file for writing!" << endl;
        return;
    }

    for (const auto& book : books) {
        file << book.bookID << endl;
        file << book.title << endl;
        file << book.author << endl;
        file << book.quantity << endl;
    }

    file.close();
    cout << "Books saved to file successfully." << endl;
}

void loadFromFile(vector<Book>& books) {
    ifstream file("books.txt", ios::in); // Explicitly specifying the mode
    if (!file) {
        cerr << "Error: Could not open file for reading. Starting with an empty library." << endl;
        return;
    }

    Book book;
    while (file >> book.bookID) {
        file.ignore(); // Ignore the newline after bookID
        ///z
        ///nor khair de
        getline(file, book.title);
        getline(file, book.author);
        file >> book.quantity;
        file.ignore(); // Ignore the newline after quantity
         //vhvbhkkkhjkhkjh
        books.push_back(book);
    }

    file.close();
    cout << "Books loaded from file successfully." << endl;
}
