cmake_minimum_required(VERSION 3.16..3.24)

add_executable(main_exec src/main.c)
target_link_libraries(main_exec PRIVATE glad c_setup)
target_include_directories(main_exec PRIVATE include)
target_include_directories(main_exec PRIVATE -L lib -glfw3)
target_link_libraries(main_exec PRIVATE
    -framework OpenGL
    -framework Cocoa
    -framework IOKit
    -framework CoreVideo
    )
