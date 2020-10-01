cmake_minimum_required(VERSION 3.15)
project(toDoList LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

add_definitions(-std=gnu++17)
add_definitions(-fPIC)

include_directories(Core)
include_directories(CLI)
file(GLOB_RECURSE CPP_SOURCES
        "Core/API/*.cpp"
        "Core/Model/*.cpp"
        "Core/Views/*.cpp"
        "Core/Serialization/*.cpp"
        "CLI/*.cpp")
file(GLOB_RECURSE HEADERS "Core/API/*.h" "Core/Model/.*h" "Core/Views/.*h" "CLI/.*h" "Core/Serialization/.*h")
file(GLOB TEST_SOURCES "Tests/*.cpp")
include(GoogleTest)
find_package(GTest REQUIRED)
include_directories(${GMOCK_INCLUDE_DIR})
enable_testing()

find_package(Protobuf REQUIRED)
include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

file(GLOB_RECURSE PROTO_SOURCES CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/ProtoFile/*.proto )
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_SOURCES})
message("Generated ${PROTO_SRCS} ${PROTO_HDRS}")

SET_SOURCE_FILES_PROPERTIES(${PROTO_SRCS} ${PROTO_HDRS} PROPERTIES GENERATED TRUE)

add_executable(toDoList ${HEADERS} ${CPP_SOURCES} main.cpp ${PROTO_SRCS} ${PROTO_HDRS})

add_executable(TestsExecutable ${TEST_SOURCES}
                ${CPP_SOURCES} ${HEADERS} CLI/Validators/InputValidators/ExitValidator.cpp CLI/Validators/InputValidators/ExitValidator.h Core/Serialization/Serializer.h Core/Serialization/Persistor.cpp Core/Serialization/Persistor.h Core/Serialization/PersistorUtils.h Core/Serialization/PersistorUtils.cpp Core/Model/AllDataStorageFactory.cpp Core/Model/AllDataStorageFactory.h Tests/PersistorUtilsTest.cpp)
target_link_libraries(TestsExecutable GTest::GTest GTest::Main ${GMOCK_LIBRARY} ${GMOCK_MAIN_LIBRARY})

set(Boost_USE_STATIC_LIBS OFF) # only find static libs
set(Boost_USE_DEBUG_LIBS OFF)
set(Boost_USE_RELEASE_LIBS ON)  # only find release libs
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

add_definitions(-DBOOST_ALL_NO_LIB)

find_package(Boost 1.71.0 REQUIRED COMPONENTS date_time)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif ()

target_link_libraries(toDoList ${Boost_LIBRARIES})
target_link_libraries(TestsExecutable ${Boost_LIBRARIES})
target_link_libraries(toDoList ${Protobuf_LIBRARIES})
gtest_discover_tests(TestsExecutable)
