
# Student Record Management System

This is a C++ console program that generates 100,000 student records. Users can sort the records using Merge Sort or Quick Sort, view student information, and compare the performance of the two algorithms.

## How to Run

The program requires a C++17 compiler and CMake 3.16 or newer.

1. Download or clone the GitHub repository.
2. Open a terminal in the project folder containing CMakeLists.txt.
3. Build the program using these commands:

   cmake -S . -B build
   cmake --build build

4. Run the executable from the terminal.

On Windows (MinGW):

   .\build\StudentRecordManagement.exe

On Windows (Visual Studio compiler):

   .\build\Debug\StudentRecordManagement.exe

On macOS/Linux:

   ./build/StudentRecordManagement

Alternatively, open the project in CLion, build it, and run the StudentRecordManagement target.

All program interaction takes place through the console.

## Using the Program

When the program starts, it automatically generates 100,000 student records and displays the main menu.

The menu has four options:

1. Sort Students - Choose Merge Sort or Quick Sort, select a field (ID, name, age, or GPA), and choose ascending or descending order.

2. View Student Records - View the student list in pages of 10 records. Users can move between pages or jump to a specific page.

3. Compare Algorithms - Run both sorting algorithms on the same dataset and compare their runtimes, comparison counts, and sorting correctness.

4. Exit - Close the program.

To navigate the menus, enter the number corresponding to the desired option.

No external data files are needed.
