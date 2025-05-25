// === File: Administrator.cpp ===
#include "Administrator.h"
#include <iostream>

Administrator::Administrator(const std::string& id, const std::string& username, const std::string& password)
    : User(id, username, password) {}

void Administrator::addUser(User* users[], int& userCount, User* newUser) {
    if (userCount < MAX_USERS) {
        users[userCount++] = newUser;
        std::cout << "User added successfully.\n";
    } else {
        std::cout << "User limit reached.\n";
    }
}

void Administrator::removeUser(User* users[], int& userCount, const std::string& userId) {
    for (int i = 0; i < userCount; ++i) {
        if (users[i]->getId() == userId) {
            delete users[i];
            for (int j = i; j < userCount - 1; ++j) {
                users[j] = users[j + 1];
            }
            userCount--;
            std::cout << "User removed.\n";
            return;
        }
    }
    std::cout << "User not found.\n";
}

void Administrator::addCourse(Course courses[], int& courseCount, const Course& course) {
    if (courseCount < MAX_COURSES) {
        courses[courseCount++] = course;
        std::cout << "Course added successfully.\n";
    } else {
        std::cout << "Course limit reached.\n";
    }
}

void Administrator::removeCourse(Course courses[], int& courseCount, const std::string& courseCode) {
    for (int i = 0; i < courseCount; ++i) {
        if (courses[i].getCode() == courseCode) {
            for (int j = i; j < courseCount - 1; ++j) {
                courses[j] = courses[j + 1];
            }
            courseCount--;
            std::cout << "Course removed.\n";
            return;
        }
    }
    std::cout << "Course not found.\n";
}
