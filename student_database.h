#pragma once
#include <vector>
#include <string>
#include <iostream>

struct Student {
    std::string name;
    int age;
    std::string major;
    double gpa;
};

// Объявления функций
void addStudent(std::vector<Student>& database);
void displayStudents(const std::vector<Student>& database);
void removeStudent(std::vector<Student>& database);