#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Header-classes-library.h"
using namespace std;

// ===============================
// A3 TEST APPLICATION
// ===============================
int main() {

    // ✅ Create Author objects (dependency)
    Author author1(1, "Rick Riordan", "American");
    Author author2(2, "Naomi Novik", "American");
    Author author3(3, "Cassandra Clare", "American");

    // =====================================================
    // ✅ CORRECT BOOK INITIALISATION
    // =====================================================
    cout << "===== CORRECT BOOK INITIALISATION =====\n";

    Book* correct1 = new HardcopyBook(
        "The Lightning Thief",
        author1,
        "1111",
        true,
        "2005",
        "A10"
    );

    Book* correct2 = new EBook(
        "A Deadly Education",
        author2,
        "5555",
        true,
        "2020",
        "2030-12-31"
    );

    Book* correct3 = new HardcopyBook(
        "City of Bones",
        author3,
        "4444",
        true,
        "2007",
        "B07"
    );

    correct1->displayBookDetails();
    correct2->displayBookDetails();
    correct3->displayBookDetails();

    // =====================================================
    // ❌ INCORRECT BOOK INITIALISATION (same books)
    // =====================================================
    cout << "\n===== INCORRECT BOOK INITIALISATION =====\n";

    Book* incorrect1 = new HardcopyBook(
        "The Lightning Thief",
        author1,
        "ABC123",        // Invalid ISBN
        true,
        "2005",
        "A10"
    );

    Book* incorrect2 = new EBook(
        "A Deadly Education",
        author2,
        "5555",
        true,
        "Year2020",      // Invalid date
        "NoExpiry"       // Invalid licence
    );

    Book* incorrect3 = new HardcopyBook(
        "City of Bones",
        Author(),        // Missing author info
        "4444",
        true,
        "2007",
        "B07"
    );

    incorrect1->displayBookDetails();
    incorrect2->displayBookDetails();
    incorrect3->displayBookDetails();


    // =====================================================
    // ✅ SORTING TEST – ASCENDING ORDER (BY TITLE A → Z)
    // =====================================================
    cout << "\n===== SORTING TEST: ASCENDING (BY TITLE) =====\n";

    // Deliberately UNSORTED
    Book* asc[3] = {
        correct3,   // City of Bones
        correct1,   // The Lightning Thief
        correct2    // A Deadly Education
    };

    cout << "\n-- BEFORE SORT (ASCENDING) --\n";
    for (int i = 0; i < 3; i++)
        asc[i]->displayBookDetails();

    // Sort by TITLE ascending
    Book::sortBookData(asc, 3);

    cout << "\n-- AFTER SORT (ASCENDING) --\n";
    for (int i = 0; i < 3; i++)
        asc[i]->displayBookDetails();


    // =====================================================
    // ✅ SORTING TEST – DESCENDING ORDER (BY TITLE Z → A)
    // =====================================================
    cout << "\n===== SORTING TEST: DESCENDING (BY TITLE) =====\n";

    // Deliberately UNSORTED
    Book* desc[3] = {
        correct2,   // A Deadly Education
        correct3,   // City of Bones
        correct1    // The Lightning Thief
    };

    cout << "\n-- BEFORE SORT (DESCENDING) --\n";
    for (int i = 0; i < 3; i++)
        desc[i]->displayBookDetails();

    // Step 1: sort ascending
    Book::sortBookData(desc, 3);

    // Step 2: reverse array for descending order
    swap(desc[0], desc[2]);

    cout << "\n-- AFTER SORT (DESCENDING) --\n";
    for (int i = 0; i < 3; i++)
        desc[i]->displayBookDetails();


    return 0;
}