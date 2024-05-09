cmake_minimum_required(VERSION 3.27)
project(vehicles_2)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall -Wextra -Werror -Wpedantic -pedantic-errors)

include_directories(include)

set(SOURCE_FILES
        src/vehicles.cpp
        test/main_gtest.cpp
)

add_executable(vehicles_2 ${SOURCE_FILES} main.cpp
)

set(SOURCES_FILES_TESTS
        test/main_gtest.cpp
        include/vehicles.hpp
        src/vehicles.cpp
        test/test_vehicles.cpp
)

add_executable(vehicles_2__test ${SOURCE_FILES} ${SOURCES_FILES_TESTS} test/main_gtest.cpp)

# TODO: Poniższe ścieżki prawdopodobnie musisz zmienić...
target_include_directories(vehicles_2__test PUBLIC
        ../../googletest-master/googlemock/include
        ../../googletest-master/googletest/include
)

# TODO: Poniższą ścieżkę prawdopodobnie musisz zmienić...
add_subdirectory(../../googletest-master googletest-master)

target_link_libraries(vehicles_2__test gmock)
