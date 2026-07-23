#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Student {
    int id;
    string name;
    vector<double> grades;
};

vector<Student> students;
int nextID = 1000;

void saveStudents() {
    ofstream file("gradeData.txt");

    if (!file) {
        cout << "Could not open gradeData.txt" << endl;
        return;
    }

    // One student is saved on each line: ID,Name,Grade,Grade,...
    for (int i = 0; i < students.size(); i++) {
        file << students[i].id << "," << students[i].name;

        for (int j = 0; j < students[i].grades.size(); j++) {
            file << "," << students[i].grades[j];
        }

        file << endl;
    }

    file.close();
}

void loadStudents() {
    ifstream file("gradeData.txt");

    if (!file) {
        return; // This is normal the first time the program is used.
    }

    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string idString;
        string gradeString;
        Student student;

        getline(ss, idString, ',');
        getline(ss, student.name, ',');

        if (idString.empty() || student.name.empty()) {
            continue;
        }

        student.id = stoi(idString);

        while (getline(ss, gradeString, ',')) {
            if (!gradeString.empty()) {
                student.grades.push_back(stod(gradeString));
            }
        }

        students.push_back(student);

        if (student.id >= nextID) {
            nextID = student.id + 1;
        }
    }

    file.close();
}

int findStudentByID(int id) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i].id == id) {
            return i;
        }
    }

    return -1;
}

double getAverage(Student student) {
    if (student.grades.size() == 0) {
        return 0;
    }

    double total = 0;

    for (int i = 0; i < student.grades.size(); i++) {
        total = total + student.grades[i];
    }

    return total / student.grades.size();
}

char getLetterGrade(double average) {
    if (average >= 90) {
        return 'A';
    } else if (average >= 80) {
        return 'B';
    } else if (average >= 70) {
        return 'C';
    } else if (average >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}

void showStudent(Student student) {
    cout << "ID: " << student.id << endl;
    cout << "Name: " << student.name << endl;

    if (student.grades.size() == 0) {
        cout << "Grades: No grades entered yet" << endl;
    } else {
        cout << "Grades: ";

        for (int i = 0; i < student.grades.size(); i++) {
            cout << fixed << setprecision(1) << student.grades[i];

            if (i < student.grades.size() - 1) {
                cout << ", ";
            }
        }

        double average = getAverage(student);
        cout << endl;
        cout << "Average: " << fixed << setprecision(2) << average << endl;
        cout << "Letter Grade: " << getLetterGrade(average) << endl;
    }
}

void showStudentIDs() {
    if (students.size() == 0) {
        cout << "There are no students yet." << endl;
        return;
    }

    cout << "Student List:" << endl;

    for (int i = 0; i < students.size(); i++) {
        cout << "ID: " << students[i].id << " - " << students[i].name << endl;
    }
}

void addStudent() {
    Student student;
    student.id = nextID;

    cin.ignore();
    cout << "Enter student name: ";
    getline(cin, student.name);

    if (student.name.empty()) {
        cout << "Student name cannot be blank." << endl;
        return;
    }

    students.push_back(student);
    nextID++;
    saveStudents();

    cout << student.name << " was added." << endl;
    cout << "Their student ID is " << student.id << "." << endl;
}

void addGrade() {
    if (students.size() == 0) {
        cout << "Add a student before adding a grade." << endl;
        return;
    }

    // The list appears here so the user does not need to remember an ID.
    showStudentIDs();

    int id;
    cout << "Enter student ID to add a grade: ";
    cin >> id;

    int index = findStudentByID(id);

    if (index == -1) {
        cout << "Student not found." << endl;
        return;
    }

    double grade;
    cout << "Enter grade (0-100): ";
    cin >> grade;

    if (grade < 0 || grade > 100) {
        cout << "Grade must be from 0 to 100." << endl;
        return;
    }

    students[index].grades.push_back(grade);
    saveStudents();
    cout << "Grade added for " << students[index].name << "." << endl;
}

void displayStudents() {
    if (students.size() == 0) {
        cout << "There are no students yet." << endl;
        return;
    }

    cout << "All Students and Grades" << endl;
    cout << "-----------------------" << endl;

    for (int i = 0; i < students.size(); i++) {
        showStudent(students[i]);
        cout << endl;
    }
}

void searchByName() {
    if (students.size() == 0) {
        cout << "There are no students yet." << endl;
        return;
    }

    string name;
    bool found = false;

    cin.ignore();
    cout << "Enter student name: ";
    getline(cin, name);

    for (int i = 0; i < students.size(); i++) {
        if (students[i].name == name) {
            showStudent(students[i]);
            found = true;
        }
    }

    if (found == false) {
        cout << "Student not found." << endl;
    }
}

void editGrade() {
    showStudentIDs();

    int id;
    cout << "Enter student ID: ";
    cin >> id;

    int index = findStudentByID(id);

    if (index == -1) {
        cout << "Student not found." << endl;
        return;
    }

    if (students[index].grades.size() == 0) {
        cout << "This student has no grades to edit." << endl;
        return;
    }

    cout << "Grades for " << students[index].name << ":" << endl;
    for (int i = 0; i < students[index].grades.size(); i++) {
        cout << i + 1 << ". " << students[index].grades[i] << endl;
    }

    int gradeNumber;
    cout << "Enter grade number to edit: ";
    cin >> gradeNumber;

    if (gradeNumber < 1 || gradeNumber > students[index].grades.size()) {
        cout << "Invalid grade number." << endl;
        return;
    }

    double newGrade;
    cout << "Enter the new grade (0-100): ";
    cin >> newGrade;

    if (newGrade < 0 || newGrade > 100) {
        cout << "Grade must be from 0 to 100." << endl;
        return;
    }

    students[index].grades[gradeNumber - 1] = newGrade;
    saveStudents();
    cout << "Grade updated." << endl;
}

void removeGrade() {
    showStudentIDs();

    int id;
    cout << "Enter student ID: ";
    cin >> id;

    int index = findStudentByID(id);

    if (index == -1) {
        cout << "Student not found." << endl;
        return;
    }

    if (students[index].grades.size() == 0) {
        cout << "This student has no grades to remove." << endl;
        return;
    }

    cout << "Grades for " << students[index].name << ":" << endl;
    for (int i = 0; i < students[index].grades.size(); i++) {
        cout << i + 1 << ". " << students[index].grades[i] << endl;
    }

    int gradeNumber;
    cout << "Enter grade number to remove: ";
    cin >> gradeNumber;

    if (gradeNumber < 1 || gradeNumber > students[index].grades.size()) {
        cout << "Invalid grade number." << endl;
        return;
    }

    students[index].grades.erase(students[index].grades.begin() + gradeNumber - 1);
    saveStudents();
    cout << "Grade removed." << endl;
}

int main() {
    loadStudents();

    int choice;

    do {
        cout << "Grade Manager" << endl;
        cout << "1. Add a student" << endl;
        cout << "2. Add a grade" << endl;
        cout << "3. View all students and grades" << endl;
        cout << "4. Look up a student ID by name" << endl;
        cout << "5. Show all student IDs" << endl;
        cout << "6. Edit a grade" << endl;
        cout << "7. Remove a grade" << endl;
        cout << "8. Save data to file" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice (1-9): ";
        cin >> choice;

        if (choice == 1) {
            addStudent();
        } else if (choice == 2) {
            addGrade();
        } else if (choice == 3) {
            displayStudents();
        } else if (choice == 4) {
            searchByName();
        } else if (choice == 5) {
            showStudentIDs();
        } else if (choice == 6) {
            editGrade();
        } else if (choice == 7) {
            removeGrade();
        } else if (choice == 8) {
            saveStudents();
            cout << "Data saved." << endl;
        } else if (choice == 9) {
            saveStudents();
            cout << "Good Bye!" << endl;
        } else {
            cout << "Invalid choice. Try again." << endl;
        }

        cout << endl;
    } while (choice != 9);

    return 0;
}
