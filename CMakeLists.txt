cmake_minimum_required(VERSION 3.8)
project(Bitwolf_Engine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)

set(SOURCE_FILES main.cpp)
add_executable(Bitwolf_Engine ${SOURCE_FILES})
target_link_libraries(Bitwolf_Engine Qt5::Widgets)
