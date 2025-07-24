#ifndef STUDENT_LIB_H
#define STUDENT_LIB_H

#include <string>
#include <vector>

class STUDENT {
private:
    int id;
    char name[50];
    int age;
    float gpa;

public:
    STUDENT(int id = 0, const char* name = "", int age = 0, float gpa = 0.0f);
    void inputData();
    
    // Getter methods
    int getId() const;
    const char* getName() const;
    int getAge() const;
    float getGPA() const;
    
    // CSV methods
    std::string toCSV() const;
    static STUDENT fromCSV(const std::string& line);
};

class StudentManager {
private:
    std::vector<STUDENT> students;
    std::string filename;

public:
    StudentManager(const std::string& csvFile = "students.csv");
    void addStudent(const STUDENT& student);
    void addStudents(int count);
    void displayAll() const;
    bool saveToCSV() const;
    bool loadFromCSV();
    size_t getCount() const;
};

#endif