#include <iostream>
#include <string>
#include <limits>
#include "Constants.h"
#include "Administrator.h"
#include "Instructor.h"
#include "Student.h"
#include "Course.h"
#include "FileIO.h"

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

User* loginUser(User* users[], int userCount) {
    std::string username, password;
    std::cout << "\nLogin\n------\n";
    std::cout << "Username: "; std::cin >> username;
    std::cout << "Password: "; std::cin >> password;

    for (int i = 0; i < userCount; ++i) {
        if (users[i]->authenticate(username, password)) {
            std::cout << "\nLogin successful!\n";
            return users[i];
        }
    }
    std::cout << "\nInvalid credentials.\n";
    return nullptr;
}

void showAllCourses(Course* courses[], int courseCount) {
    std::cout << "\n-- Available Courses --\n";
    for (int i = 0; i < courseCount; ++i) {
        std::cout << "Code: " << courses[i]->getCode()
                  << " | Avg Grade: " << courses[i]->getAverageGrade() << "\n";
    }
}

Course* findCourse(Course* courses[], int courseCount, const std::string& code) {
    for (int i = 0; i < courseCount; ++i) {
        if (courses[i]->getCode() == code) return courses[i];
    }
    return nullptr;
}

int main() {
    User* users[MAX_USERS];
    int userCount = 0;

    Course* courses[MAX_COURSES];
    int courseCount = 0;

    std::string uname, id, pwd;
    std::cout << "Setup Admin Account\n-------------------\n";
    std::cout << "Admin ID: "; std::cin >> id;
    std::cout << "Username: "; std::cin >> uname;
    std::cout << "Password: "; std::cin >> pwd;

    Administrator* admin = new Administrator(id, uname, pwd);
    users[userCount++] = admin;

    bool running = true;
    while (running) {
        std::cout << "\n==== Student Management System ====\n";
        std::cout << "1. Login\n2. Exit\nChoose an option: ";
        int choice;
        std::cin >> choice; clearInput();

        if (choice == 1) {
            User* currentUser = loginUser(users, userCount);
            if (!currentUser) continue;

            if (Administrator* a = dynamic_cast<Administrator*>(currentUser)) {
                int opt;
                do {
                    std::cout << "\n-- Admin Menu --\n";
                    std::cout << "1. Add User\n2. Remove User\n3. Add Course\n4. Remove Course\n";
                    std::cout << "5. Show All Courses\n6. Logout\n7. Save Student Data to File\n8. Show Students by GPA\nChoose an option: ";
                    std::cin >> opt; clearInput();

                    if (opt == 1) {
                        std::string uid, uname, pwd, name;
                        int type;
                        std::cout << "Enter 1 for Student, 2 for Instructor: "; std::cin >> type; clearInput();
                        std::cout << "ID: "; std::cin >> uid;
                        std::cout << "Username: "; std::cin >> uname;
                        std::cout << "Password: "; std::cin >> pwd;
                        std::cout << "Name: "; clearInput(); std::getline(std::cin, name);

                        User* newUser = (type == 1) ? static_cast<User*>(new Student(uid, uname, pwd, name))
                                                   : static_cast<User*>(new Instructor(uid, uname, pwd, name));
                        if (userCount < MAX_USERS) {
                            a->addUser(users, userCount, newUser);
                            std::cout << "User added.\n";
                        } else {
                            std::cout << "User limit reached.\n";
                        }

                    } else if (opt == 2) {
                        std::string uid;
                        std::cout << "Enter ID of user to remove: "; std::cin >> uid;
                        std::cout << "Are you sure you want to remove user " << uid << "? (y/n): ";
                        char confirm; std::cin >> confirm;
                        if (confirm == 'y' || confirm == 'Y') a->removeUser(users, userCount, uid);

                    } else if (opt == 3) {
                        std::string cname, cid;
                        int credits;
                        std::cout << "Course Name: "; clearInput(); std::getline(std::cin, cname);
                        std::cout << "Course Code: "; std::cin >> cid;
                        std::cout << "Credits: "; std::cin >> credits;

                        if (courseCount < MAX_COURSES) {
                            Course* c = new Course(cname, cid, credits);
                            courses[courseCount++] = c;
                            std::cout << "Course added.\n";
                        } else {
                            std::cout << "Course limit reached.\n";
                        }

                    } else if (opt == 4) {
                        std::string cid;
                        std::cout << "Enter Course Code to remove: "; std::cin >> cid;
                        std::cout << "Are you sure you want to remove course " << cid << "? (y/n): ";
                        char confirm; std::cin >> confirm;
                        if (confirm == 'y' || confirm == 'Y') {
                            for (int i = 0; i < courseCount; ++i) {
                                if (courses[i]->getCode() == cid) {
                                    delete courses[i];
                                    for (int j = i; j < courseCount - 1; ++j) {
                                        courses[j] = courses[j + 1];
                                    }
                                    courseCount--;
                                    std::cout << "Course removed.\n";
                                    break;
                                }
                            }
                        }

                    } else if (opt == 5) {
                        showAllCourses(courses, courseCount);

                    } else if (opt == 7) {
                        Student* studentList[MAX_USERS];
                        int studentCount = 0;
                        for (int i = 0; i < userCount; ++i) {
                            if (Student* stu = dynamic_cast<Student*>(users[i])) {
                                studentList[studentCount++] = stu;
                            }
                        }
                        saveStudentData(studentList, studentCount, *courses, courseCount, "students.csv");

                    } else if (opt == 8) {
                        float threshold;
                        std::cout << "Enter minimum GPA to filter: ";
                        std::cin >> threshold;
                        Student* studentList[MAX_USERS];
                        int studentCount = 0;
                        for (int i = 0; i < userCount; ++i) {
                            if (Student* stu = dynamic_cast<Student*>(users[i])) {
                                studentList[studentCount++] = stu;
                            }
                        }
                        displayStudentsByGPA(studentList, studentCount, *courses, courseCount, threshold);
                    }
                } while (opt != 6);

            } else if (Instructor* inst = dynamic_cast<Instructor*>(currentUser)) {
                int opt;
                do {
                    std::cout << "\n-- Instructor Menu --\n";
                    std::cout << "1. Add Course to Teach\n2. Remove Course\n3. Update Student Grade\n4. Course Stats\n5. Logout\nChoose an option: ";
                    std::cin >> opt; clearInput();

                    if (opt == 1) {
                        std::string cid;
                        std::cout << "Course Code: "; std::cin >> cid;
                        Course* c = findCourse(courses, courseCount, cid);
                        if (c && inst->addCourse(cid)) {
                            c->addInstructor(inst->getId());
                            std::cout << "Course added.\n";
                        } else {
                            std::cout << "Course not found or limit exceeded.\n";
                        }
                    } else if (opt == 2) {
                        std::string cid;
                        std::cout << "Course Code: "; std::cin >> cid;
                        inst->removeCourse(cid);
                    } else if (opt == 3) {
                        std::string cid;
                        std::cout << "Course Code: "; std::cin >> cid;
                        Course* c = findCourse(courses, courseCount, cid);
                        if (c) {
                            std::string sid;
                            float grade;
                            std::cout << "Student ID: "; std::cin >> sid;
                            std::cout << "Grade: "; std::cin >> grade;
                            inst->updateStudentGrade(*c, sid, grade, users, userCount);
                        } else {
                            std::cout << "Course not found.\n";
                        }
                    } else if (opt == 4) {
                        std::string cid;
                        std::cout << "Course Code: "; std::cin >> cid;
                        Course* c = findCourse(courses, courseCount, cid);
                        if (c) {
                            // Build student list from users[]
                            Student* studentList[MAX_USERS];
                            int studentCount = 0;
                            for (int i = 0; i < userCount; ++i) {
                                if (Student* stu = dynamic_cast<Student*>(users[i])) {
                                    studentList[studentCount++] = stu;
                                }
                            }
                            inst->viewStats(*c, studentList, studentCount);  // call the correct overload
                        }
                    }

                } while (opt != 5);

            } else if (Student* stu = dynamic_cast<Student*>(currentUser)) {
                int opt;
                do {
                    std::cout << "\n-- Student Menu --\n";
                    std::cout << "1. Register Course\n2. Drop Course\n3. View Grades\n4. View GPA\n5. Logout\nChoose an option: ";
                    std::cin >> opt; clearInput();

                    if (opt == 1) {
                        std::string cid;
                        std::cout << "Enter Course Code: "; std::cin >> cid;
                        Course* c = findCourse(courses, courseCount, cid);
                        if (c && stu->registerCourse(c->getCode())) {
                            std::cout << "Course registered.\n";
                        } else {
                            std::cout << "Course not found or limit reached.\n";
                        }
                    } else if (opt == 2) {
                        std::string cid;
                        std::cout << "Enter Course Code: "; std::cin >> cid;
                        Course* c = findCourse(courses, courseCount, cid);
                        if (c && stu->dropCourse(c->getCode())) {
                            std::cout << "Course dropped.\n";
                        } else {
                            std::cout << "Could not drop course.\n";
                        }
                    } else if (opt == 3) {
                        stu->viewGrades();
                    } else if (opt == 4) {
                        float gpa = stu->calculateGPA(*courses, courseCount);
                        std::cout << "GPA (weighted by credits, 0.0 to 4.0 scale): " << gpa << "\n";
                    }
                } while (opt != 5);
            }
        } else if (choice == 2) {
            running = false;
        }
    }

    for (int i = 0; i < userCount; ++i) delete users[i];
    for (int i = 0; i < courseCount; ++i) delete courses[i];

    return 0;
}