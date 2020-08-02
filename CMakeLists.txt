cmake_minimum_required(VERSION 3.16)

project(toDoList)
set(CMAKE_CXX_STANDARD 17)
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

add_executable(toDoList main.cpp Model/Task.cpp Model/Task.h Model/TaskID.cpp Model/TaskID.h Model/TaskEntity.cpp Model/TaskEntity.h
        Display/Display.cpp Display/Display.h
        API/TaskService.cpp API/TaskService.h Model/IdGenerator.cpp Model/IdGenerator.h
        Model/HashTaskID.cpp Model/HashTaskID.h Tests/IdGeneratorTest.cpp Tests/TaskTest.cpp Tests/TaskServiceTest.cpp
        Tests/TaskEntityTest.cpp Model/TaskDTO.cpp Model/TaskDTO.h Views/DateView.cpp Views/DateView.h Views/LabelView.cpp
        Views/LabelView.h Views/PriorityView.cpp Views/PriorityView.h Model/dtoConvertor.cpp Model/dtoConvertor.h Model/Storage.cpp
        Model/Storage.h Model/StorageService.cpp Model/StorageService.h)

set(BOOST_ROOT "C:/Users/Ilya/boost")
include_directories(${Boost_INCLUDE_DIR})

target_link_libraries(toDoList gtest gtest_main)
