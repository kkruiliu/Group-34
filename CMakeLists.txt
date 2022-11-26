cmake_minimum_required(VERSION 3.21)
project(Group_34)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

include_directories(.)

add_executable(Group_34

        "User.h"
        "Book.cpp"
        "Book.h"
        "log_in_alpha.cpp"
        "main.cpp"
        "Reviews.cpp"
        "Reviews.h"
        "MainWindow.cpp"
        "MainWindow.h"
        "Database.json")

target_link_libraries(Group_34 PRIVATE sfml-graphics sfml-window sfml-system)


