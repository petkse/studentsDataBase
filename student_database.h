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

// Функции с вводом/выводом для меню
void addStudent(std::vector<Student>& database);
void displayStudents(const std::vector<Student>& database);
void removeStudent(std::vector<Student>& database);

// Чистые функции для тестирования
void addStudentLogic(std::vector<Student>& database, const Student& s);
bool removeStudentLogic(std::vector<Student>& database, const std::string& name);