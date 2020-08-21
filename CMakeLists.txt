cmake_minimum_required(VERSION 3.15)
project(toDoList LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
include_directories(src)
file(GLOB CPP_SOURCES "src/API/*.cpp" "src/Model/*.cpp" "src/Views/*.cpp")

file(GLOB HEADERS "src/API/*.h" "src/Model/.*h" "src/Views/.*h")
file(GLOB TEST_SOURCES "Tests/*.cpp")

add_executable(toDoList ${HEADERS} ${CPP_SOURCES} main.cpp)

include(GoogleTest)
find_package(GTest REQUIRED)
include_directories(${GMOCK_INCLUDE_DIR})
enable_testing()


add_executable(TestsExecutable ${TEST_SOURCES}
                ${CPP_SOURCES} CLI/State.h CLI/Context.cpp CLI/Context.h CLI/StateMachine.cpp CLI/StateMachine.h CLI/ViewState.cpp CLI/ViewState.h CLI/BaseState.cpp CLI/BaseState.h CLI/ExitState.cpp CLI/ExitState.h CLI/Validator.cpp CLI/Validator.h CLI/AddTaskState.cpp CLI/AddTaskState.h CLI/ViewTaskState.cpp CLI/ViewTaskState.h)

target_link_libraries(TestsExecutable GTest::GTest GTest::Main ${GMOCK_LIBRARY} ${GMOCK_MAIN_LIBRARY})

set(Boost_USE_STATIC_LIBS ON) # only find static libs
set(Boost_USE_DEBUG_LIBS OFF)
set(Boost_USE_RELEASE_LIBS ON)  # only find release libs
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME ON)

add_definitions( -DBOOST_ALL_NO_LIB )

find_package(Boost 1.73.0 REQUIRED COMPONENTS date_time)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif ()

target_link_libraries(toDoList ${Boost_LIBRARIES})
target_link_libraries(TestsExecutable ${Boost_LIBRARIES})
gtest_discover_tests(TestsExecutable)
