# CreditCardValidator example

This project is a simple main function to test the CreditCardValidator lib.

## How to use

1. You need to [download](../README.md#how-to-use) the lib on your machine

2. In your [CMakeLists.txt](CMakeLists.txt) you must add 3 lines:
    - SET(LIB_PATH "path/to/the/lib") -> path to the directory where the lib is
    - target_link_libraries(toto PRIVATE ${LIB_PATH}/libcreditCardValidator.dylib) -> you link the library with your executable
    - include_directories(../include) -> add the path to the directory where CreditCardValidator.hpp is

3. Now you can run your project normally
    - mkdir build/
    - cd build/
    - cmake ..
    - make
    - cd ../
    - ./executable
