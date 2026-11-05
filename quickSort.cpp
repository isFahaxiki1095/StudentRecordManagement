
#include "student.h"
#include <algorithm>
using namespace std;

// Yuxi - Quick Sort

// Compare two students based on the field selected
bool quickCompare(const Student& a, const Student& b, string field, bool ascending) {

    if (field == "id" || field == "Student ID") {
        if (ascending) {
            return a.id < b.id;
        }
        else {
            return a.id > b.id;
        }
    }
    else if (field == "name" || field == "Name") {
        if (ascending) {
            return a.name < b.name;
        }
        else {
            return a.name > b.name;
        }
    }
    else if (field == "age" || field == "Age") {
        if (ascending) {
            return a.age < b.age;
        }
        else {
            return a.age > b.age;
        }
    }
    else if (field == "gpa" || field == "GPA") {
        if (ascending) {
            return a.gpa < b.gpa;
        }
        else {
            return a.gpa > b.gpa;
        }
    }

    return false;
}


// Divide the list around a pivot
int quickPartition(vector<Student>& students, int low, int high,
                   string field, bool ascending, long long& comparisons) {

    Student pivot = students[low + (high - low) / 2];

    int i = low - 1;
    int j = high + 1;

    while (true) {

        do {
            i++;
            comparisons++;
        } while (quickCompare(students[i], pivot, field, ascending));

        do {
            j--;
            comparisons++;
        } while (quickCompare(pivot, students[j], field, ascending));

        if (i >= j) {
            return j;
        }

        swap(students[i], students[j]);
    }
}


// Quick Sort function
void quickSort(vector<Student>& students, int low, int high,
               string field, bool ascending, long long& comparisons) {

    if (students.empty() || low < 0 ||
        high >= static_cast<int>(students.size()) || low >= high) {
        return;
    }

    int pivotIndex = quickPartition(students, low, high,
                                    field, ascending, comparisons);

    quickSort(students, low, pivotIndex,
              field, ascending, comparisons);

    quickSort(students, pivotIndex + 1, high,
              field, ascending, comparisons);
}


// Check if the list is sorted correctly
bool isQuickSortCorrect(const vector<Student>& students,
                        string field, bool ascending) {

    if (field != "id" && field != "Student ID" &&
        field != "name" && field != "Name" &&
        field != "age" && field != "Age" &&
        field != "gpa" && field != "GPA") {
        return false;
    }

    for (int i = 1; i < static_cast<int>(students.size()); i++) {

        if (quickCompare(students[i], students[i - 1], field, ascending)) {
            return false;
        }
    }

    return true;
}
