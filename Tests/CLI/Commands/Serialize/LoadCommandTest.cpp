//
// Created by ilya on 18.10.20.
//

#include <gmock/gmock.h>
#include <string>
#include "Commands/Serialize/LoadCommand.h"
#include "Core/Mocks/CoreAPIMock.h"
#include "CLI/Mocks/VisitorMock.h"
using testing::Eq;
using testing::Return;
using testing::ReturnRef;
using testing::Mock;
class LoadCommandTest : public testing::Test {

};

TEST_F(LoadCommandTest, shouldExecuteCommand) {
  auto service = std::make_shared<CoreAPIMock>();
  std::string fileName;
  EXPECT_CALL(service.operator*(), load(fileName)).Times(2).WillOnce(Return(true)).WillOnce(Return(false));
  LoadCommand command(service, fileName);
  command.execute();
  ASSERT_EQ(command.getLoadResult(), true);
  command.execute();
  ASSERT_EQ(command.getLoadResult(), false);
}

bool operator==(const LoadCommand first, const LoadCommand sec) {
  return true;
}

TEST_F(LoadCommandTest, shouldAcceptVisitor) {
  std::string fileName;
  auto service = std::make_shared<CoreAPIMock>();
  auto visitor = std::make_shared<VisitorMock>();
  LoadCommand command(service, fileName);
  EXPECT_CALL(visitor.operator*(), visitLoadCommand(command)).Times(1);
  ASSERT_NO_THROW(command.accept(visitor));
}
