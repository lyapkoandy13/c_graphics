#!/bin/bash

rm -rf build/**

# Compile main.cpp and link with the library
cc -Wall -Wextra -g -o build/main src/main.c src/shader.c vendor/glad.c -lstdc++ -I vendor/include -L vendor/lib -lglfw3 -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

echo "Build and linking completed. Executable 'main' created."
