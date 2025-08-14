cmake_minimum_required(VERSION 3.10)
PROJECT(hello_tar_local)
add_executable(${PROJECT_NAME} main.c)
install(TARGETS ${PROJECT_NAME} DESTINATION bin)