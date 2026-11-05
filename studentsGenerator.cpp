
#include "student.h"
#include <random>
#include <stdexcept>
using namespace std;

// Yuxi - Generate Student Data

vector<Student> generateStudents(int count) {

    if (count < 0 || count > 100000) {
        throw invalid_argument("Invalid student count");
    }

    vector<string> firstNames = {
        "James", "John", "Michael", "David", "Daniel",
        "Alex", "Ryan", "Chris", "Kevin", "Andrew",
        "Emily", "Sarah", "Jessica", "Ashley", "Emma",
        "Olivia", "Sophia", "Grace", "Hannah", "Mia"
    };

    vector<string> lastNames = {
        "Smith", "Johnson", "Williams", "Brown", "Jones",
        "Garcia", "Miller", "Davis", "Wilson", "Anderson",
        "Taylor", "Thomas", "Lee", "Martin", "Clark",
        "Lewis", "Walker", "Hall", "Allen", "Young"
    };

    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> firstDist(0, firstNames.size() - 1);
    uniform_int_distribution<int> lastDist(0, lastNames.size() - 1);
    uniform_int_distribution<int> ageDist(18, 25);
    uniform_int_distribution<int> gpaDist(0, 400);

    vector<Student> students;

    for (int i = 0; i < count; i++) {

        Student s;

        s.id = 100001 + i;

        s.name = firstNames[firstDist(gen)] + " " +
                 lastNames[lastDist(gen)];

        s.age = ageDist(gen);

        s.gpa = gpaDist(gen) / 100.0;

        students.push_back(s);
    }

    return students;
}
