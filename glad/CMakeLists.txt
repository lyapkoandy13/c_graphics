cmake_minimum_required(VERSION 3.16..3.24)
project(Glad)

add_library(glad ${PROJECT_SOURCE_DIR}/include/glad/glad.h ${PROJECT_SOURCE_DIR}/src/glad.c)
target_include_directories(glad PUBLIC include/)