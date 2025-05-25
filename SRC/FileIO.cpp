// === File: FileIO.cpp ===
#include <fstream>
#include <iostream>
#include "Student.h"
#include "Constants.h"

void saveStudentData(Student* students[], int studentCount, const Course courses[], int courseCount, const std::string& filename) {
    std::ofstream out(filename);
    if (!out) {
        std::cerr << "Error opening file for writing." << std::endl;
        return;
    }

    for (int i = 0; i < studentCount; ++i) {
        float gpa = students[i]->calculateGPA(courses, courseCount);
        out << students[i]->getId() << "," << students[i]->getUsername() << "," << gpa << "\n";
    }

    out.close();
    std::cout << "Student data saved to " << filename << "\n";
}

void displayStudentsByGPA(Student* students[], int studentCount, const Course courses[], int courseCount, float minGPA) {
    std::cout << "\nStudents with GPA >= " << minGPA << ":\n";

    for (int i = 0; i < studentCount; ++i) {
        float gpa = students[i]->calculateGPA(courses, courseCount);
        if (gpa >= minGPA) {
            std::cout << "- " << students[i]->getUsername() << " (GPA: " << gpa << ")\n";
        }
    }
}
