
cmake_minimum_required(VERSION 3.10.2)

project(learnC C)

set(CMAKE_C_STANDARD 11)

add_executable(learnC main.c chunk.h common.h chunk.c memory.h memory.c debug.h debug.c value.h value.c vm.h vm.c)
