cmake_minimum_required(VERSION 3.16)

project(toDoList)
set(CMAKE_CXX_STANDARD 17)
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)
add_executable(toDoList main.cpp Model/Task.cpp Model/Task.h Model/TaskID.cpp Model/TaskID.h Model/TaskEntity.cpp Model/TaskEntity.h Display/Display.cpp Display/Display.h
        API/TaskService.cpp API/TaskService.h Model/IdGenerator.cpp Model/IdGenerator.h Model/HashTaskEntity.cpp Model/HashTaskEntity.h Tests/IdGeneratorTest.cpp Tests/TaskTest.cpp Tests/TaskServiceTest.cpp Tests/TaskEntityTest.cpp Model/TaskDTO.cpp Model/TaskDTO.h)


target_link_libraries(toDoList gtest gtest_main)
