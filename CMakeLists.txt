cmake_minimum_required(VERSION 3.24)
project(get_next_line C)

set(CMAKE_C_STANDARD 11)

add_executable(get_next_line main.c get_next_line.c get_next_line_utils.c)
