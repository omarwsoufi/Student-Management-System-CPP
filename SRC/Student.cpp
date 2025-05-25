// === File: Student.cpp ===
#include "Student.h"
#include <iostream>
#include <iomanip>
#include "course.h"
Student::Student(const std::string& id, const std::string& username, const std::string& password, const std::string& name)
    : User(id, username, password), name(name), courseCount(0) {}

bool Student::registerCourse(const std::string& courseCode) {
    if (courseCount >= MAX_COURSES_PER_STUDENT) return false;
    for (int i = 0; i < courseCount; ++i) {
        if (coursesEnrolled[i] == courseCode) return false;
    }
    coursesEnrolled[courseCount] = courseCode;
    grades[courseCount] = -1.0f; // Not yet graded
    courseCount++;
    return true;
}

bool Student::dropCourse(const std::string& courseCode) {
    for (int i = 0; i < courseCount; ++i) {
        if (coursesEnrolled[i] == courseCode) {
            for (int j = i; j < courseCount - 1; ++j) {
                coursesEnrolled[j] = coursesEnrolled[j + 1];
                grades[j] = grades[j + 1];
            }
            courseCount--;
            return true;
        }
    }
    return false;
}

void Student::receiveGrade(const std::string& courseCode, float grade) {
    for (int i = 0; i < courseCount; ++i) {
        if (coursesEnrolled[i] == courseCode) {
            grades[i] = grade;
            return;
        }
    }
}

void Student::viewGrades() const {
    std::cout << "\n-- Grades --\n";
    for (int i = 0; i < courseCount; ++i) {
        std::cout << "Course: " << coursesEnrolled[i] << " | Grade: ";
        if (grades[i] < 0)
            std::cout << "Not Graded\n";
        else
            std::cout << std::fixed << std::setprecision(2) << grades[i] << "\n";
    }
}

float Student::calculateGPA(const Course allCourses[], int courseTotal) const {
    float totalPoints = 0.0f;
    int totalCredits = 0;

    for (int i = 0; i < courseCount; ++i) {
        if (grades[i] < 0) continue; // skip ungraded
        for (int j = 0; j < courseTotal; ++j) {
            if (allCourses[j].getCode() == coursesEnrolled[i]) {
                float gpa = (grades[i] / 100.0f) * 4.0f;
                totalPoints += gpa * allCourses[j].getCredits();
                totalCredits += allCourses[j].getCredits();
                break;
            }
        }
    }

    return (totalCredits > 0) ? (totalPoints / totalCredits) : 0.0f;
}
float Student::getGradeForCourse(const std::string& courseCode) const {
    for (int i = 0; i < courseCount; ++i) {
        if (coursesEnrolled[i] == courseCode) {
            return grades[i];  // returns grade or -1 if not graded yet
        }
    }
    return -1.0f;  // or another sentinel for course not found
}
