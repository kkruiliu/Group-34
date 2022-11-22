cmake_minimum_required(VERSION 3.21)
project(Group_34)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Group_34
     
        "User.h"
        "Book.cpp"
        "Book.h"
        "log_in_alpha.cpp"
        "main.cpp"
        "Reviews.cpp"
        "Reviews.h"
        "Database.json"
        )
