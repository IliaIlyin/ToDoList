//
// Created by ilya on 18.10.20.
//


#include <gmock/gmock.h>
#include <string>
#include "Commands/Show/ShowDueDate/ShowDueDateByDateCommand.h"
#include "Core/Mocks/CoreAPIMock.h"
#include "CLI/Mocks/VisitorMock.h"
using testing::Eq;
using testing::Return;
using testing::ReturnRef;
using testing::Mock;
class ShowDueDateByDateCommandTest : public testing::Test {

};

TEST_F(ShowDueDateByDateCommandTest, shouldExecuteCommand) {
  auto service = std::make_shared<CoreAPIMock>();
  TaskID id(1);
  boost::gregorian::date date{2000, 11, 20};
  std::vector<TaskDTO> vec;
  Task parent = Task::createTask("Elon", boost::gregorian::date{2000, 11, 11}, Task::Priority::FIRST, "label");
  TaskDTO dto(parent, id, false);
  vec.push_back(dto);
  EXPECT_CALL(service.operator*(), showDueDateByDate(date)).Times(1).WillOnce(Return(vec));
  ShowDueDateByDateCommand command(service, date);
  command.execute();
  ASSERT_EQ(command.getCommandResult(), vec);
}

bool operator==(const ShowDueDateByDateCommand first, const ShowDueDateByDateCommand sec) {
  return true;
}

TEST_F(ShowDueDateByDateCommandTest, shouldAcceptVisitor) {
  boost::gregorian::date date{2000, 11, 20};
  auto service = std::make_shared<CoreAPIMock>();
  auto visitor = std::make_shared<VisitorMock>();
  ShowDueDateByDateCommand command(service, date);
  EXPECT_CALL(visitor.operator*(), visitShowDueDateByDateCommand(command)).Times(1);
  ASSERT_NO_THROW(command.accept(visitor));
}
