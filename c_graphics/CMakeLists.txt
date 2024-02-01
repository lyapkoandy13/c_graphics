cmake_minimum_required(VERSION 3.16..3.24)
project(idk)

add_library(files ${PROJECT_SOURCE_DIR}/src/files.c)
target_include_directories(files PUBLIC ${PROJECT_SOURCE_DIR}/include)

# link glfw
include_directories(${CMAKE_SOURCE_DIR}/vendor/include)
find_library(GLFW glfw3 "${CMAKE_SOURCE_DIR}/vendor/lib")

add_executable(main_exec ${PROJECT_SOURCE_DIR}/src/main.c)
target_include_directories(main_exec PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(main_exec PRIVATE c_setup files glad ${GLFW})

target_link_libraries(main_exec PRIVATE
    "-framework OpenGL"
    "-framework Cocoa"
    "-framework IOKit"
    "-framework CoreVideo"
    )
