# 🎓 Student Management System (C++)

A complete, object-oriented Student Management System written in C++. The project simulates a university-level academic platform where students, instructors, and administrators can manage courses, records, and personal data. It uses file-based storage, dynamic memory, and manual data structures for performance and practice.

[GitHub Repository](https://github.com/omarwsoufi/Student-Management-System-CPP.git)

## 📁 Project Structure

```
src/
├── Administrator.cpp / .h     # Admin role functions
├── Course.cpp / .h            # Course data and logic
├── FileIO.cpp / .h            # File loading/saving logic
├── Instructor.cpp / .h        # Instructor functionalities
├── Student.cpp / .h           # Student features and records
├── User.cpp / .h              # Shared base class for all users
├── Constants.h                # Constants for IDs, limits, etc.
└── main.cpp                   # Main menu interface and driver code
```

## ✨ Key Features

* 🔑 **Authentication & Role Access**: Student, Instructor, Administrator roles
* 🧠 **OOP Principles**: Classes, inheritance, encapsulation, polymorphism
* 📂 **File-Based Persistence**: Saves student data to CSV
* 📊 **GPA Calculation**: Weighted GPA based on course credits
* ⚙️ **Manual Memory Management**: No STL (dynamic arrays used)
* 🧭 **Menu-Based Interface**: Clean user navigation through CLI

## 📊 System Architecture

### Core Components
1. **User Management**
   - Base `User` class with authentication
   - Three derived classes: `Administrator`, `Instructor`, and `Student`
   - Each user type has unique capabilities and restrictions

2. **Course Management**
   - `Course` class for managing course information
   - Support for multiple instructors per course
   - Grade tracking and statistics
   - Credit-based system

3. **Data Persistence**
   - CSV file export functionality
   - Student data storage and retrieval
   - GPA calculation and reporting

### System Limits
- Maximum Users: 100
- Maximum Courses: 100
- Maximum Instructors per Course: 3
- Maximum Students per Course: 100
- Maximum Courses per Instructor: 5
- Maximum Courses per Student: 6

## 🛠️ How to Compile & Run

### Prerequisites:
* C++ compiler (e.g., `g++` with C++17 or later)
* CMake (version 3.10 or later)
* Standard C++ libraries

### Quick Start (Windows):
1. Make sure you have g++ installed and added to your system PATH
2. Open Command Prompt or PowerShell in the project directory
3. Run the build script:
   ```bash
   .\build.bat
   ```
   This will automatically compile and run the program.

### Building with CMake (Recommended):
```bash
# Create a build directory
mkdir build
cd build

# Generate build files
cmake ..

# Build the project
cmake --build .
```

### Manual Compilation (Alternative):
```bash
g++ -o StudentManagementSystem main.cpp User.cpp Student.cpp Instructor.cpp Administrator.cpp Course.cpp FileIO.cpp -std=c++17
```

### Running the Program:
```bash
# If using CMake build
./StudentManagementSystem      # On Linux/macOS
StudentManagementSystem.exe    # On Windows

# If using manual compilation
./StudentManagementSystem      # On Linux/macOS
StudentManagementSystem.exe    # On Windows
```

## 📋 Program Usage

### Initial Setup:
1. Launch the program
2. Create administrator account
3. Use administrator credentials to add other users and courses

### Login:
* Select login option
* Enter credentials
* Access role-specific menu

### Administrator Menu:
* Add/Remove Users (Students, Instructors)
* Add/Remove Courses
* Show All Courses with average grades
* Save Student Data to `students.csv`
* Show Students by GPA
* Logout

### Instructor Menu:
* Add/Remove Courses to Teach
* Update Student Grades
* View Course Statistics (Min/Max/Average)
* Logout

### Student Menu:
* Register/Drop Courses (max 6)
* View Grades
* Calculate and View GPA
* Logout

### Exiting:
* Choose option 2 from main menu to exit
* Program releases allocated memory

## ⚠️ Notes and Limitations
* Static array implementation limits system capacity
* Data persistence is export-only (no import functionality)
* Grade scale: 0-100 (converted to 0.0-4.0 for GPA)
* Ungraded courses are marked with -1
* Input validation for unique IDs and course codes

## 🔮 Future Enhancements
1. Dynamic data structures for scalability
2. Database integration for persistent storage
3. User interface improvements
4. Additional reporting features
5. Enhanced security measures

## 📝 License

This project is for **educational purposes** and not distributed under any specific license. 