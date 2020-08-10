cmake_minimum_required(VERSION 3.15)
project(toDoList LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

include_directories(src)

file(GLOB CPP_SOURCES "src/API/*.cpp" "src/Model/*.cpp" "src/Views/*.cpp" "src/Display/.*cpp")

file(GLOB HEADERS "src/API/*.h" "src/Model/.*h" "src/Views/.*h" "src/Display/.*h")

file(GLOB TEST_SOURCES "Tests/*.cpp")

add_executable(toDoList ${HEADERS} ${CPP_SOURCES} main.cpp)

include(GoogleTest)
find_package(GTest REQUIRED)
enable_testing()


add_executable(TestsExecutable ${TEST_SOURCES}
                ${CPP_SOURCES})

target_link_libraries(TestsExecutable GTest::GTest GTest::Main)

gtest_discover_tests(TestsExecutable)

set(Boost_USE_STATIC_LIBS ON) # only find static libs
set(Boost_USE_DEBUG_LIBS OFF)
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
