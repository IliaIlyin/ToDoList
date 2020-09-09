cmake_minimum_required(VERSION 3.15)
project(toDoList LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
include_directories(src)
include_directories(CLI)
file(GLOB CPP_SOURCES "src/API/*.cpp" "src/Model/*.cpp" "src/Views/*.cpp")

file(GLOB HEADERS "src/API/*.h" "src/Model/.*h" "src/Views/.*h")
file(GLOB TEST_SOURCES "Tests/*.cpp")

add_executable(toDoList ${HEADERS} ${CPP_SOURCES} main.cpp)

include(GoogleTest)
find_package(GTest REQUIRED)
include_directories(${GMOCK_INCLUDE_DIR})
enable_testing()


add_executable(TestsExecutable ${TEST_SOURCES}
                ${CPP_SOURCES} CLI/State.h CLI/Contexts/Context.cpp CLI/Contexts/Context.h CLI/StateMachine.cpp CLI/StateMachine.h CLI/States/ViewState.cpp CLI/States/ViewState.h CLI/States/BaseState.cpp CLI/States/BaseState.h CLI/States/ExitState.cpp CLI/States/ExitState.h CLI/CommandsValidator.cpp CLI/CommandsValidator.h CLI/States/AddTaskState.cpp CLI/States/AddTaskState.h CLI/States/ViewTaskState.cpp CLI/States/ViewTaskState.h CLI/Validators/Validator.h CLI/Validators/AddTaskValidator.cpp CLI/Validators/AddTaskValidator.h CLI/Validators/ViewTaskValidator.cpp CLI/Validators/ViewTaskValidator.h CLI/Validators/AddSubTaskValidator.cpp CLI/Validators/AddSubTaskValidator.h CLI/Validators/GetTaskValidator.cpp CLI/Validators/GetTaskValidator.h CLI/Validators/TaskNameValidator.cpp CLI/Validators/TaskNameValidator.h CLI/Validators/DateValidator.cpp CLI/Validators/DateValidator.h CLI/Validators/PriorityValidator.cpp CLI/Validators/PriorityValidator.h CLI/Validators/LabelValidator.cpp CLI/Validators/LabelValidator.h CLI/States/TaskNameState.cpp CLI/States/TaskNameState.h CLI/States/TaskPriorityState.cpp CLI/States/TaskPriorityState.h CLI/States/TaskDateState.cpp CLI/States/TaskDateState.h CLI/States/TaskLabelState.cpp CLI/States/TaskLabelState.h CLI/States/TaskIdState.cpp CLI/States/TaskIdState.h CLI/Validators/TaskIdValidator.cpp CLI/Validators/TaskIdValidator.h CLI/Tokenizer.cpp CLI/Tokenizer.h CLI/Validators/BaseStateValidator.cpp CLI/Validators/BaseStateValidator.h CLI/Contexts/AddContext.cpp CLI/Contexts/AddContext.h CLI/Commands/Add/AddTaskCommand.cpp CLI/Commands/Add/AddTaskCommand.h CLI/Commands/Add/AddSubTaskCommand.cpp CLI/Commands/Add/AddSubTaskCommand.h CLI/Commands/Get/GetTaskCommand.cpp CLI/Commands/Get/GetTaskCommand.h CLI/Command.h CLI/Commands/Show/ShowAll/ShowAllByLabelCommand.cpp CLI/Commands/Show/ShowAll/ShowAllByLabelCommand.h CLI/Commands/Other/DeleteTaskCommand.cpp CLI/Commands/Other/DeleteTaskCommand.h CLI/Commands/Show/ShowDueDate/ShowDueDateByDateCommand.cpp CLI/Commands/Show/ShowDueDate/ShowDueDateByDateCommand.h CLI/Commands/Other/PostponeTaskCommand.cpp CLI/Commands/Other/PostponeTaskCommand.h CLI/Commands/Other/CompleteTaskCommand.cpp CLI/Commands/Other/CompleteTaskCommand.h CLI/Commands/Get/GetSubtasksCommand.cpp CLI/Commands/Get/GetSubtasksCommand.h CLI/CommandFactory.cpp CLI/CommandFactory.h CLI/Commands/Show/ShowAll/ShowAllByPriorityCommand.cpp CLI/Commands/Show/ShowAll/ShowAllByPriorityCommand.h CLI/Commands/Show/ShowAll/ShowAllByDateCommand.cpp CLI/Commands/Show/ShowAll/ShowAllByDateCommand.h CLI/Commands/Show/ShowDueDate/ShowDueDateByLabelCommand.cpp CLI/Commands/Show/ShowDueDate/ShowDueDateByLabelCommand.h CLI/Commands/Show/ShowDueDate/ShowDueDateByPriorityCommand.cpp CLI/Commands/Show/ShowDueDate/ShowDueDateByPriorityCommand.h CLI/Commands/Show/ShowToday/ShowTodayByLabelCommand.cpp CLI/Commands/Show/ShowToday/ShowTodayByLabelCommand.h CLI/Commands/Show/ShowToday/ShowTodayByPriorityCommand.cpp CLI/Commands/Show/ShowToday/ShowTodayByPriorityCommand.h CLI/Visitor.h CLI/Visitors/Add/AddTaskCommandVisitor.cpp CLI/Visitors/Add/AddTaskCommandVisitor.h CLI/Visitors/Add/AddSubTaskCommandVisitor.cpp CLI/Visitors/Add/AddSubTaskCommandVisitor.h CLI/Visitors/Get/GetTaskCommandVisitor.cpp CLI/Visitors/Get/GetTaskCommandVisitor.h CLI/Visitors/Get/GetSubTaskCommandVisitor.cpp CLI/Visitors/Get/GetSubTaskCommandVisitor.h CLI/States/AddSubTaskState.cpp CLI/States/AddSubTaskState.h)

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
