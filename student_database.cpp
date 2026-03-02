#include "student_database.h"

// Функция для добавления студента
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

    database.push_back(student);
    std::cout << "Студент добавлен в базу данных.\n";
}

// Функция для вывода всех студентов
void displayStudents(const std::vector<Student>& database) {
    std::cout << "Список студентов:\n";
    for (const Student& student : database) {
        std::cout << "Имя: " << student.name << "\n";
        std::cout << "Возраст: " << student.age << "\n";
        std::cout << "Специальность: " << student.major << "\n";
        std::cout << "Средний балл: " << student.gpa << "\n\n";
    }
}

// Функция для удаления студента
void removeStudent(std::vector<Student>& database) {
    if (database.empty()) {
        std::cout << "База данных пуста.\n";
        return;
    }

    std::string name;
    std::cout << "Введите имя студента для удаления: ";
    std::cin >> name;

    for (auto i = database.begin(); i != database.end(); ++i) {
        if (i->name == name) {
            database.erase(i);
            std::cout << "Студент удалён.\n";
            return;
        }
    }

    std::cout << "Студент не найден.\n";
}