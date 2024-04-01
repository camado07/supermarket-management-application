cmake_minimum_required(VERSION 3.27)
project(SupermarketSystem)

set(CMAKE_CXX_STANDARD 17)

add_executable(SupermarketSystem main.cpp
        product.h
        file_handler.h
        file_handler.cpp
        shopping.h
        shopping.cpp)
