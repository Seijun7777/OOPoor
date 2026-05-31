# OOPoor — Personal Finance Manager

A terminal-based personal finance manager written in C++ as an OOP course project.
Supports multiple users, income/expense tracking, and an admin panel.


## Features

- User registration and login with password validation
- Record income and expenses with timestamps
- View transaction history
- Admin panel to manage and delete user accounts
- Data stored in a binary file (no external database)


## Project Structure
Project_1/
├── main.cpp
├── Login_Functions.h
├── Menu_User.h
├── Menu_Admin.h
├── assets/
│   └── Arts.h
├── Classes/
│   ├── Users.h
│   └── Transactions.h
└── DataBase/
└── DataBase.bin


## Requirements

- C++17 or later
- GCC or Clang compiler
- macOS / Linux


## Notes

- The first admin account must be created manually by uncommenting the buffer code in `main.cpp`
- Each user can store up to 100 income and 100 expense records
- Passwords must be 8–18 characters, usernames 4–18 characters

