#ifndef COURSE_H
#define COURSE_H

#include <string>
#include "Constants.h" // For MAX_INSTRUCTORS_PER_COURSE and MAX_STUDENTS_PER_COURSE

class Course {
private:
    std::string courseName;
    std::string courseCode;
    std::string instructorIds[MAX_INSTRUCTORS_PER_COURSE];
    int instructorCount;
    int credits;

    std::string studentIds[MAX_STUDENTS_PER_COURSE];
    float grades[MAX_STUDENTS_PER_COURSE];
    int studentCount;
    std::string name;
public:
    Course(const std::string& name, const std::string& code, int credits);

    void addInstructor(const std::string& instructorId);
    void removeInstructor(const std::string& instructorId);

    void enrollStudent(const std::string& studentId);
    void dropStudent(const std::string& studentId);
    void setGrade(const std::string& studentId, float grade);

    float getGrade(const std::string& studentId) const;
    float getMaxGrade() const;
    float getMinGrade() const;
    float getAverageGrade() const;

    std::string getCode() const;
    int getCredits() const;
    std::string getName() const;

    void printStatistics() const;
};

#endif // COURSE_H
