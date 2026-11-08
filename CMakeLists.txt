cmake_minimum_required(VERSION 3.16)

project(StudentRecordManagement)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(StudentRecordManagement
        main.cpp
        mergesort.cpp
        quickSort.cpp
        studentsGenerator.cpp
        interface.cpp
)
