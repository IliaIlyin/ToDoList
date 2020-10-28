//
// Created by ilya on 18.10.20.
//


#include <gmock/gmock.h>
#include <string>
#include "Commands/Show/ShowAll/ShowAllByDateCommand.h"
#include "Core/Mocks/CoreAPIMock.h"
#include "CLI/Mocks/VisitorMock.h"
using testing::Eq;
using testing::Return;
using testing::ReturnRef;
using testing::Mock;
class ShowAllByDateCommandTest : public testing::Test {

};

TEST_F(ShowAllByDateCommandTest, shouldExecuteCommand) {
  auto service = std::make_shared<CoreAPIMock>();
  TaskID id(1);
  std::vector<TaskDTO> vec;
  Task parent = Task::createTask("Elon", boost::gregorian::date{2000, 11, 11}, Task::Priority::FIRST, "label");
  TaskDTO dto(parent, id, false);
  vec.push_back(dto);
  EXPECT_CALL(service.operator*(), showAllByDate()).Times(1).WillOnce(Return(vec));
  ShowAllByDateCommand command(service);
  command.execute();
  ASSERT_EQ(command.getCommandResult(), vec);
}

bool operator==(const ShowAllByDateCommand first, const ShowAllByDateCommand sec) {
  return true;
}

TEST_F(ShowAllByDateCommandTest, shouldAcceptVisitor) {
  auto service = std::make_shared<CoreAPIMock>();
  auto visitor = std::make_shared<VisitorMock>();
  ShowAllByDateCommand command(service);
  EXPECT_CALL(visitor.operator*(), visitShowAllByDateCommand(command)).Times(1);
  ASSERT_NO_THROW(command.accept(visitor));
}
