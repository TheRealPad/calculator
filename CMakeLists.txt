cmake_minimum_required(VERSION 3.17)

cmake_policy(VERSION 3.17)

project(Calculator VERSION 1.0
        DESCRIPTION "I love C++"
        LANGUAGES CXX)

SET(NAME "calculator")
SET(TEST_NAME "unit_test")

set(CMAKE_CXX_STANDARD 17)

set(SRC
        main.cpp
)

add_executable(${NAME} ${SRC})

set_target_properties(${NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

add_compile_options(-fPIC)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.11.0
)
FetchContent_MakeAvailable(googletest)

add_executable(${TEST_NAME} tests/test.cpp)
target_link_libraries(${TEST_NAME} PUBLIC gtest_main)

include(CTest)
include(GoogleTest)
gtest_discover_tests(${TEST_NAME})
