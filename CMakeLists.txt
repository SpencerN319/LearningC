cmake_minimum_required(VERSION 3.20)
project(LearningC C)

set(CMAKE_C_STANDARD 11)

#add_executable(LearningC Introductory/main.c)
#add_executable(LearningC Threading/simple_thread.c)
add_executable(LearningC Threading/multi_thread.c)
