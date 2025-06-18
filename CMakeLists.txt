cmake_minimum_required(VERSION 3.10)

project(Gravity2DCLI VERSION 11.2 LANGUAGES C)

 set(CMAKE_C_STANDARD 99)
 set(CMAKE_C_STANDARD_REQUIRED ON)

 add_executable(Gravity2DCLI
  main.c
  physics.c
 )

