//
// Created by Feng Jie on 11/7/26.
//

#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include "student.h"

using namespace std;

int main() {

    StudentLists lists;

    lists.BaseRandomList = generateStudents(100000);
    lists.SortedList = lists.BaseRandomList;

    int choice = 0;
    while (choice != 4) {

        // Chris's main menu
        Start_Menu(static_cast<int>(lists.BaseRandomList.size()));
        choice = GetMenuChoice("Choice", 1, 4);

        if (choice == 1) {

            // Get sorting preferences from Chris's menu
            SortOptions options = Sort_Options();

            // Convert menu field names to sorting field names
            string field;

            if (options.sortBy == "Student ID") {
                field = "id";
            }
            else if (options.sortBy == "Name") {
                field = "name";
            }
            else if (options.sortBy == "Age") {
                field = "age";
            }
            else {
                field = "gpa";
            }

            // Reset to the original randomized records
            lists.SortedList = lists.BaseRandomList;

            long long comparisons = 0;

            // Start timer
            auto start = chrono::steady_clock::now();

            if (options.isMerge) {
                mergeSort(lists.SortedList, 0, static_cast<int>(lists.SortedList.size()) - 1, field, options.isAscending, comparisons);
            }
            else {
                quickSort(lists.SortedList, 0, static_cast<int>(lists.SortedList.size()) - 1, field, options.isAscending, comparisons);
            }

            // Stop timer
            auto end = chrono::steady_clock::now();

            double runtime = chrono::duration<double, milli>(end - start).count();

            // Verify sorting correctness
            bool correct;

            if (options.isMerge) {
                correct = isSortedCorrectly(lists.SortedList, field, options.isAscending);
            }
            else {
                correct = isQuickSortCorrect(lists.SortedList, field, options.isAscending);
            }

            cout << "\nSorting Completed!\n";
            cout << "Runtime: " << runtime << " ms\n";
            cout << "Comparisons: " << comparisons << "\n";

            if (correct) {
                cout << "Sorting Correct: YES\n";
            }
            else {
                cout << "Sorting Correct: NO\n";
            }

            // Chris's pagination
            View_Records(lists);
        }

        else if (choice == 2) {

            // View the current records
            View_Records(lists);
        }

        else if (choice == 3) {

            int comparisonChoice = 1;

            while (comparisonChoice == 1) {

                // Ask for comparison sorting preferences
                SortOptions options = Sort_Options();

                // Convert field name
                string field;

                if (options.sortBy == "Student ID") {
                    field = "id";
                }
                else if (options.sortBy == "Name") {
                    field = "name";
                }
                else if (options.sortBy == "Age") {
                    field = "age";
                }
                else {
                    field = "gpa";
                }

                // Use identical copies of the original dataset
                vector<Student> mergeStudents = lists.BaseRandomList;
                vector<Student> quickStudents = lists.BaseRandomList;

                MergeData mergeData;
                QuickData quickData;

                // Measure Merge Sort performance
                auto mergeStart = chrono::steady_clock::now();

                mergeSort(mergeStudents, 0,
                          static_cast<int>(mergeStudents.size()) - 1, field, options.isAscending, mergeData.comparisons);

                auto mergeEnd = chrono::steady_clock::now();

                mergeData.runtime = chrono::duration<double, milli>(
                    mergeEnd - mergeStart).count();

                mergeData.correct = isSortedCorrectly(mergeStudents, field, options.isAscending);

                // Measure Quick Sort performance
                auto quickStart = chrono::steady_clock::now();

                quickSort(quickStudents, 0,
                          static_cast<int>(quickStudents.size()) - 1, field, options.isAscending, quickData.comparisons);

                auto quickEnd = chrono::steady_clock::now();

                quickData.runtime = chrono::duration<double, milli>(quickEnd - quickStart).count();

                quickData.correct = isQuickSortCorrect(quickStudents, field, options.isAscending);

                // Chris's performance comparison display
                Comparison_Menu(
                    to_string(lists.BaseRandomList.size()),options,mergeData,quickData
                );

                // 1 = Compare again, 2 = Main menu
                comparisonChoice = GetMenuChoice("Choice", 1, 2);
            }
        }

        else if (choice == 4) {
            cout << "\nGoodbye!\n";
        }
    }

    return 0;
}
