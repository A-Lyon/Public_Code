cmake_minimum_required(VERSION 3.11)
project(hw5)
 
if (CMAKE_SOURCE_DIR MATCHES "[Hh][Ww]([0-9])$"
   AND NOT PROJECT_NAME MATCHES "${CMAKE_MATCH_1}$")
    message(FATAL_ERROR "Building ${PROJECT_NAME} in ${CMAKE_SOURCE_DIR}")
endif()
 
add_compile_options(-Wall)
 
add_compile_options(-Wextra -Wpedantic)
 
add_compile_options(-fmessage-length=80 -fno-diagnostics-show-option
    -fstack-protector-all -g -O3 -std=c++17 -Walloc-zero -Walloca
    -Wctor-dtor-privacy -Wduplicated-cond -Wduplicated-branches
    -Werror -Wextra-semi -Wfatal-errors -Winit-self -Wlogical-op
    -Wold-style-cast -Wshadow -Wunused-const-variable=1
    -Wzero-as-null-pointer-constant)
 
add_executable(${PROJECT_NAME} main.cc) 
 
add_custom_target(${PROJECT_NAME}.tar ALL COMMAND
    tar -cf ${PROJECT_NAME}.tar *.cc CMakeLists.txt)
