cmake_minimum_required(VERSION 3.10)
project(StudentManagement SYSTEM C)

# Set the C standard to C99
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Define the executable
add_executable(student_mgmt main.c)

# Enable testing support for CTest (so `ctest` command in CI doesn't error out)
enable_testing()
