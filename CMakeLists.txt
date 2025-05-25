cmake_minimum_required(VERSION 3.10)
project(StudentManagementSystem)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/SRC)

add_executable(StudentManagementSystem
        SRC/main.cpp
        SRC/Administrator.cpp
        SRC/Instructor.cpp
        SRC/Student.cpp
        SRC/Course.cpp
        SRC/FileIO.cpp
        SRC/User.cpp
)
if(MINGW)
    message(STATUS "Building with mingw-w64")
else()
    message(STATUS "Not building with mingw-w64")
endif()

