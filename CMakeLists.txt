cmake_minimum_required(VERSION 3.0.0)
project(physics_simulation VERSION 0.1.0 LANGUAGES C CXX)

include_directories("include")

add_executable(physics_simulation src/main.cpp src/glad.c)

find_package(glfw3 3.3 REQUIRED)

target_link_libraries(physics_simulation glfw)
 
find_package(OpenGL REQUIRED)

target_link_libraries(physics_simulation OpenGL::GL)
