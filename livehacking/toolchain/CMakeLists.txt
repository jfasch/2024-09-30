cmake_minimum_required(VERSION 3.20)
project(greet)

add_library(company greet.c bye.c)

add_executable(hello-world hello-world.c)
target_link_libraries(hello-world company)

add_executable(hello-suesser hello-suesser.c)
target_link_libraries(hello-suesser company)
