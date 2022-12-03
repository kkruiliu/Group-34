cmake_minimum_required(VERSION 3.21)
project(Group_34)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)

FetchContent_Declare(Jsoncpp
    GIT_REPOSITORY https://github.com/open-source-parsers/jsoncpp.git
    GIT_TAG master)

FetchContent_MakeAvailable(SFML Jsoncpp)

include_directories(.)

add_executable(Group_34

        "User.h"
        "Book.cpp"
        "Book.h"
        "Button.h"
        "log_in_alpha.cpp"
        "main.cpp"
        "Reviews.cpp"
        "Reviews.h"
        "textBox.h"
        "Database.json" 
        "Database.h")

target_link_libraries(Group_34 PRIVATE sfml-graphics sfml-window sfml-system jsoncpp_lib)
