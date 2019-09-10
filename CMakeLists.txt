cmake_minimum_required(VERSION 3.0)

project(linkedlist)

add_library(linkedlist SHARED  
            linkedlist.c)

add_executable(listtest main.c)

target_link_libraries(listtest linkedlist)