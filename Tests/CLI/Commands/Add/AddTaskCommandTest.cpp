//
// Created by ilya on 18.10.20.
//

#include <gmock/gmock.h>
#include <string>
#include "Commands/Add/AddTaskCommand.h"
#include "Core/Mocks/CoreAPIMock.h"
#include "CLI/Mocks/VisitorMock.h"
using testing::Eq;
using testing::Return;
using testing::ReturnRef;
using testing::Mock;
class AddTaskCommandTest : public testing::Test {

};

TEST_F(AddTaskCommandTest, shouldExecuteCommand) {
  auto service = std::make_shared<CoreAPIMock>();
  Task parent = Task::createTask("Elon", boost::gregorian::date{2000, 11, 11}, Task::Priority::FIRST, "label");
  EXPECT_CALL(service.operator*(), addTask(parent)).Times(2).WillOnce(Return(true)).WillOnce(Return(false));
  AddTaskCommand command(service, parent);
  command.execute();
  ASSERT_EQ(command.getAddTaskResult(), true);
  command.execute();
  ASSERT_EQ(command.getAddTaskResult(), false);
}

bool operator==(const AddTaskCommand first, const AddTaskCommand sec) {
  return true;
}

TEST_F(AddTaskCommandTest, shouldAcceptVisitor) {
  auto service = std::make_shared<CoreAPIMock>();
  auto visitor = std::make_shared<VisitorMock>();
  Task parent = Task::createTask("Elon", boost::gregorian::date{2000, 11, 11}, Task::Priority::FIRST, "label");
  AddTaskCommand command(service, parent);
  EXPECT_CALL(visitor.operator*(), visitAddTaskCommand(command)).Times(1);
  ASSERT_NO_THROW(command.accept(visitor));
}
