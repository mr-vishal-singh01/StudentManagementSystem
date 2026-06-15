# 🎓 Student Management System

> **About:** Professional C-based Student Management System with persistent binary storage, multi-platform CMake builds, and automated CI/CD workflows.
> 
> **Builds:** ![Build Status](https://github.com/mr-vishal-singh01/StudentManagementSystem/actions/workflows/cmake-multi-platform.yml/badge.svg)
> **License:** ![License](https://img.shields.io/github/license/mr-vishal-singh01/StudentManagementSystem)
> **Topics:** `c-programming` | `management-system` | `cmake` | `github-actions` | `hackathon`

---

---

## 🚀 Quick Start

### 1. Prerequisites
- **C Compiler:** GCC (Linux) or MSVC (Windows)
- **Build Tool:** CMake 3.10+

### 2. Build Instructions
```bash
# Clone the repository
git clone https://github.com/mr-vishal-singh01/StudentManagementSystem.git
cd StudentManagementSystem

# Create build directory
mkdir build && cd build

# Configure and Build
cmake ..
cmake --build .
```

### 3. Run the Program
```bash
./student_mgmt
```

---

## 🧪 How to Test New Features

### 1. Data Integrity (Name Validation)
- Choose **Option 1** (Add Student).
- Try to enter a name with numbers (e.g., `Vishal123`).
- **Result:** The system will block the entry and ask for a valid name.

### 2. Smart Search (Search by Name)
- Choose **Option 4** (Search Student by Name).
- Enter part of a name (e.g., `Vishal`).
- **Result:** The system will find all matching student profiles.

---

## ✨ Features
- **Full CRUD:** Add, Display, Search, Modify, and Delete student records.
- **Data Persistence:** Records are saved in `students.dat` (binary format).
- **Security:** Built-in input validation to prevent buffer overflows.
- **CI/CD:** Automated builds for Windows and Linux via GitHub Actions.

---

## 📚 Documentation
For detailed guides, please visit our **[Project Wiki](https://github.com/mr-vishal-singh01/StudentManagementSystem/wiki)**:
- [User Guide](https://github.com/mr-vishal-singh01/StudentManagementSystem/wiki/User-Guide)
- [Developer Guide](https://github.com/mr-vishal-singh01/StudentManagementSystem/wiki/Developer-Guide)

---

## 🛡️ Security & License
- **Security:** Please refer to our [Security Policy](SECURITY.md) for reporting vulnerabilities.
- **License:** This project is licensed under the [MIT License](LICENSE).

---
*Developed by **Vishal Chauchan***
