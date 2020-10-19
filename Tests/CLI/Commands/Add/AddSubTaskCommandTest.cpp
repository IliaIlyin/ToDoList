//
// Created by ilya on 18.10.20.
//

//
// Created by ilya on 18.10.20.
//

#include <gmock/gmock.h>
#include <string>
#include "Commands/Add/AddSubTaskCommand.h"
#include "Core/Mocks/CoreAPIMock.h"
#include "CLI/Mocks/VisitorMock.h"
using testing::Eq;
using testing::Return;
using testing::ReturnRef;
using testing::Mock;
class AddSubTaskCommandTest : public testing::Test {

};

TEST_F(AddSubTaskCommandTest, shouldExecuteCommand) {
  auto service = std::make_shared<CoreAPIMock>();
  TaskID id(1);
  Task parent = Task::createTask("Elon", boost::gregorian::date{2000, 11, 11}, Task::Priority::FIRST, "label");
  EXPECT_CALL(service.operator*(), addSubTaskToParent(id,parent)).Times(2).WillOnce(Return(true)).WillOnce(Return(false));
  AddSubTaskCommand command(service,id, parent);
  command.execute();
  ASSERT_EQ(command.getAddSubTaskResult(), true);
  command.execute();
  ASSERT_EQ(command.getAddSubTaskResult(), false);
}

bool operator ==(const AddSubTaskCommand first,const AddSubTaskCommand sec){
  return true;
}

TEST_F(AddSubTaskCommandTest, shouldAcceptVisitor) {
  auto service = std::make_shared<CoreAPIMock>();
  auto visitor = std::make_shared<VisitorMock>();
  TaskID id(1);
  Task parent = Task::createTask("Elon", boost::gregorian::date{2000, 11, 11}, Task::Priority::FIRST, "label");
  AddSubTaskCommand command(service, id, parent);
  EXPECT_CALL(visitor.operator*(), visitAddSubTaskCommand(command)).Times(1);
  ASSERT_NO_THROW(command.accept(visitor));
}
