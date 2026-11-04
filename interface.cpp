#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>
#include "student.h"

using namespace std;

// Gets and validates a menu selection
int GetMenuChoice(string category, int min, int max) {
    int choice;

    while (true) {
        cout << "  Enter " << category << ": ";

        if (cin >> choice && choice >= min && choice <= max) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return choice;
        }

        cout << "  Invalid Input! Please Enter Valid Input for "
             << category << ".\n\n";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void Start_Menu(int dataSize) {
    cout << "\n";
    cout << "============================================================\n";
    cout << "              STUDENT RECORD MANAGEMENT SYSTEM\n";
    cout << "============================================================\n\n";

    cout << "  Total Students: " << dataSize << "\n\n";

    cout << "  1. Sort Students\n\n";
    cout << "  2. View Student Records\n\n";
    cout << "  3. Compare Algorithms\n\n";
    cout << "  4. Exit\n\n";

    cout << "------------------------------------------------------------\n";
}

SortOptions Sort_Options() {
    SortOptions options;
    cout << "\n";
    cout << "============================================================\n";
    cout << "                       SORT STUDENTS\n";
    cout << "============================================================\n\n";

    // Algorithm selection
    cout << "  Choose Algorithm:\n\n";
    cout << "    1. Merge Sort\n";
    cout << "    2. Quick Sort\n\n";

    int const algorithm = GetMenuChoice("Algorithm", 1,2);

    if (algorithm == 1) {
        options.isMerge = true;
    }
    if (algorithm == 2) {
        options.isMerge = false;
    }

    cout << "\n";
    cout << "------------------------------------------------------------\n\n";

    cout << "  Sort By:\n\n";

    cout << "    " << left << setw(25) << "1. Student ID" << "2. Name\n\n";
    cout << "    " << left << setw(25) << "3. Age" << "4. GPA\n\n";

    int const field = GetMenuChoice("Field", 1, 4);

    if (field == 1) {
        options.sortBy = "Student ID";
    }
    if (field == 2) {
        options.sortBy = "Name";
    }
    if (field == 3) {
        options.sortBy = "Age";
    }
    if (field == 4) {
        options.sortBy = "GPA";
    }

    cout << "\n";
    cout << "------------------------------------------------------------\n\n";

    // Sorting order selection
    cout << "  Order:\n\n";
    cout << "    1. Ascending\n";
    cout << "    2. Descending\n\n";

    int const orderChoice = GetMenuChoice("Order", 1, 2);

    if (orderChoice == 1) {
        options.order = "Ascending";
        options.isAscending = true;
    }
    if (orderChoice == 2) {
        options.order = "Descending";
        options.isAscending = false;
    }
    cout << "\n";
    cout << "============================================================\n";

    return options;
}


void View_Records(StudentLists const &lists) {

    int const listLength = static_cast<int>(lists.SortedList.size());
    if (listLength == 0) {
        cout << "\nNo Student records available.\n";
        return;
    }
    int const totalPages = (listLength + 9) / 10;
    int pageNumber = 1;
    int startIndex = 0;
    int endIndex = 9;
    bool Active = true;

    while (Active) {

        startIndex = (pageNumber - 1) * 10;
        endIndex = (pageNumber * 10) - 1;

        if (pageNumber == totalPages) {
            endIndex = listLength - 1;
        }

        cout << "\n";
        cout << "============================================================\n";
        cout << "                       STUDENT RECORDS\n";
        cout << "============================================================\n\n";

        cout << "+------------+-------------------------+-------+--------+\n";

        cout << "| " << left << setw(11) << "Student ID"
             << "| " << left << setw(24) << "Name"
             << "| " << left << setw(6) << "Age"
             << "| " << left << setw(7) << "GPA"
             << "|\n";

        cout << "+------------+-------------------------+-------+--------+\n";

        // Display 10 records
        for (int i = startIndex; i <= endIndex; i++) {
            const Student &student = lists.SortedList[i];

            cout << "| " << left << setw(11) << student.id
                 << "| " << left << setw(24) << student.name
                 << "| " << left << setw(6) << student.age
                 << "| " << left << setw(7) << fixed << setprecision(2) << student.gpa
                 << "|\n";
        }

        cout << "+------------+-------------------------+-------+--------+\n\n";

        cout << "  1. [Previous]        Page " << pageNumber
             << " / " << totalPages
             << "        2. [Next]\n\n";

        cout << "3. Jump to Certain Page\n";
        cout << "4. Exit to Main Menu\n\n";

        cout << "============================================================\n";


        int choice = GetMenuChoice("Choice", 1,  4);

        if (choice == 1) {
            if (pageNumber != 1) {
                pageNumber -= 1;
            }
        }
        if (choice == 2) {
            if (pageNumber != totalPages) {
                pageNumber += 1;
            }
        }
        if (choice == 3) {
            pageNumber = GetMenuChoice("Page Number", 1, totalPages);
        }
        if (choice == 4) {
            Active = false;
        }
    }
}





void Comparison_Menu(string const &dataSize, SortOptions const &sOptions,
                      MergeData const &mData, QuickData const &qData){

    //Convert correct bool into YES or NO String
    string mCorrectStr;
    string qCorrectStr;

    if (mData.correct) {
        mCorrectStr = "YES";
    }
    if (!mData.correct) {
        mCorrectStr = "NO";
    }
    if (qData.correct) {
        qCorrectStr = "YES";
    }
    if (!qData.correct) {
        qCorrectStr = "NO";
    }

    cout << "\n";
    cout << "============================================================\n";
    cout << "                    ALGORITHM COMPARISON\n";
    cout << "============================================================\n\n";

    cout << "  Dataset Size: " << dataSize << "\n";
    cout << "  Sort By:      " << sOptions.sortBy << "\n";
    cout << "  Order:        " << sOptions.order << "\n\n";
    cout << "------------------------------------------------------------\n";

    cout << left << setw(22) << "  " << setw(20) << "Merge Sort" << "Quick Sort\n";
    cout << "------------------------------------------------------------\n";

    cout << left << setw(22) << "  Runtime:" << setw(20)
         << (to_string(mData.runtime) + " ms") << qData.runtime << " ms\n";

    cout << left << setw(22) << "  Comparisons:" << setw(20)
         << mData.comparisons << qData.comparisons << "\n";

    cout << left << setw(22) << "  Correct:" << setw(20) << mCorrectStr << qCorrectStr << "\n";
    cout << "------------------------------------------------------------\n\n";

    cout << "  Merge Sort Space: O(n)\n";
    cout << "  Quick Sort Space: O(log n) average\n\n";

    cout << "============================================================\n\n";

    cout << "  1. Run Comparison Again\n";
    cout << "  2. Return to Main Menu\n\n";

    cout << "------------------------------------------------------------\n";
}


