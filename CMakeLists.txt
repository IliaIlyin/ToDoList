cmake_minimum_required(VERSION 3.16)

include_directories(src)
project(toDoList)
set(CMAKE_CXX_STANDARD 17)
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

add_executable(toDoList main.cpp
        src/Model/Task.cpp
        src/Model/Task.h
        src/Model/TaskID.cpp
        src/Model/TaskID.h
        src/Model/TaskEntity.cpp
        src/Model/TaskEntity.h
        src/Display/Display.cpp
        src/Display/Display.h
        src/API/TaskService.cpp
        src/API/TaskService.h
        src/Model/IdGenerator.cpp
        src/Model/IdGenerator.h
        src/Model/HashTaskID.cpp
        src/Model/HashTaskID.h
        Tests/IdGeneratorTest.cpp
        Tests/TaskTest.cpp
        Tests/TaskServiceTest.cpp
        Tests/TaskEntityTest.cpp
        src/Model/TaskDTO.cpp
        src/Model/TaskDTO.h
        src/Views/DateView.cpp
        src/Views/DateView.h
        src/Views/LabelView.cpp
        src/Views/LabelView.h
        src/Views/PriorityView.cpp
        src/Views/PriorityView.h
        src/Model/dtoConvertor.cpp
        src/Model/dtoConvertor.h
        src/Model/Storage.cpp
        src/Model/Storage.h
        src/Model/StorageService.cpp
        src/Model/StorageService.h
        src/Views/GeneralView.h
        src/Views/ViewService.cpp
        src/Views/ViewService.h
        src/Model/AllDataStorage.cpp
        src/Model/AllDataStorage.h
        Tests/TaskIdTest.cpp
        Tests/TaskDtoTest.cpp
        Tests/StorageServiceTest.cpp)

set(BOOST_ROOT "C:/Users/Ilya/boost")
include_directories(${Boost_INCLUDE_DIR})

target_link_libraries(toDoList gtest gtest_main)
