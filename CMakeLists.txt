cmake_minimum_required(VERSION 3.17)

cmake_policy(VERSION 3.17)

project(Calculator VERSION 1.0
        DESCRIPTION "I love C++"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

SET(NAME "johnDoe")
SET(TEST_NAME "unit_test")

set(SRC
        src/Calculator/Calculator.cpp
        src/Error/Error.cpp
        src/OperationsPriorities/OperationsPriorities.cpp
        src/OperationsPriorities/ProxyOperationsPriorities.cpp
        src/InfiniteNumbers/InfiniteNumber.cpp
)

set(TEST_SRC
        tests/test.cpp
        tests/Error.cpp
        tests/Calculator.cpp
        tests/OperationsPriorities.cpp
        tests/InfiniteNumber.cpp
)

add_executable(${NAME} main.cpp ${SRC})

set_target_properties(${NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

include_directories(src/Calculator)
include_directories(src/Error)
include_directories(src/Interface)
include_directories(src/OperationsPriorities)
include_directories(src/InfiniteNumbers)

add_compile_options(-fPIC)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.11.0
)
FetchContent_MakeAvailable(googletest)

add_executable(${TEST_NAME} ${SRC} ${TEST_SRC})
target_link_libraries(${TEST_NAME} PUBLIC gtest_main)

include(CTest)
include(GoogleTest)
gtest_discover_tests(${TEST_NAME})

set_target_properties(${TEST_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
