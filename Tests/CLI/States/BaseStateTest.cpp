//
// Created by ilya on 19.10.20.
//

#include "States/BaseState.h"
#include "Validators/BaseStateValidator.h"
#include "CLI/Mocks/CommandMock.h"
#include "Visitors/Add/AddTaskCommandVisitor.h"
#include "CLI/Mocks/IOStreamMock.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>

using testing::Eq;
using testing::Return;
using testing::ReturnRef;
using testing::Mock;

class BaseStateTest : public ::testing::Test {

};
TEST_F(BaseStateTest, shouldExecuteCommand) {
  auto validator = std::make_shared<BaseStateValidator>();
  std::shared_ptr<IOStreamInterface> inputer = std::make_shared<IOStreamMock>();
  std::shared_ptr<Visitor> ptr = std::make_shared<AddTaskCommandVisitor>(inputer);
  BaseState base(validator);
  auto mock = std::make_shared<CommandMock>();
  EXPECT_CALL(mock.operator*(), accept(ptr));
  base.execute(mock, ptr);
}
TEST_F(BaseStateTest, shouldChangeState) {
  auto validator = std::make_shared<BaseStateValidator>();
  std::shared_ptr<IOStreamInterface> inputer = std::make_shared<IOStreamMock>();
  std::shared_ptr<Visitor> ptr = std::make_shared<AddTaskCommandVisitor>(inputer);
  BaseState base(validator);
  ASSERT_NE(base.changeState(), nullptr);
}
TEST_F(BaseStateTest, shouldPrintDTO) {
  auto validator = std::make_shared<BaseStateValidator>();
  auto inputer = std::make_shared<IOStreamMock>();
  std::shared_ptr<Context> context = std::make_shared<Context>();
  TaskID id(1);
  Task parent = Task::createTask("Elon", boost::gregorian::date{2000, 11, 11}, Task::Priority::FIRST, "label");
  TaskDTO dto(parent, id, false);
  context->SetDto(dto);
  std::shared_ptr<Visitor> ptr = std::make_shared<AddTaskCommandVisitor>(inputer);
  BaseState base(validator);
  std::stringstream str;
  str << "Task Name: ";
  str << dto.getTask().getName();
  EXPECT_CALL(inputer.operator*(), print(str.str())).Times(1);
  str.str(std::string());
  str << "Task Date: " << dto.getTask().getDate();
  EXPECT_CALL(inputer.operator*(), print(str.str())).Times(1);
  str.str(std::string());
  str << "Task Label: " << dto.getTask().getLabel();
  EXPECT_CALL(inputer.operator*(), print(str.str())).Times(1);
  str.str(std::string());
  str << "Task Priority: " << dto.getTask().getPriority();
  EXPECT_CALL(inputer.operator*(), print(str.str())).Times(1);
  str.str(std::string());
  str << "Task status: " << dto.checkStatus();
  EXPECT_CALL(inputer.operator*(), print(str.str())).Times(1);
  str.str(std::string());
  std::string input = "Welcome User! Available commands: \n"
                      "Add task\n"
                      "Add subTask\n"
                      "get task\n"
                      "get subTasks\n"
                      "postpone task\n"
                      "complete task\n"
                      "delete task\n"
                      "show all sort priority\n"
                      "show all sort date\n"
                      "show all sort label\n"
                      "show today sort priority\n"
                      "show today sort label\n"
                      "show due date sort label\n"
                      "show due date sort priority\n"
                      "show due date sort date\n"
                      "exit\n"
                      "save\n"
                      "load\n";
  str << input;
  EXPECT_CALL(inputer.operator*(), print(str.str())).Times(1);
  ASSERT_NO_THROW(base.print(context, inputer));
}
TEST_F(BaseStateTest, shouldPrintDTOsNotEmpty) {
  std::vector<TaskDTO> vec;
  auto validator = std::make_shared<BaseStateValidator>();
  auto inputer = std::make_shared<IOStreamMock>();
  std::shared_ptr<Context> context = std::make_shared<Context>();
  TaskID id(1);
  Task parent = Task::createTask("Elon", boost::gregorian::date{2000, 11, 11}, Task::Priority::FIRST, "label");
  TaskDTO dto(parent, id, false);
  vec.push_back(dto);
  context->SetDtos(vec);
  std::shared_ptr<Visitor> ptr = std::make_shared<AddTaskCommandVisitor>(inputer);
  BaseState base(validator);
  std::stringstream str;
  str << "Task Id: " << dto.getTaskId().getId();
  EXPECT_CALL(inputer.operator*(), print(str.str()));
  str.str(std::string());
  str << "Task Name: " << dto.getTask().getName();
  EXPECT_CALL(inputer.operator*(), print(str.str()));
  str.str(std::string());
  std::string input = "Welcome User! Available commands: \n"
                      "Add task\n"
                      "Add subTask\n"
                      "get task\n"
                      "get subTasks\n"
                      "postpone task\n"
                      "complete task\n"
                      "delete task\n"
                      "show all sort priority\n"
                      "show all sort date\n"
                      "show all sort label\n"
                      "show today sort priority\n"
                      "show today sort label\n"
                      "show due date sort label\n"
                      "show due date sort priority\n"
                      "show due date sort date\n"
                      "exit\n"
                      "save\n"
                      "load\n";
  str << input;
  EXPECT_CALL(inputer.operator*(), print(str.str())).Times(1);
  ASSERT_NO_THROW(base.print(context, inputer));
}

TEST_F(BaseStateTest, shouldPrintDTOsEmpty) {
  std::vector<TaskDTO> vec;
  auto validator = std::make_shared<BaseStateValidator>();
  auto inputer = std::make_shared<IOStreamMock>();
  std::shared_ptr<Context> context = std::make_shared<Context>();
  TaskID id(1);
  context->SetDtos(vec);
  std::shared_ptr<Visitor> ptr = std::make_shared<AddTaskCommandVisitor>(inputer);
  BaseState base(validator);
  std::stringstream str;
  str << "No tasks";
  EXPECT_CALL(inputer.operator*(), print(str.str()));
  str.str(std::string());
  std::string input = "Welcome User! Available commands: \n"
                      "Add task\n"
                      "Add subTask\n"
                      "get task\n"
                      "get subTasks\n"
                      "postpone task\n"
                      "complete task\n"
                      "delete task\n"
                      "show all sort priority\n"
                      "show all sort date\n"
                      "show all sort label\n"
                      "show today sort priority\n"
                      "show today sort label\n"
                      "show due date sort label\n"
                      "show due date sort priority\n"
                      "show due date sort date\n"
                      "exit\n"
                      "save\n"
                      "load\n";
  str << input;
  EXPECT_CALL(inputer.operator*(), print(str.str())).Times(1);
  ASSERT_NO_THROW(base.print(context, inputer));
}

TEST_F(BaseStateTest, shouldRead) {
  auto validator = std::make_shared<BaseStateValidator>();
  auto inputer = std::make_shared<IOStreamMock>();
  EXPECT_CALL(inputer.operator*(), input()).Times(3).WillOnce(Return("Add task")).WillOnce(Return("get task")).WillOnce(
      Return("save"));
  std::shared_ptr<Context> context = std::make_shared<Context>();
  std::shared_ptr<Visitor> ptr = std::make_shared<AddTaskCommandVisitor>(inputer);
  BaseState base(validator);
  ASSERT_EQ(base.read(inputer), GeneralCommandsValidator::CommandToken::ADD_TASK);
  ASSERT_EQ(base.read(inputer), GeneralCommandsValidator::CommandToken::GET_TASK);
  ASSERT_EQ(base.read(inputer), GeneralCommandsValidator::CommandToken::SAVE);

}