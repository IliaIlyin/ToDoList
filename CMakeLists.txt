cmake_minimum_required(VERSION 3.15)
project(toDoList LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(-Dgtest_disable_pthreads=ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

add_definitions(-std=gnu++17)
add_definitions(-fPIC)

include_directories(Core)
include_directories(CLI)
include_directories(Tests)
include_directories(SerializationUtils)

file(GLOB_RECURSE CORE_HEADERS "Core/*.h" "SerializationUtils.h")
file(GLOB_RECURSE CLI_HEADERS "CLI/*.h" "Core/*.h" "SerializationUtils.h")
file(GLOB_RECURSE CORE_SOURCES "Core/*.cpp" "SerializationUtils.cpp")
file(GLOB_RECURSE CLI_SOURCES "CLI/*.cpp" "Core/*.cpp" "SerializationUtils.cpp")

file(GLOB_RECURSE TEST_SOURCES "Tests/SerializationUtilsTest.cpp" "Tests/*.h" "Tests/*.cpp")

include(GoogleTest)
find_package(GTest REQUIRED)
include_directories(${GMOCK_INCLUDE_DIR})
enable_testing()

find_package(Protobuf REQUIRED)
include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

file(GLOB_RECURSE PROTO_SOURCES CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/ProtoFile/*.proto)
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_SOURCES})
message("Generated ${PROTO_SRCS} ${PROTO_HDRS}")

SET_SOURCE_FILES_PROPERTIES(${PROTO_SRCS} ${PROTO_HDRS} PROPERTIES GENERATED TRUE)
#gRPC###################################

set(_PROTOBUF_LIBPROTOBUF protobuf::libprotobuf)
set(_REFLECTION gRPC::grpc++_reflection)


# Find gRPC installation
# Looks for gRPCConfig.cmake file installed by gRPC's cmake installation.
find_package(gRPC REQUIRED)
message(STATUS "Using gRPC ${gRPC_VERSION}")

set(_GRPC_GRPCPP gRPC::grpc++ gRPC::grpc++_reflection)
find_program(_GRPC_CPP_PLUGIN_EXECUTABLE grpc_cpp_plugin)

##########################################

# Proto file
get_filename_component(ts_proto "ProtoFile/CoreService.proto" ABSOLUTE)
get_filename_component(ts_proto_path "${ts_proto}" PATH)

set(ts_proto_srcs "${CMAKE_CURRENT_BINARY_DIR}/CoreService.pb.cc")
set(ts_proto_hdrs "${CMAKE_CURRENT_BINARY_DIR}/CoreService.pb.h")
set(ts_grpc_srcs "${CMAKE_CURRENT_BINARY_DIR}/CoreService.grpc.pb.cc")
set(ts_grpc_hdrs "${CMAKE_CURRENT_BINARY_DIR}/CoreService.grpc.pb.h")
add_custom_command(
        OUTPUT "${ts_proto_srcs}" "${ts_proto_hdrs}" "${ts_grpc_srcs}" "${ts_grpc_hdrs}"
        COMMAND protoc
        ARGS -I "${ts_proto_path}"
        --grpc_out "${CMAKE_CURRENT_BINARY_DIR}"
        --cpp_out "${CMAKE_CURRENT_BINARY_DIR}"
        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
        ${ts_proto}
        DEPENDS ${ts_proto})

add_executable(toDoList ${CLI_HEADERS}
        ${CLI_SOURCES} main.cpp ${PROTO_SRCS}
        ${PROTO_HDRS} ${ts_proto_srcs} ${ts_grpc_hdrs}
        ${ts_grpc_srcs})

add_executable(TestsExecutable ${TEST_SOURCES}
        ${CORE_SOURCES} ${CORE_HEADERS} ${CLI_SOURCES} ${CLI_HEADERS}
        ${PROTO_SRCS} ${PROTO_HDRS} ${ts_proto_srcs} ${ts_grpc_hdrs}
        ${ts_grpc_srcs})

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

add_executable(runServer
        "ServerRun.cpp" ${CORE_SOURCES} ${CORE_HEADERS} ${PROTO_SRCS} ${PROTO_HDRS}
        ${ts_proto_srcs} ${ts_grpc_hdrs} ${ts_grpc_srcs})

target_link_libraries(runServer
        ${Boost_LIBRARIES}
        ${Protobuf_LIBRARIES}
        ${_GRPC_GRPCPP})
target_link_libraries(toDoList
        ${Boost_LIBRARIES}
        ${Protobuf_LIBRARIES}
        ${_GRPC_GRPCPP})
target_link_libraries(TestsExecutable
        GTest::GTest
        GTest::Main
        ${GMOCK_LIBRARY}
        ${GMOCK_MAIN_LIBRARY}
        gmock
        gmock_main
        ${Protobuf_LIBRARIES}
        ${_GRPC_GRPCPP}
        ${Boost_LIBRARIES})
gtest_discover_tests(TestsExecutable)