#include "StudentLib.h"
#include <iostream>
using namespace std;

int main() {
    StudentManager manager("students.csv");
    int choice;
    
    do {
        cout << "\nStudent Management System\n";
        cout << "1. Add new students\n";
        cout << "2. Display all students\n";
        cout << "3. Save to CSV\n";
        cout << "4. Load from CSV\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                int numStudents;
                cout << "Enter number of students: ";
                cin >> numStudents;
                cin.ignore();
                manager.addStudents(numStudents);
                break;
            }
            case 2:
                manager.displayAll();
                break;
            case 3:
                if (manager.saveToCSV()) {
                    cout << "Data saved successfully!\n";
                }
                break;
            case 4:
                if (manager.loadFromCSV()) {
                    cout << "Data loaded successfully!\n";
                }
                break;
        }
    } while (choice != 0);

    return 0;
}