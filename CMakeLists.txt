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
file(GLOB_RECURSE CPP_SOURCES
        "Core/API/*.cpp"
        "Core/Model/*.cpp"
        "Core/Views/*.cpp"
        "Core/Serialization/*.cpp"
        "CLI/*.cpp")
file(GLOB_RECURSE HEADERS "Core/API/*.h" "Core/Model/.*h" "Core/Views/.*h" "CLI/.*h" "Core/Serialization/.*h")
file(GLOB_RECURSE TEST_SOURCES "Tests/*.cpp")
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
                ${CPP_SOURCES} ${HEADERS} ${PROTO_SRCS} ${PROTO_HDRS} Tests/Core/Serialization/PersistorTest.cpp Core/Model/AllDataStorageFactoryInterface.h Core/API/CoreAPIInterface.h Tests/Core/Model/AllDataStorageTest.cpp Core/Views/ViewServiceInterface.h Tests/Core/Model/AllDataStorageFactoryTest.cpp Tests/Core/Mocks/AllDataStorageMock.h Tests/Core/Mocks/ViewServiceMock.h Tests/Core/Mocks/AllDataStorageFactoryMock.h Tests/Core/API/CoreApiTest.cpp CLI/Builders/Serialize/SaveCommandBuilder.h CLI/Builders/Serialize/SaveCommandBuilder.cpp CLI/Builders/Serialize/SaveCommandBuilder.h CLI/Builders/Serialize/LoadCommandBuilder.cpp CLI/Builders/Serialize/LoadCommandBuilder.h CLI/Commands/Serialize/SaveCommand.cpp CLI/Commands/Serialize/SaveCommand.h CLI/Commands/Serialize/LoadCommand.cpp CLI/Commands/Serialize/LoadCommand.h CLI/Visitors/Serialize/SaveCommandVisitor.cpp CLI/Visitors/Serialize/SaveCommandVisitor.h CLI/Visitors/Serialize/LoadCommandVisitor.cpp CLI/Visitors/Serialize/LoadCommandVisitor.h Tests/CLI/Builders/Add/AddSubTaskCommandBuilderTest.cpp CLI/InputStateMachineInterface.h CLI/StateMachineInterface.h CLI/Contexts/ContextInterface.h CLI/Contexts/InputContextInterface.h CLI/Utils/InputStateMachineCreator.cpp CLI/Utils/InputStateMachineCreator.h CLI/Utils/InputContextCreator.cpp CLI/Utils/InputContextCreator.h CLI/Utils/InputContextCreatorInterface.h CLI/Utils/InputStateMachineCreatorInterface.h Tests/Core/Mocks/CoreAPIMock.h Tests/CLI/Mocks/InputStateMachineMock.h Tests/CLI/Builders/Add/AddTaskCommandBuilderTest.cpp Tests/CLI/Builders/Get/GetTaskCommandBuilderTest.cpp Tests/CLI/Builders/Get/GetSubTasksCommandBuilderTest.cpp Tests/CLI/Builders/Other/CompleteTaskCommandBuilderTest.cpp Tests/CLI/Builders/Other/PostponeTaskCommandBuilderTest.cpp Tests/CLI/Builders/Other/DeleteTaskCommandBuilderTest.cpp Tests/CLI/Builders/Serialize/SaveCommandBuilderTest.cpp Tests/CLI/Builders/Serialize/LoadCommandBuilderTest.cpp Tests/CLI/Builders/Show/ShowAll/ShowAllByDateCommandBuilderTest.cpp Tests/CLI/Builders/Show/ShowAll/ShowAllByLabelCommandBuilderTest.cpp Tests/CLI/Builders/Show/ShowAll/ShowAllByPriorityCommandBuilderTest.cpp Tests/CLI/Builders/Show/ShowDueDate/ShowDueDateByDateCommandBuilderTest.cpp Tests/CLI/Builders/Show/ShowDueDate/ShowDueDateByLabelCommandBuilderTest.cpp Tests/CLI/Builders/Show/ShowDueDate/ShowDueDateByPriorityCommandBuilderTest.cpp Tests/CLI/Builders/Show/ShowToday/ShowTodayByLabelCommandBuilderTest.cpp Tests/CLI/Builders/Show/ShowToday/ShowTodayByPriorityCommandBuilderTest.cpp Tests/CLI/Commands/Add/AddSubTaskCommandTest.cpp Tests/CLI/Commands/Add/AddTaskCommandTest.cpp Tests/CLI/Mocks/VisitorMock.h Tests/CLI/Commands/Get/GetSubtasksCommandTest.cpp Tests/CLI/Commands/Get/GetTaskCommandTest.cpp Tests/CLI/Commands/Other/CompleteTaskCommandTest.cpp Tests/CLI/Commands/Other/DeleteTaskCommandTest.cpp Tests/CLI/Commands/Other/PostponeTaskCommandTest.cpp Tests/CLI/Commands/Serialize/SaveCommandTest.cpp Tests/CLI/Commands/Serialize/LoadCommandTest.cpp Tests/CLI/Commands/Show/ShowAll/ShowAllByLabelCommandTest.cpp Tests/CLI/Commands/Show/ShowAll/ShowAllByDateCommandTest.cpp Tests/CLI/Commands/Show/ShowAll/ShowAllByPriorityCommandTest.cpp Tests/CLI/Commands/Show/ShowDueDate/ShowDueDateByDateCommandTest.cpp Tests/CLI/Commands/Show/ShowDueDate/ShowDueDateByLabelCommandTest.cpp Tests/CLI/Commands/Show/ShowDueDate/ShowDueDateByPriorityCommandTest.cpp Tests/CLI/Commands/Show/ShowToday/ShowTodayByLabelCommandTest.cpp Tests/CLI/Commands/Show/ShowToday/ShowTodayByPriorityCommandTest.cpp Tests/CLI/ContextTest.cpp Tests/CLI/Visitors/Add/AddTaskCommandVisitorTest.cpp Tests/CLI/Visitors/Add/AddSubTaskCommandVisitorTest.cpp Tests/CLI/Visitors/Get/GetTaskCommandVisitorTest.cpp Tests/CLI/Visitors/Get/GetSubTasksCommandVisitorTest.cpp Tests/CLI/Visitors/Other/CompleteTaskCommandVisitorTest.cpp Tests/CLI/Visitors/Other/DeleteTaskCommandVisitorTest.cpp Tests/CLI/Visitors/Other/PostponeTaskCommandVisitorTest.cpp Tests/CLI/Visitors/Serialize/SaveCommandVisitorTest.cpp Tests/CLI/Visitors/Serialize/LoadCommandVisitorTest.cpp Tests/CLI/Visitors/Show/ShowAll/ShowAllByDateCommandVisitorTest.cpp Tests/CLI/Visitors/Show/ShowAll/ShowAllByLabelCommandVisitor.cpp Tests/CLI/Visitors/Show/ShowAll/ShowAllByPriorityCommandVisitorTest.cpp Tests/CLI/Visitors/Show/ShowDueDate/ShowDueDateByDateCommandVisitorTest.cpp Tests/CLI/Visitors/Show/ShowDueDate/ShowDueDateByPriorityCommandVisitorTest.cpp Tests/CLI/Visitors/Show/ShowDueDate/ShowDueDateByLabelCommandVisitorTest.cpp Tests/CLI/Visitors/Show/ShowToday/ShowTodayByLabelCommandVisitorTest.cpp Tests/CLI/Visitors/Show/ShowToday/ShowTodayByPriorityCommandVisitorTest.cpp Tests/CLI/Factories/Validators/GeneralCommandsValidatorTest.cpp Tests/CLI/Factories/Validators/GeneralInputValidatorTest.cpp Tests/CLI/Validators/BaseStateValidatorTest.cpp Tests/CLI/Validators/InputValidators/DateValidatorTest.cpp Tests/CLI/Validators/InputValidators/LabelValidatorTest.cpp Tests/CLI/Validators/InputValidators/TaskNameValidatorTest.cpp Tests/CLI/Validators/InputValidators/TaskIdValidatorTest.cpp Tests/CLI/Validators/InputValidators/ExitValidatorTest.cpp Tests/CLI/Validators/InputValidators/PriorityValidatorTest.cpp)
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
target_link_libraries(TestsExecutable gmock gmock_main)
target_link_libraries(TestsExecutable ${Protobuf_LIBRARIES})
target_link_libraries(toDoList ${Protobuf_LIBRARIES})
gtest_discover_tests(TestsExecutable)
