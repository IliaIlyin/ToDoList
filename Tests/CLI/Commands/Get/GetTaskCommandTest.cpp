//
// Created by ilya on 18.10.20.
//


#include <gmock/gmock.h>
#include <string>
#include "Commands/Get/GetTaskCommand.h"
#include "Core/Mocks/CoreAPIMock.h"
#include "CLI/Mocks/VisitorMock.h"
using testing::Eq;
using testing::Return;
using testing::ReturnRef;
using testing::Mock;
class GetTaskCommandTest : public testing::Test {

};

TEST_F(GetTaskCommandTest, shouldExecuteCommand) {
  auto service = std::make_shared<CoreAPIMock>();
  TaskID id(1);
  Task parent = Task::createTask("Elon", boost::gregorian::date{2000, 11, 11}, Task::Priority::FIRST, "label");
  TaskDTO dto(parent,id,false);
  EXPECT_CALL(service.operator*(), getTask(id)).Times(2).WillOnce(Return(dto)).WillOnce(Return(std::nullopt));
  GetTaskCommand command(service,id);
  command.execute();
  ASSERT_EQ(command.GetGetTaskCommandResult(), dto);
  command.execute();
  ASSERT_EQ(command.GetGetTaskCommandResult(), std::nullopt);
}

bool operator ==(const GetTaskCommand first,const GetTaskCommand sec){
  return true;
}

TEST_F(GetTaskCommandTest, shouldAcceptVisitor) {
  auto service = std::make_shared<CoreAPIMock>();
  auto visitor = std::make_shared<VisitorMock>();
  TaskID id(1);
  GetTaskCommand command(service, id);
  EXPECT_CALL(visitor.operator*(), visitGetTaskCommand(command)).Times(1);
  ASSERT_NO_THROW(command.accept(visitor));
}
