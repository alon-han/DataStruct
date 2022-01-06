cmake_minimum_required(VERSION 3.19)
project(DataStruct_03 C)

set(CMAKE_C_STANDARD 99)

add_executable(DataStruct_03 main.c)
add_executable(DataStruct_03_Book_01 Infix_To_Postfix.c Stack.h Stack.c)
add_executable(DataStruct_03_Practice_3.1 Practice_3.1.c List.h List.c)
add_executable(DataStruct_03_Practice_3.2 Practice_3.2.c List.h List.c)
add_executable(DataStruct_03_Practice_3.3 Practice_3.3_a.c List.h List.c)