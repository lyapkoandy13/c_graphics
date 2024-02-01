#!/bin/bash

# rm -rf build/**

SOURCES="src/main.c src/files.c vendor/glad.c"
# SOURCES="src/main.c src/files.c"
CPP_FLAGS="-lstdc++"

# Compile main.cpp and link with the library
cc -Wall -Wextra -Wpedantic -Werror -g -o build/main ${SOURCES} -I vendor/include -L vendor/lib -lglfw3 -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

echo "Build and linking completed. Executable 'main' created."
