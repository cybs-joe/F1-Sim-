cmake_minimum_required(VERSION 3.16)
project(F1Sim CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(f1sim
    src/main.cpp
    src/race.cpp
    src/strategy.cpp
)

target_include_directories(f1sim PRIVATE src)
find_package(CURL REQUIRED)
target_link_libraries(f1sim CURL::libcurl)