#include "student_database.h"

// Логика для тестов 
void addStudentLogic(std::vector<Student>& database, const Student& s) {
    database.push_back(s);
}

bool removeStudentLogic(std::vector<Student>& database, const std::string& name) {
    for (auto it = database.begin(); it != database.end(); ++it) {
        if (it->name == name) {
            database.erase(it);
            return true;
        }
    }
    return false;
}

// Функции для меню 
void addStudent(std::vector<Student>& database) {
    Student student;
    std::cout << "Введите имя студента: ";
    std::cin >> student.name;
    std::cout << "Введите возраст студента: ";
    std::cin >> student.age;
    std::cout << "Введите специальность студента: ";
    std::cin >> student.major;
    std::cout << "Введите средний балл студента: ";
    std::cin >> student.gpa;

    addStudentLogic(database, student);
    std::cout << "Студент добавлен в базу данных.\n";
}

void displayStudents(const std::vector<Student>& database) {
    std::cout << "Список студентов:\n";
    for (const Student& student : database) {
        std::cout << "Имя: " << student.name << "\n";
        std::cout << "Возраст: " << student.age << "\n";
        std::cout << "Специальность: " << student.major << "\n";
        std::cout << "Средний балл: " << student.gpa << "\n\n";
    }
}

void removeStudent(std::vector<Student>& database) {
    if (database.empty()) {
        std::cout << "База данных пуста.\n";
        return;
    }

    std::string name;
    std::cout << "Введите имя студента для удаления: ";
    std::cin >> name;

    if (removeStudentLogic(database, name))
        std::cout << "Студент удалён.\n";
    else
        std::cout << "Студент не найден.\n";
}