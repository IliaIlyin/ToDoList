//
// Created by ilya on 18.10.20.
//


#include <gmock/gmock.h>
#include <string>
#include "Commands/Other/CompleteTaskCommand.h"
#include "Core/Mocks/CoreAPIMock.h"
#include "CLI/Mocks/VisitorMock.h"
using testing::Eq;
using testing::Return;
using testing::ReturnRef;
using testing::Mock;
class CompleteTaskCommandTest : public testing::Test {

};

TEST_F(CompleteTaskCommandTest, shouldExecuteCommand) {
  auto service = std::make_shared<CoreAPIMock>();
  TaskID id(1);
  Task parent = Task::createTask("Elon", boost::gregorian::date{2000, 11, 11}, Task::Priority::FIRST, "label");
  TaskDTO dto(parent,id,false);
  EXPECT_CALL(service.operator*(), completeTask(id)).Times(2).WillOnce(Return(true)).WillOnce(Return(false));
  CompleteTaskCommand command(service,id);
  command.execute();
  ASSERT_EQ(command.getCompleteTaskCommandResult(), true);
  command.execute();
  ASSERT_EQ(command.getCompleteTaskCommandResult(), false);
}

bool operator ==(const CompleteTaskCommand first,const CompleteTaskCommand sec){
  return true;
}

TEST_F(CompleteTaskCommandTest, shouldAcceptVisitor) {
  auto service = std::make_shared<CoreAPIMock>();
  auto visitor = std::make_shared<VisitorMock>();
  TaskID id(1);
  CompleteTaskCommand command(service, id);
  EXPECT_CALL(visitor.operator*(), visitCompleteTaskCommand(command)).Times(1);
  ASSERT_NO_THROW(command.accept(visitor));
}
