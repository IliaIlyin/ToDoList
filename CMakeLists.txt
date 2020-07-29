cmake_minimum_required(VERSION 3.16)

project(toDoList)
set(CMAKE_CXX_STANDARD 17)
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)
add_executable(toDoList main.cpp Task.cpp Task.h TaskID.cpp TaskID.h TaskEntity.cpp TaskEntity.h Display.cpp Display.h
        TaskService.cpp TaskService.h IdGenerator.cpp IdGenerator.h HashTaskEntity.cpp HashTaskEntity.h Tests/IdGeneratorTest.cpp Tests/TaskTest.cpp Tests/TaskServiceTest.cpp Tests/TaskEntityTest.cpp)


target_link_libraries(toDoList gtest gtest_main)
