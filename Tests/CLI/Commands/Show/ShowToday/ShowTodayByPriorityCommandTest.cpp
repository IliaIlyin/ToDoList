//
// Created by ilya on 18.10.20.
//


#include <gmock/gmock.h>
#include <string>
#include "Commands/Show/ShowToday/ShowTodayByPriorityCommand.h"
#include "Core/Mocks/CoreAPIMock.h"
#include "CLI/Mocks/VisitorMock.h"
using testing::Eq;
using testing::Return;
using testing::ReturnRef;
using testing::Mock;
class ShowTodayByPriorityCommandTest : public testing::Test {

};

TEST_F(ShowTodayByPriorityCommandTest, shouldExecuteCommand) {
  auto service = std::make_shared<CoreAPIMock>();
  TaskID id(1);
  std::vector<TaskDTO> vec;
  Task parent = Task::createTask("Elon", boost::gregorian::date{2000, 11, 11}, Task::Priority::FIRST, "label");
  TaskDTO dto(parent, id, false);
  vec.push_back(dto);
  EXPECT_CALL(service.operator*(), showTodayByPriority()).Times(1).WillOnce(Return(vec));
  ShowTodayByPriorityCommand command(service);
  command.execute();
  ASSERT_EQ(command.getCommandResult(), vec);
}

bool operator==(const ShowTodayByPriorityCommand first, const ShowTodayByPriorityCommand sec) {
  return true;
}

TEST_F(ShowTodayByPriorityCommandTest, shouldAcceptVisitor) {
  auto service = std::make_shared<CoreAPIMock>();
  auto visitor = std::make_shared<VisitorMock>();
  ShowTodayByPriorityCommand command(service);
  EXPECT_CALL(visitor.operator*(), visitShowTodayPriorityCommand(command)).Times(1);
  ASSERT_NO_THROW(command.accept(visitor));
}
