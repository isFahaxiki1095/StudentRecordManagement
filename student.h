//
// Created by Feng Jie on 11/2/26.
//

#ifndef STUDENTRECORDMANAGEMENT_STUDENT_H
#define STUDENTRECORDMANAGEMENT_STUDENT_H

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

struct Student {
    int id;
    string name;
    int age;
    double gpa;
};

//This is to make sure every time we sort the list its sorting the randomized list
//And is saving the new sorted list elsewhere
//This could be done by copying the original random list and then sorting or however idm
struct StudentLists {
    vector<Student> BaseRandomList;
    vector<Student> SortedList;
};

//Stores Data from Merge sort of Student dataset
struct MergeData {
    double runtime = 0;
    long long comparisons = 0;
    bool correct = false;
};

//Stores Data from Quick sort of Student dataset
struct QuickData {
    double runtime = 0;
    long long comparisons = 0;
    bool correct = false;
};

//Stores Sort Options for Menu
struct SortOptions {
    //True for merge, false for quick
    bool isMerge = true;

    //Stored as "Student ID", "Name", "Age", "GPA"
    string sortBy;

    //Stored as "Ascending" or "Descending"
    string order;

    //Order bool to make everything easier
    //Ascending = true, Descending = false
    bool isAscending = true;
};


//============================================================
// CHRIS-JOHN - MENU AND INTERFACE FUNCTIONS
//============================================================


// GET MENU CHOICE
// Displays an input prompt and returns a validated integer.
// Parameters:
//   category - Name of the input being requested (e.g. "Choice", "Order")
//   min      - Minimum accepted integer
//   max      - Maximum accepted integer
// Automatically handles invalid inputs and requests re-entry.
// NOTE: This function prints its own "Enter [category]: " prompt.
int GetMenuChoice(string category, int min, int max);





// START MENU
// Displays the main menu with the following options:
//   1. Sort Students
//   2. View Student Records
//   3. Compare Algorithms
//   4. Exit
// Parameter: dataSize - Number of students in the dataset.
// NOTE: This function ONLY displays the menu.
// Main() must handle the user's selection and call the appropriate function.
// Use GetMenuChoice("Choice", 1, 4) to get validated input.
// Do not add a separate cin prompt in main().
void Start_Menu(int dataSize);





// SORT OPTIONS
// Displays the sorting menu and collects 3 selections:
//   Algorithm: 1. Merge Sort  2. Quick Sort
//   Sort By:   1. Student ID  2. Name  3. Age  4. GPA
//   Order:     1. Ascending   2. Descending
//
// RETURNS: A SortOptions struct containing:
//   isMerge     - true for Merge Sort, false for Quick Sort
//   sortBy      - "Student ID", "Name", "Age", or "GPA"
//   order       - "Ascending" or "Descending"
//   isAscending - true for Ascending, false for Descending
//
// NOTE: This function handles ALL input validation internally.
// Main() should save the returned struct and pass its values to
// the appropriate sorting algorithm.
// Sorting should always start from BaseRandomList, not a previously sorted list.
SortOptions Sort_Options();





// VIEW RECORDS
// Displays SortedList in a formatted table, 10 students per page.
// Handles its own menu navigation:
//   1. Previous Page
//   2. Next Page
//   3. Jump to Specific Page
//   4. Return to Main Menu
//
// Parameter: lists - StudentLists struct containing the student records.
// NOTE: This function handles ALL input and page navigation internally.
// Main() only needs to call View_Records(studentLists).
// When Exit is selected, control automatically returns to main().
//
// IMPORTANT: SortedList must contain records BEFORE calling this function.
// At program startup, initialize it using:
//   studentLists.SortedList = studentLists.BaseRandomList;
// This allows records to be viewed before any sorting has occurred.
// The function does not modify either list.
void View_Records(StudentLists const &lists);





// ALGORITHM COMPARISON
// Displays the performance comparison of Merge Sort and Quick Sort.
// Parameters:
//   dataSize - Dataset size displayed in the menu
//   sOptions - SortOptions containing the sorting field and order
//   mData    - MergeData containing runtime, comparisons, and correctness
//   qData    - QuickData containing runtime, comparisons, and correctness
//
// NOTE: This function ONLY displays the comparison results.
// Main() must:
//   1. Run BOTH sorting algorithms on independent copies of BaseRandomList.
//   2. Record runtime, comparison count, and correctness for each.
//   3. Pass the completed MergeData and QuickData structs to this function.
//   4. Handle the comparison menu selections:
//        1. Run Comparison Again
//        2. Return to Main Menu
//
// Do not compare algorithms using a previously sorted list.
// Each algorithm should receive the same original randomized dataset.
void Comparison_Menu(string const &dataSize, SortOptions const &sOptions,
                     MergeData const &mData, QuickData const &qData);






//Jie Feng - Functions
bool compareStudents(const Student& a, const Student& b, string field, bool ascending);

void mergeSort(vector<Student>& students, int left, int right, string field, bool ascending, long long& comparisons);

bool isSortedCorrectly(const vector<Student>& students, string field, bool ascending);


//Yuxi

// Generate student records
vector<Student> generateStudents(int count = 100000);

// Quick Sort
void quickSort(vector<Student>& students, int low, int high,
               string field, bool ascending, long long& comparisons);

// Check Quick Sort result
bool isQuickSortCorrect(const vector<Student>& students,
                        string field, bool ascending);

#endif //STUDENTRECORDMANAGEMENT_STUDENT_H