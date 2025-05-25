#ifndef FILEIO_H
#define FILEIO_H

#include "Student.h"
#include "Course.h"
#include <string>

void saveStudentData(Student* students[], int studentCount, const Course courses[], int courseCount, const std::string& filename);
void displayStudentsByGPA(Student* students[], int studentCount, const Course courses[], int courseCount, float minGPA);

#endif // FILEIO_H
