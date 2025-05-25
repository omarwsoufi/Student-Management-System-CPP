#include "Course.h"
#include <iostream>
#include <limits>

Course::Course(const std::string& name, const std::string& code, int credits)
    : courseName(name), courseCode(code), credits(credits), instructorCount(0), studentCount(0) {}

void Course::addInstructor(const std::string& instructorId) {
    if (instructorCount < MAX_INSTRUCTORS_PER_COURSE) {
        for (int i = 0; i < instructorCount; ++i) {
            if (instructorIds[i] == instructorId) return; // already added
        }
        instructorIds[instructorCount++] = instructorId;
    }
}

void Course::removeInstructor(const std::string& instructorId) {
    for (int i = 0; i < instructorCount; ++i) {
        if (instructorIds[i] == instructorId) {
            for (int j = i; j < instructorCount - 1; ++j) {
                instructorIds[j] = instructorIds[j + 1];
            }
            instructorCount--;
            return;
        }
    }
}

void Course::enrollStudent(const std::string& studentId) {
    for (int i = 0; i < studentCount; ++i) {
        if (studentIds[i] == studentId) return; // already enrolled
    }
    if (studentCount < MAX_STUDENTS_PER_COURSE) {
        studentIds[studentCount] = studentId;
        grades[studentCount] = 0.0f;
        studentCount++;
    }
}

void Course::dropStudent(const std::string& studentId) {
    for (int i = 0; i < studentCount; ++i) {
        if (studentIds[i] == studentId) {
            for (int j = i; j < studentCount - 1; ++j) {
                studentIds[j] = studentIds[j + 1];
                grades[j] = grades[j + 1];
            }
            studentCount--;
            return;
        }
    }
}

void Course::setGrade(const std::string& studentId, float grade) {
    for (int i = 0; i < studentCount; ++i) {
        if (studentIds[i] == studentId) {
            grades[i] = grade;
            return;
        }
    }
}

float Course::getGrade(const std::string& studentId) const {
    for (int i = 0; i < studentCount; ++i) {
        if (studentIds[i] == studentId) {
            return grades[i];
        }
    }
    return -1.0f; // not found
}

float Course::getMaxGrade() const {
    if (studentCount == 0) return 0.0f;
    float maxGrade = std::numeric_limits<float>::min();
    for (int i = 0; i < studentCount; ++i) {
        if (grades[i] > maxGrade) maxGrade = grades[i];
    }
    return maxGrade;
}

float Course::getMinGrade() const {
    if (studentCount == 0) return 0.0f;
    float minGrade = std::numeric_limits<float>::max();
    for (int i = 0; i < studentCount; ++i) {
        if (grades[i] < minGrade) minGrade = grades[i];
    }
    return minGrade;
}

float Course::getAverageGrade() const {
    if (studentCount == 0) return 0.0f;
    float sum = 0.0f;
    for (int i = 0; i < studentCount; ++i) {
        sum += grades[i];
    }
    return sum / studentCount;
}

std::string Course::getCode() const {
    return courseCode;
}

int Course::getCredits() const {
    return credits;
}

void Course::printStatistics() const {
    std::cout << "\n-- Course Statistics --\n";
    std::cout << "Max Grade: " << getMaxGrade() << "\n";
    std::cout << "Min Grade: " << getMinGrade() << "\n";
    std::cout << "Average Grade: " << getAverageGrade() << "\n";
}
std::string Course::getName() const {
    return name; // or whatever variable holds the course name
}
