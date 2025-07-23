cmake_minimum_required(VERSION 3.10)

project(Leetcode)

include_directories(src/include)

add_library(prj_lib src/list.c)

add_executable(main src/main.c)

