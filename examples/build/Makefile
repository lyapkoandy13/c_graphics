all: main

main: src/main.c
	cc -Wall -Wextra -Wpedantic -Werror -g -o build/main src/main.c src/files.c vendor/glad.c -I vendor/include -L vendor/lib -lglfw3 -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

clean:
	rm -rf build/**
