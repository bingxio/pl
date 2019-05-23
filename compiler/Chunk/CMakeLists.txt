cmake_minimum_required(VERSION 3.14)

project(learnC C)

set(CMAKE_C_STANDARD 11)

add_executable(learnC Main.c chunk.h common.h chunk.c memory.h memory.c debug.h debug.c value.h value.c)