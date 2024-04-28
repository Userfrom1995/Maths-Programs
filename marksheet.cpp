#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate the total marks obtained
int calculateTotal(const vector<int>& marks) {
    int total = 0;
    for (int mark : marks) {
        total += mark;
    }
    return total;
}

// Function to calculate the percentage
float calculatePercentage(int totalMarks, int totalPossibleMarks) {
    return (static_cast<float>(totalMarks) / totalPossibleMarks) * 100.0;
}

// Function to determine grade based on percentage
string determineGrade(float percentage) {
    if (percentage >= 95)
        return "A+";
    else if (percentage >= 90)
        return "A";
    else if (percentage >= 85)
        return "B+";
    else if (percentage >= 80)
        return "B";
    else if (percentage >= 75)
        return "C+";
    else if (percentage >= 70)
        return "C";
    else if (percentage >= 65)
        return "D+";
    else if (percentage >= 60)
        return "D";
    else if (percentage >= 50)
        return "E+";
    else if (percentage >= 40)
        return "E";
    else
        return "F";
}

// Function to print the grading scale
void printGradingScale() {
    cout << "Grading Scale:" << endl;
    cout << "--------------" << endl;
    cout << "95 - 100: A+" << endl;
    cout << "90 - 94 : A " << endl;
    cout << "85 - 89 : B+" << endl;
    cout << "80 - 84 : B " << endl;
    cout << "75 - 79 : C+" << endl;
    cout << "70 - 74 : C " << endl;
    cout << "65 - 69 : D+ " << endl;
    cout << "60 - 64 : D " << endl;
    cout << "50 - 59 : E+ " << endl;
    cout << "40 - 59 : E " << endl;
    cout << "Below 40: F" << endl;
}

struct Student {
    string name;
    vector<int> marks;
    int totalMarks;
    float percentage;
    string grade;
};

// Function to compare students for sorting by percentage
bool compareStudents(const Student& s1, const Student& s2) {
    return s1.percentage > s2.percentage;
}

int main() {
    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;

    int numSubjects;
    cout << "Enter the number of subjects per student: ";
    cin >> numSubjects;

    vector<Student> students(numStudents);

    // Input data for each student
    for (int i = 0; i < numStudents; ++i) {
        cout << "\nEnter details for student " << i + 1 << ":" << endl;
        cout << "Name: ";
        cin >> students[i].name;
        students[i].marks.resize(numSubjects);
        cout << "Enter marks for each subject:" << endl;
        for (int j = 0; j < numSubjects; ++j) {
            cout << "Subject " << j + 1 << ": ";
            cin >> students[i].marks[j];
        }
        students[i].totalMarks = calculateTotal(students[i].marks);
        students[i].percentage = calculatePercentage(students[i].totalMarks, numSubjects * 100);
        students[i].grade = determineGrade(students[i].percentage);
    }
    // Sort students by percentage
    sort(students.begin(), students.end(), compareStudents);

    // Print grading scale
    printGradingScale();

    // Print marksheet for each student
    cout << "\nRank\tName\tTotal Marks\tPercentage\tGrade" << endl;
    cout << "---------------------------------------------------" << endl;
    for (int i = 0; i < numStudents; ++i) {
        cout << i + 1 << "\t" << students[i].name << "\t" << students[i].totalMarks << "\t\t"
             << fixed << setprecision(2) << students[i].percentage << "%\t\t" << students[i].grade << endl;
    }

    return 0;
}
