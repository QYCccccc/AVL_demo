cmake_minimum_required(VERSION 3.16)
project(AVL_Test C)

set(CMAKE_C_STANDARD 11)

add_executable(AVL_Test main.c avlTree.c avlTree.h)