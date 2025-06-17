cmake_minimum_required(VERSION 3.10)

project(Gravity2DCLI VERSION 11.2 LANGUAGES C)

 set(CMAKE_C_STANDARD 99)
 set(CMAKE_C_STANDARD_REQUIRED ON)

 cmake_policy(SET CMP0072 NEW)

 find_package(OpenGL REQUIRED)
 find_package(PkgConfig REQUIRED)

 pkg_check_modules(GLFW REQUIRED glfw3)
 pkg_check_modules(GLEW REQUIRED glew)

 add_executable(Gravity2DCLI
  main.c
  physics.c
 )

 target_include_directories(Gravity2DCLI PRIVATE
  ${OPENGL_INCLUDE_DIR}
  ${GLFW_INCLUDE_DIRS}
  ${GLEW_INCLUDE_DIRS}
 )

 target_link_libraries(Gravity2DCLI PRIVATE
  ${OPENGL_gl_LIBRARY}
  ${GLFW_LIBRARIES}
  ${GLEW_LIBRARIES}
 )


