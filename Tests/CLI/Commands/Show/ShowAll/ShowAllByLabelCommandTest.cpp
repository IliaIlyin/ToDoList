//
// Created by ilya on 18.10.20.
//

//
// Created by ilya on 18.10.20.
//


#include <gmock/gmock.h>
#include <string>
#include "Commands/Show/ShowAll/ShowAllByLabelCommand.h"
#include "Core/Mocks/CoreAPIMock.h"
#include "CLI/Mocks/VisitorMock.h"
using testing::Eq;
using testing::Return;
using testing::ReturnRef;
using testing::Mock;
class ShowAllByLabelCommandTest : public testing::Test {

};

TEST_F(ShowAllByLabelCommandTest, shouldExecuteCommand) {
  auto service = std::make_shared<CoreAPIMock>();
  TaskID id(1);
  std::vector<TaskDTO> vec;
  Task parent = Task::createTask("Elon", boost::gregorian::date{2000, 11, 11}, Task::Priority::FIRST, "label");
  TaskDTO dto(parent,id,false);
  vec.push_back(dto);
  EXPECT_CALL(service.operator*(), showAllByLabel()).Times(1).WillOnce(Return(vec));
  ShowAllByLabelCommand command(service);
  command.execute();
  ASSERT_EQ(command.getCommandResult(), vec);
}

bool operator ==(const ShowAllByLabelCommand first,const ShowAllByLabelCommand sec){
  return true;
}

TEST_F(ShowAllByLabelCommandTest, shouldAcceptVisitor) {
  auto service = std::make_shared<CoreAPIMock>();
  auto visitor = std::make_shared<VisitorMock>();
  ShowAllByLabelCommand command(service);
  EXPECT_CALL(visitor.operator*(), visitShowAllByLabelCommand(command)).Times(1);
  ASSERT_NO_THROW(command.accept(visitor));
}
