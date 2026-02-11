#include "Student.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

Student::Student() : name(""), numGrades(0) {
    for (int i = 0; i < 10; i++) {
        grades[i] = 0;
    }
}

Student::Student(std::string studentName, int studentGrades[], int count) 
    : name(studentName), numGrades(count) {
    for (int i = 0; i < count && i < 10; i++) {
        grades[i] = studentGrades[i];
    }
}

void Student::setName(std::string studentName) {
    name = studentName;
}

void Student::setGrades(int studentGrades[], int count) {
    numGrades = count;
    for (int i = 0; i < count && i < 10; i++) {
        grades[i] = studentGrades[i];
    }
}

std::string Student::getName() const {
    return name;
}

int Student::getGrade(int index) const {
    if (index >= 0 && index < numGrades) {
        return grades[index];
    }
    return 0;
}

int Student::getNumGrades() const {
    return numGrades;
}

double Student::getAverage() const {
    if (numGrades == 0) {
        return 0.0;
    }
    
    int sum = 0;
    for (int i = 0; i < numGrades; i++) {
        sum += grades[i];
    }
    return static_cast<double>(sum) / numGrades;
}

int Student::getHighestGrade() const {
    if (numGrades == 0) {
        return 0;
    }
    
    int highest = grades[0];
    for (int i = 1; i < numGrades; i++) {
        if (grades[i] > highest) {
            highest = grades[i];
        }
    }
    return highest;
}

int Student::getLowestGrade() const {
    if (numGrades == 0) {
        return 0;
    }
    
    int lowest = grades[0];
    for (int i = 1; i < numGrades; i++) {
        if (grades[i] < lowest) {
            lowest = grades[i];
        }
    }
    return lowest;
}

void Student::display() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Grades: ";
    for (int i = 0; i < numGrades; i++) {
        std::cout << grades[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Average: " << std::fixed << std::setprecision(2) << getAverage() << std::endl;
    std::cout << "Highest: " << getHighestGrade() << std::endl;
    std::cout << "Lowest: " << getLowestGrade() << std::endl;
}

StudentDatabase::StudentDatabase() : numStudents(0), numGrades(0) {}

void StudentDatabase::readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    
    if (!file.is_open()) {
        std::cout << "Error opening file: " << filename << std::endl;
        return;
    }
    
    file >> numStudents;
    file >> numGrades;
    file.ignore();
    
    for (int i = 0; i < numStudents && i < 100; i++) {
        std::string line;
        std::getline(file, line);
        
        std::istringstream iss(line);
        std::string firstName, lastName;
        iss >> firstName >> lastName;
        
        std::string fullName = firstName + " " + lastName;
        
        int tempGrades[10];
        int gradeCount = 0;
        int grade;
        while (iss >> grade && gradeCount < 10) {
            tempGrades[gradeCount] = grade;
            gradeCount++;
        }
        
        Student student(fullName, tempGrades, gradeCount);
        students[i] = student;
    }
    
    file.close();
    std::cout << "Successfully loaded " << numStudents << " students with " << numGrades << " grades each." << std::endl;
}

void StudentDatabase::addStudent(const Student& student) {
    if (numStudents < 100) {
        students[numStudents] = student;
        numStudents++;
    }
}

void StudentDatabase::displayAllStudents() const {
    std::cout << "\n=== All Students ===" << std::endl;
    for (int i = 0; i < numStudents; i++) {
        std::cout << "\nStudent " << (i + 1) << ":" << std::endl;
        students[i].display();
    }
}

void StudentDatabase::displayStudentByName(const std::string& name) const {
    bool found = false;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].getName() == name) {
            std::cout << "\n=== Student Found ===" << std::endl;
            students[i].display();
            found = true;
            break;
        }
    }
    
    if (!found) {
        std::cout << "Student with name '" << name << "' not found." << std::endl;
    }
}

void StudentDatabase::displayHighestAverage() const {
    if (numStudents == 0) {
        std::cout << "No students in database." << std::endl;
        return;
    }
    
    int topIndex = 0;
    double highestAvg = students[0].getAverage();
    
    for (int i = 1; i < numStudents; i++) {
        double avg = students[i].getAverage();
        if (avg > highestAvg) {
            highestAvg = avg;
            topIndex = i;
        }
    }
    
    std::cout << "\n=== Student with Highest Average ===" << std::endl;
    students[topIndex].display();
}

void StudentDatabase::displayLowestAverage() const {
    if (numStudents == 0) {
        std::cout << "No students in database." << std::endl;
        return;
    }
    
    int bottomIndex = 0;
    double lowestAvg = students[0].getAverage();
    
    for (int i = 1; i < numStudents; i++) {
        double avg = students[i].getAverage();
        if (avg < lowestAvg) {
            lowestAvg = avg;
            bottomIndex = i;
        }
    }
    
    std::cout << "\n=== Student with Lowest Average ===" << std::endl;
    students[bottomIndex].display();
}

int StudentDatabase::getNumStudents() const {
    return numStudents;
}

int main() {
    StudentDatabase database;
    
    std::cout << "=== Student Grades Database ===" << std::endl;
    std::cout << "\nReading data from file..." << std::endl;
    
    database.readFromFile("student.txt");
    
    database.displayAllStudents();
    
    database.displayHighestAverage();
    
    database.displayLowestAverage();
    
    std::cout << "\n=== Search for Specific Student ===" << std::endl;
    database.displayStudentByName("Sara Nazir");
    
    std::cout << "\n=== Total Students: " << database.getNumStudents() << " ===" << std::endl;
    
    return 0;
}