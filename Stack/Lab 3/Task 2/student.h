#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    std::string name;
    int grades[10];
    int numGrades;

public:
    Student();
    Student(std::string studentName, int studentGrades[], int count);
    
    void setName(std::string studentName);
    void setGrades(int studentGrades[], int count);
    
    std::string getName() const;
    int getGrade(int index) const;
    int getNumGrades() const;
    double getAverage() const;
    int getHighestGrade() const;
    int getLowestGrade() const;
    
    void display() const;
};

class StudentDatabase {
private:
    Student students[100];
    int numStudents;
    int numGrades;

public:
    StudentDatabase();
    
    void readFromFile(const std::string& filename);
    void addStudent(const Student& student);
    void displayAllStudents() const;
    void displayStudentByName(const std::string& name) const;
    void displayHighestAverage() const;
    void displayLowestAverage() const;
    int getNumStudents() const;
};

#endif