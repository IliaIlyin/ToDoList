//
// Created by ilya on 18.10.20.
//


#include <gmock/gmock.h>
#include <string>
#include "Commands/Other/PostponeTaskCommand.h"
#include "Core/Mocks/CoreAPIMock.h"
#include "CLI/Mocks/VisitorMock.h"
using testing::Eq;
using testing::Return;
using testing::ReturnRef;
using testing::Mock;
class PostponeTaskCommandTest : public testing::Test {

};

TEST_F(PostponeTaskCommandTest, shouldExecuteCommand) {
  auto service = std::make_shared<CoreAPIMock>();
  TaskID id(1);
  boost::gregorian::date date{2000, 11, 20};
  Task parent = Task::createTask("Elon", boost::gregorian::date{2000, 11, 11}, Task::Priority::FIRST, "label");
  TaskDTO dto(parent, id, false);
  EXPECT_CALL(service.operator*(), postponeTask(id, date)).Times(2).WillOnce(Return(true)).WillOnce(Return(false));
  PostponeTaskCommand command(service, id, date);
  command.execute();
  ASSERT_EQ(command.getPostponeTaskCommandResult(), true);
  command.execute();
  ASSERT_EQ(command.getPostponeTaskCommandResult(), false);
}

bool operator==(const PostponeTaskCommand first, const PostponeTaskCommand sec) {
  return true;
}

TEST_F(PostponeTaskCommandTest, shouldAcceptVisitor) {
  boost::gregorian::date date{2000, 11, 20};
  auto service = std::make_shared<CoreAPIMock>();
  auto visitor = std::make_shared<VisitorMock>();
  TaskID id(1);
  PostponeTaskCommand command(service, id, date);
  EXPECT_CALL(visitor.operator*(), visitPostponeTaskCommand(command)).Times(1);
  ASSERT_NO_THROW(command.accept(visitor));
}
