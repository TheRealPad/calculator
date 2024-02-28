cmake_minimum_required(VERSION 3.17)

cmake_policy(VERSION 3.17)

project(Calculator VERSION 1.0
        DESCRIPTION "I love C++"
        LANGUAGES CXX)

SET(NAME "calculator")

set(CMAKE_CXX_STANDARD 17)

set(SRC
        main.cpp
    )

add_executable(${NAME} ${SRC})

set_target_properties(${NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

add_compile_options(-fPIC)
