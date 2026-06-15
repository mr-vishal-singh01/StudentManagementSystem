cmake_minimum_required(VERSION 3.10)
project(StudentManagementSystem C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Source files
set(SOURCES main.c)

# Executable
add_executable(student_mgmt ${SOURCES})

# Enable testing support for GitHub Actions
enable_testing()
add_test(NAME basic_run COMMAND student_mgmt)
