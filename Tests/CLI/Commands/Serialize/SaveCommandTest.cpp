//
// Created by ilya on 18.10.20.
//


#include <gmock/gmock.h>
#include <string>
#include "Commands/Serialize/SaveCommand.h"
#include "Core/Mocks/CoreAPIMock.h"
#include "CLI/Mocks/VisitorMock.h"
using testing::Eq;
using testing::Return;
using testing::ReturnRef;
using testing::Mock;
class SaveCommandTest : public testing::Test {

};

TEST_F(SaveCommandTest, shouldExecuteCommand) {
  auto service = std::make_shared<CoreAPIMock>();
  std::string fileName;
  EXPECT_CALL(service.operator*(), save(fileName)).Times(2).WillOnce(Return(true)).WillOnce(Return(false));
  SaveCommand command(service,fileName);
  command.execute();
  ASSERT_EQ(command.getSaveResult(), true);
  command.execute();
  ASSERT_EQ(command.getSaveResult(), false);
}

bool operator ==(const SaveCommand first,const SaveCommand sec){
  return true;
}

TEST_F(SaveCommandTest, shouldAcceptVisitor) {
  std::string fileName;
  auto service = std::make_shared<CoreAPIMock>();
  auto visitor = std::make_shared<VisitorMock>();
  SaveCommand command(service, fileName);
  EXPECT_CALL(visitor.operator*(), visitSaveCommand(command)).Times(1);
  ASSERT_NO_THROW(command.accept(visitor));
}
