//
// Created by ilya on 18.10.20.
//


#include <gmock/gmock.h>
#include <string>
#include "Commands/Get/GetSubtasksCommand.h"
#include "Core/Mocks/CoreAPIMock.h"
#include "CLI/Mocks/VisitorMock.h"
using testing::Eq;
using testing::Return;
using testing::ReturnRef;
using testing::Mock;
class GetSubtasksCommandTest : public testing::Test {

};

TEST_F(GetSubtasksCommandTest, shouldExecuteCommand) {
  auto service = std::make_shared<CoreAPIMock>();
  TaskID id(1);
  std::vector<TaskDTO> vec;
  Task parent = Task::createTask("Elon", boost::gregorian::date{2000, 11, 11}, Task::Priority::FIRST, "label");
  TaskDTO dto(parent, id, false);
  vec.push_back(dto);
  EXPECT_CALL(service.operator*(), getSubTasks(id)).Times(2).WillOnce(Return(vec)).WillOnce(Return(std::nullopt));
  GetSubTaskCommand command(service, id);
  command.execute();
  ASSERT_EQ(command.GetGetSubTaskCommandResult(), vec);
  command.execute();
  ASSERT_EQ(command.GetGetSubTaskCommandResult(), std::nullopt);
}

bool operator==(const GetSubTaskCommand first, const GetSubTaskCommand sec) {
  return true;
}

TEST_F(GetSubtasksCommandTest, shouldAcceptVisitor) {
  auto service = std::make_shared<CoreAPIMock>();
  auto visitor = std::make_shared<VisitorMock>();
  TaskID id(1);
  GetSubTaskCommand command(service, id);
  EXPECT_CALL(visitor.operator*(), visitGetSubTaskCommand(command)).Times(1);
  ASSERT_NO_THROW(command.accept(visitor));
}
