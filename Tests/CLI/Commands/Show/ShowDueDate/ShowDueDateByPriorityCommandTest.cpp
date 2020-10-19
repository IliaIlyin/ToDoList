//
// Created by ilya on 18.10.20.
//

//
// Created by ilya on 18.10.20.
//


#include <gmock/gmock.h>
#include <string>
#include "Commands/Show/ShowDueDate/ShowDueDateByPriorityCommand.h"
#include "Core/Mocks/CoreAPIMock.h"
#include "CLI/Mocks/VisitorMock.h"
using testing::Eq;
using testing::Return;
using testing::ReturnRef;
using testing::Mock;
class ShowDueDateByPriorityCommandTest : public testing::Test {

};

TEST_F(ShowDueDateByPriorityCommandTest, shouldExecuteCommand) {
  auto service = std::make_shared<CoreAPIMock>();
  TaskID id(1);
  boost::gregorian::date date{2000, 11, 20};
  std::vector<TaskDTO> vec;
  Task parent = Task::createTask("Elon", boost::gregorian::date{2000, 11, 11}, Task::Priority::FIRST, "label");
  TaskDTO dto(parent, id, false);
  vec.push_back(dto);
  EXPECT_CALL(service.operator*(), showDueDateByPriority(date)).Times(1).WillOnce(Return(vec));
  ShowDueDateByPriorityCommand command(service, date);
  command.execute();
  ASSERT_EQ(command.getCommandResult(), vec);
}

bool operator==(const ShowDueDateByPriorityCommand first, const ShowDueDateByPriorityCommand sec) {
  return true;
}

TEST_F(ShowDueDateByPriorityCommandTest, shouldAcceptVisitor) {
  boost::gregorian::date date{2000, 11, 20};
  auto service = std::make_shared<CoreAPIMock>();
  auto visitor = std::make_shared<VisitorMock>();
  ShowDueDateByPriorityCommand command(service, date);
  EXPECT_CALL(visitor.operator*(), visitShowDueDateByPriorityCommand(command)).Times(1);
  ASSERT_NO_THROW(command.accept(visitor));
}
