#include <gtest/gtest.h>
#include <algorithm>
#include "student_database.h"

// Вспомогательная функция для проверки существования студента
bool studentExists(const std::vector<Student>& db, const std::string& name) {
    for (const auto& s : db) {
        if (s.name == name) return true;
    }
    return false;
}

// Юнит-тест 1: Добавление студента вручную
TEST(StudentTest, AddStudentManual) {
    std::vector<Student> db;
    Student s{"Andrew", 19, "Math", 4.7};
    db.push_back(s);
    EXPECT_TRUE(studentExists(db, "Andrew"));
}

// Юнит-тест 2: Удаление студента
TEST(StudentTest, RemoveStudentManual) {
    std::vector<Student> db;
    db.push_back({"Ivan", 21, "IT", 4.5});

    auto it = std::remove_if(db.begin(), db.end(),
        [](const Student& st){ return st.name == "Ivan"; });

    db.erase(it, db.end());

    EXPECT_FALSE(studentExists(db, "Ivan"));
}

// Юнит-тест 3: Добавление нескольких студентов
TEST(StudentTest, MultipleAdd) {
    std::vector<Student> db;
    db.push_back({"Egor", 22, "Physics", 3.8});
    db.push_back({"Ksenia", 23, "Chemistry", 4.1});
    EXPECT_TRUE(studentExists(db, "Egor"));
    EXPECT_TRUE(studentExists(db, "Ksenia"));
}

// Юнит-тест 4: Попытка удалить несуществующего студента
TEST(StudentTest, RemoveNonExistent) {
    std::vector<Student> db;
    db.push_back({"Kate", 24, "Biology", 3.9});
    auto size_before = db.size();
    auto it = std::remove_if(db.begin(), db.end(), [](const Student& st){ return st.name == "Frank"; });
    db.erase(it, db.end());
    EXPECT_EQ(db.size(), size_before);
}

// Юнит-тест 5: Проверка правильности данных студента
TEST(StudentTest, CorrectStudentData) {
    Student s{"Fedor", 25, "Economics", 4.2};
    EXPECT_EQ(s.name, "Fedor");
    EXPECT_EQ(s.age, 25);
    EXPECT_EQ(s.major, "Economics");
    EXPECT_DOUBLE_EQ(s.gpa, 4.2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}