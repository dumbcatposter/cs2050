cmake_minimum_required(VERSION 3.20)
project(Lab_9_Solution C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Lab_9_Solution
        TASurprise.c
        TASurprise.h
        main.c)
