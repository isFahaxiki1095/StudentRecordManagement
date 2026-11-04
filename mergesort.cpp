//
// Created by Feng Jie on 11/3/26.
//


#include "student.h"
using namespace std;

// Compare students by selected attribute
bool compareStudents(const Student& a, const Student& b, string field, bool ascending) {
    if (field == "id") {
        if (ascending) {
            return a.id < b.id;
        }
        else {
            return a.id > b.id;
        }
    }
    else if (field == "name") {
        if (ascending) {
            return a.name < b.name;
        }
        else {
            return a.name > b.name;
        }
    }
    else if (field == "age") {
        if (ascending) {
            return a.age < b.age;
        }
        else {
            return a.age > b.age;
        }
    }
    else if (field == "gpa") {
        if (ascending) {
            return a.gpa < b.gpa;
        }
        else {
            return a.gpa > b.gpa;
        }
    }

    return false;
}

// Merge
void merge(vector<Student>& students, int left, int mid, int right, string field, bool ascending, long long& comparisons) {

    vector<Student> temp;

    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {
        comparisons++;
        if (!compareStudents(students[j], students[i], field, ascending)) {
            temp.push_back(students[i]);
            i++;
        }
        else {
            temp.push_back(students[j]);
            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(students[i]);
        i++;
    }

    while (j <= right) {
        temp.push_back(students[j]);
        j++;
    }

    for (int k = 0; k < temp.size(); k++) {
        students[left + k] = temp[k];
    }
}

void mergeSort(vector<Student>& students, int left, int right, string field, bool ascending, long long& comparisons) {

    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSort(students, left, mid, field, ascending, comparisons);

    mergeSort(students, mid + 1, right, field, ascending, comparisons);

    merge(students, left, mid, right, field, ascending, comparisons);
}

bool isSortedCorrectly(const vector<Student>& students, string field, bool ascending) {

    if (field != "id" && field != "name" && field != "age" && field != "gpa") {
        return false;
    }

    for (int i = 1; i < students.size(); i++) {
        if (compareStudents(students[i], students[i - 1], field, ascending)) {
            return false;
        }
    }

    return true;
}
