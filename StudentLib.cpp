#include "StudentLib.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;

// STUDENT class implementations
STUDENT::STUDENT(int id, const char* name, int age, float gpa) {
    this->id = id;
    strncpy(this->name, name, sizeof(this->name) - 1);
    this->name[sizeof(this->name) - 1] = '\0';
    this->age = age;
    this->gpa = gpa;
}

void STUDENT::inputData() {
    cout << "Enter ID: ";
    cin >> id;
    cin.ignore();
    
    cout << "Enter Name: ";
    cin.getline(name, sizeof(name));
    
    cout << "Enter Age: ";
    cin >> age;
    
    cout << "Enter GPA: ";
    cin >> gpa;
}

int STUDENT::getId() const { return id; }
const char* STUDENT::getName() const { return name; }
int STUDENT::getAge() const { return age; }
float STUDENT::getGPA() const { return gpa; }

string STUDENT::toCSV() const {
    stringstream ss;
    ss << id << "," << name << "," << age << "," << gpa;
    return ss.str();
}

STUDENT STUDENT::fromCSV(const string& line) {
    stringstream ss(line);
    string id_str, name_str, age_str, gpa_str;
    
    getline(ss, id_str, ',');
    getline(ss, name_str, ',');
    getline(ss, age_str, ',');
    getline(ss, gpa_str, ',');
    
    return STUDENT(stoi(id_str), name_str.c_str(), 
                  stoi(age_str), stof(gpa_str));
}

// StudentManager class implementations
StudentManager::StudentManager(const string& csvFile) : filename(csvFile) {
    loadFromCSV();
}

void StudentManager::addStudent(const STUDENT& student) {
    students.push_back(student);
}

void StudentManager::addStudents(int count) {
    for(int i = 0; i < count; i++) {
        cout << "\nEnter data for student " << i + 1 << ":\n";
        STUDENT student;
        student.inputData();
        addStudent(student);
    }
}

void StudentManager::displayAll() const {
    cout << "\nStudent Information:\n";
    cout << "-------------------\n";
    for(size_t i = 0; i < students.size(); i++) {
        cout << "Student " << i + 1 << ": "
             << "ID = " << students[i].getId() 
             << ", Name = " << students[i].getName() 
             << ", Age = " << students[i].getAge() 
             << ", GPA = " << students[i].getGPA() << endl;
    }
}

bool StudentManager::saveToCSV() const {
    ofstream file(filename, ios::app);
    if (!file.is_open()) {
        cout << "Error: Could not open file for writing!" << endl;
        return false;
    }
    
    for (const auto& student : students) {
        file << student.toCSV() << endl;
    }
    file.close();
    return true;
}

bool StudentManager::loadFromCSV() {
    students.clear();
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Could not open file for reading!" << endl;
        return false;
    }
    
    string line;
    while (getline(file, line)) {
        if (!line.empty()) {
            students.push_back(STUDENT::fromCSV(line));
        }
    }
    file.close();
    return true;
}

size_t StudentManager::getCount() const {
    return students.size();
}