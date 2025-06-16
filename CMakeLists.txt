cmake_minimum_required(VERSION 3.10)

project(Gravity2DCLI)

set(CMAKE_C_STANDARD 99)

find_package(OpenGL REQUIRED)

cmake_policy(SET CMP0072 NEW)

find_package(PkgConfig REQUIRED)
    pkg_check_modules(GLFW REQUIRED glfw3)
    pkg_check_modules(GLEW REQUIRED glew)

include_directories(
 ${OPENGL_INCLUDE_DIR}
 ${GLFW_INCLUDE_DIRS}
 ${GLEW_INCLUDE_DIRS}
)

add_executable(Gravity2DCLI
 main.c
 physics.c
)

target_link_libraries(Gravity2DCLI
 ${OPENGL_LIBRARIES}
 ${GLFW_LIBRARIES}
 ${GLEW_LIBRARIES}
)

