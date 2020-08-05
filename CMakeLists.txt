cmake_minimum_required(VERSION 3.15)
project(toDoList LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

include_directories(src)
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
        )

include(GoogleTest)
find_package(GTest REQUIRED)
enable_testing()


add_executable(TestsExecutable Tests/IdGeneratorTest.cpp
        )

target_link_libraries(TestsExecutable GTest::GTest GTest::Main)

gtest_discover_tests(TestsExecutable)

set(Boost_USE_STATIC_LIBS ON) # only find static libs
set(Boost_USE_DEBUG_LIBS OFF)
set(Boost_USE_DEBUG_LIBS OFF) # ignore debug libs and
set(Boost_USE_RELEASE_LIBS ON)  # only find release libs
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost REQUIRED COMPONENTS date_time)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif ()

target_link_libraries(toDoList ${Boost_LIBRARIES})
target_link_libraries(TestsExecutable ${Boost_LIBRARIES})
gtest_discover_tests(TestsExecutable)
