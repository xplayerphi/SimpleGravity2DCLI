cmake_minimum_required(VERSION 3.10)

project(Gravity2DCLI C)

set(CMAKE_C_STANDARD 99)

add_executable(Gravity2DCLI
    main.c
    physics.c
)
