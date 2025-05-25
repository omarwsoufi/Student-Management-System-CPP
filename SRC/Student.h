// === File: Student.h ===
#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include "Course.h"
#include "Constants.h"
#include <string>

class Student : public User {
private:
    std::string name;
    std::string coursesEnrolled[MAX_COURSES_PER_STUDENT];
    float grades[MAX_COURSES_PER_STUDENT];
    int courseCount;

public:
    Student(const std::string& id, const std::string& username, const std::string& password, const std::string& name);

    bool registerCourse(const std::string& courseCode);
    bool dropCourse(const std::string& courseCode);

    void receiveGrade(const std::string& courseCode, float grade); // replaces updateGrade
    void viewGrades() const;

    float calculateGPA(const Course allCourses[], int courseTotal) const;
    float getGradeForCourse(const std::string& courseCode) const;


};

#endif // STUDENT_H
