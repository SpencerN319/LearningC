cmake_minimum_required(VERSION 3.20)
project(LearningC C)

set(CMAKE_C_STANDARD 11)

#Introductory
#add_executable(LearningC Introductory/main.c)
#add_executable(LearningC Introductory/yeild.c)

#Threads
#add_executable(LearningC pointers/changing_pointer_values.c)

#Threads
#add_executable(LearningC Threading/simple_thread.c)
#add_executable(LearningC Threading/multi_thread.c)
add_executable(LearningC Threading/detaching.c)
#add_executable(LearningC Threading/exit_threads.c)
#add_executable(LearningC Threading/join_main.c)
#add_executable(LearningC Threading/thread_ids.c)

#add_executable(LearningC Threading/producer_consumer.c)
#add_executable(LearningC Threading/mutex.c)
#add_executable(LearningC Threading/passing_values.c)

#Structs
#add_executable(LearningC Structures/basic_structs.c)



