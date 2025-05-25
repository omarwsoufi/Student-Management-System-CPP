// === File: Administrator.h ===
#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "User.h"
#include "Course.h"
#include "Student.h"
#include "Instructor.h"
#include "Constants.h"  // For MAX_USERS, MAX_COURSES

class Administrator : public User {
public:
    Administrator(const std::string& id, const std::string& username, const std::string& password);

    void addUser(User* users[], int& userCount, User* newUser);
    void removeUser(User* users[], int& userCount, const std::string& userId);

    void addCourse(Course courses[], int& courseCount, const Course& course);
    void removeCourse(Course courses[], int& courseCount, const std::string& courseCode);
};

#endif // ADMINISTRATOR_H
