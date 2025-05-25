// === File: Instructor.h ===
#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include "User.h"
#include "Course.h"
#include "Constants.h"
#include <string>
#include "Student.h"

class Instructor : public User {
private:
    std::string name;
    std::string coursesTaught[MAX_COURSES_PER_INSTRUCTOR];
    int courseCount;

public:
    Instructor(const std::string& id, const std::string& username, const std::string& password, const std::string& name);

    bool addCourse(const std::string& courseCode);
    bool removeCourse(const std::string& courseCode);

    void updateStudentGrade(Course& course, const std::string& studentId, float grade, User* users[], int userCount);

    void viewStats(const Course& course, Student* students[], int studentCount);


    const std::string& getName() const { return name; }
};

#endif // INSTRUCTOR_H
