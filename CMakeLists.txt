cmake_minimum_required(VERSION 3.16..3.24)
project(c_graphics VERSION 0.0.1 DESCRIPTION "Exploring c" LANGUAGES C)

ADD_LIBRARY(c_setup INTERFACE)
target_compile_options(c_setup INTERFACE -Wall -Wpedantic -Wextra)

add_subdirectory(${PROJECT_NAME})
add_subdirectory(glad)

