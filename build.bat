@echo off
echo Compiling Student Management System...
g++ -o StudentManagementSystem.exe SRC/main.cpp SRC/Administrator.cpp SRC/Instructor.cpp SRC/Student.cpp SRC/Course.cpp SRC/FileIO.cpp SRC/User.cpp -std=c++17
if %errorlevel% equ 0 (
    echo Build successful!
    echo Running the program...
    StudentManagementSystem.exe
) else (
    echo Build failed!
    pause
) 