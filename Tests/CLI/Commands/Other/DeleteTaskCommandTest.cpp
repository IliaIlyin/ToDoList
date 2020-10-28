//
// Created by ilya on 18.10.20.
//


#include <gmock/gmock.h>
#include <string>
#include "Commands/Other/DeleteTaskCommand.h"
#include "Core/Mocks/CoreAPIMock.h"
#include "CLI/Mocks/VisitorMock.h"
using testing::Eq;
using testing::Return;
using testing::ReturnRef;
using testing::Mock;
class DeleteTaskCommandTest : public testing::Test {

};

TEST_F(DeleteTaskCommandTest, shouldExecuteCommand) {
  auto service = std::make_shared<CoreAPIMock>();
  TaskID id(1);
  Task parent = Task::createTask("Elon", boost::gregorian::date{2000, 11, 11}, Task::Priority::FIRST, "label");
  TaskDTO dto(parent, id, false);
  EXPECT_CALL(service.operator*(), deleteTask(id)).Times(2).WillOnce(Return(true)).WillOnce(Return(false));
  DeleteTaskCommand command(service, id);
  command.execute();
  ASSERT_EQ(command.getDeleteTaskCommandResult(), true);
  command.execute();
  ASSERT_EQ(command.getDeleteTaskCommandResult(), false);
}

bool operator==(const DeleteTaskCommand first, const DeleteTaskCommand sec) {
  return true;
}

TEST_F(DeleteTaskCommandTest, shouldAcceptVisitor) {
  auto service = std::make_shared<CoreAPIMock>();
  auto visitor = std::make_shared<VisitorMock>();
  TaskID id(1);
  DeleteTaskCommand command(service, id);
  EXPECT_CALL(visitor.operator*(), visitDeleteTaskCommand(command)).Times(1);
  ASSERT_NO_THROW(command.accept(visitor));
}
