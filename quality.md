# 💎 Engineering Quality & Excellence Standards

This document defines the high engineering standards for the **Student Management System** (C Programming).

## 🛠️ Technical Standards

### 💻 C Programming (Core)
- **Memory Safety:** Manual memory management must be leak-free (validated via **Valgrind**).
- **Style:** Adherence to structured, procedural programming with clear function modularity.
- **Safety:** Strict use of buffer length checks to prevent overflows.

## 🧪 Testing Protocol

- **CRUD Validation:** Rigorous testing of Add, Display, Search, Modify, and Delete operations.
- **Persistence Testing:** Verifying data integrity within the `students.dat` binary file.
- **Boundary Testing:** Testing CGPA, Attendance, and Fee fields for valid ranges.

## 🚀 Build & Deployment

- **CMake Integration:** Supporting standardized cross-platform builds.
- **GitHub Actions:** Automated CI to verify code compilation on every push.

---
<div align="center">
  <img src="https://capsule-render.vercel.app/api?type=rect&color=0E75B6&height=2&width=400&section=footer" />
</div>
