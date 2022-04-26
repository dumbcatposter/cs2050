cmake_minimum_required(VERSION 3.22)
project(prelab11 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(prelab11
        main.c
        prelab11.c
        prelab11.h)
