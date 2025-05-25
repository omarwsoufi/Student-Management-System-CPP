// === File: Instructor.cpp ===
#include "Instructor.h"
#include "Student.h"
#include <iostream>
#include "Course.h"
Instructor::Instructor(const std::string& id, const std::string& username, const std::string& password, const std::string& name)
    : User(id, username, password), name(name), courseCount(0) {}

bool Instructor::addCourse(const std::string& courseCode) {
    if (courseCount >= MAX_COURSES_PER_INSTRUCTOR) return false;
    for (int i = 0; i < courseCount; ++i) {
        if (coursesTaught[i] == courseCode) return false;
    }
    coursesTaught[courseCount++] = courseCode;
    return true;
}

bool Instructor::removeCourse(const std::string& courseCode) {
    for (int i = 0; i < courseCount; ++i) {
        if (coursesTaught[i] == courseCode) {
            for (int j = i; j < courseCount - 1; ++j) {
                coursesTaught[j] = coursesTaught[j + 1];
            }
            courseCount--;
            return true;
        }
    }
    return false;
}

void Instructor::updateStudentGrade(Course& course, const std::string& studentId, float grade, User* users[], int userCount) {
    course.setGrade(studentId, grade);
    std::cout << "Grade updated.\n";

    for (int i = 0; i < userCount; ++i) {
        Student* student = dynamic_cast<Student*>(users[i]);
        if (student && student->getId() == studentId) {
            student->receiveGrade(course.getCode(), grade);
            break;
        }
    }
}

void Instructor::viewStats(const Course& course, Student* students[], int studentCount) {
    float total = 0;
    float maxGrade = -1;
    float minGrade = 101;
    int count = 0;

    for (int i = 0; i < studentCount; ++i) {
        float grade = students[i]->getGradeForCourse(course.getCode());

        if (grade >= 0) {  // assume -1 means no grade
            total += grade;
            if (grade > maxGrade) maxGrade = grade;
            if (grade < minGrade) minGrade = grade;
            ++count;
        }
    }

    if (count == 0) {
        std::cout << "No students have grades for this course.\n";
        return;
    }

    std::cout << "\n-- Course Stats --\n";
    std::cout << "Course: " << course.getName() << "\n";
    std::cout << "Average Grade: " << (total / count)
              << " | Highest: " << maxGrade
              << " | Lowest: " << minGrade << "\n";
}
