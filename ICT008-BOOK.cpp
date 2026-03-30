// ICT008-BOOK.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// =====================
//      BOOK CLASS
// =====================
class Book {
private:
    string title;
    string author;
    string isbn;
    bool availability;
    string dateAdd;

public:
    Book() {
        title = "";
        author = "";
        isbn = "";
        availability = true;
        dateAdd = "";
    }

    void setBookDetails(string t, string a, string i, bool avail, string date) {
        title = t;
        author = a;
        isbn = i;
        availability = avail;
        dateAdd = date;
    }

    void displayBookDetails() {
        cout << "----------------------------------" << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Availability: " << (availability ? "Available" : "Borrowed") << endl;
        cout << "Date Added: " << dateAdd << endl;
        cout << "----------------------------------" << endl;
    }

    bool borrowBook() {
        if (availability) {
            availability = false;
            return true;
        }
        return false;
    }

    void returnBook() { availability = true; }

    string getISBN() { return isbn; }
    string getTitle() { return title; }
    bool isAvailable() { return availability; }

    static void sortBookData(Book books[], int size) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (books[j].isbn > books[j + 1].isbn) {
                    Book temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
            }
        }
    }
};


// =====================
//     MAIN PROGRAM
// =====================
int main() {
    const int SIZE = 5;
    Book books[SIZE];

    // Initialise books

    books[0].setBookDetails("The Lightning Thief", "Rick Riordan", "1111", true, "2005");
    books[1].setBookDetails("The Hunger Games", "Suzanne Collins", "2222", true, "2008");
    books[2].setBookDetails("The Lion, the Witch and the Wardrobe", "C.S. Lewis", "3333", true, "1950");
    books[3].setBookDetails("City of Bones", "Cassandra Clare", "4444", true, "2007");
    books[4].setBookDetails("A Deadly Education", "Naomi Novik", "5555", true, "2020");


    Book::sortBookData(books, SIZE);

    int choice;
    string input;

    while (true) {

        // ========== MENU ==========
        cout << "\n===== LIBRARY MENU =====" << endl;
        cout << "1. Borrow a Book (by ISBN or Title)" << endl;
        cout << "2. See Available Books" << endl;
        cout << "3. Exit Program" << endl;
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore(); // Fix getline bug

        // ========== OPTION 3: EXIT ==========
        if (choice == 3) {
            cout << "Program terminated." << endl;
            break;
        }

        // ========== OPTION 2: SHOW AVAILABLE BOOKS ==========
        if (choice == 2) {
            cout << "\n===== AVAILABLE BOOKS =====\n";
            bool anyAvailable = false;

            for (int i = 0; i < SIZE; i++) {
                if (books[i].isAvailable()) {
                    books[i].displayBookDetails();
                    anyAvailable = true;
                }
            }

            if (!anyAvailable) {
                cout << "No books available right now.\n";
            }
            continue;
        }

        // ========== OPTION 1: BORROW ==========
        if (choice == 1) {
            cout << "\nEnter ISBN or Title (or type 0 to cancel): ";
            getline(cin, input);

            if (input == "0") {
                cout << "Borrow cancelled.\n";
                continue;
            }

            // Case-insensitive matching
            string loweredInput = input;
            transform(loweredInput.begin(), loweredInput.end(), loweredInput.begin(), ::tolower);

            bool found = false;

            for (int i = 0; i < SIZE; i++) {

                string loweredTitle = books[i].getTitle();
                transform(loweredTitle.begin(), loweredTitle.end(), loweredTitle.begin(), ::tolower);

                // MATCH BY ISBN OR TITLE
                if (books[i].getISBN() == input || loweredTitle == loweredInput) {
                    found = true;

                    if (books[i].isAvailable()) {
                        books[i].borrowBook();
                        cout << "\nBook Borrowed Successfully!\n";
                        books[i].displayBookDetails();
                    }
                    else {
                        cout << "\nThis book is currently unavailable! \n";
                    }
                    break;
                }
            }

            if (!found)
                cout << "\nBook not found. Please try again.\n";

            continue;
        }

        // ========== INVALID OPTION ==========
        cout << "\nInvalid option. Please choose 1, 2, or 3.\n";
    }
    return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
