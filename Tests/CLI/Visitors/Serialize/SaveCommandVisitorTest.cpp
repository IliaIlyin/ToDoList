//
// Created by ilya on 18.10.20.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Visitors/Serialize//SaveCommandVisitor.h"
#include "Core/Mocks/CoreAPIMock.h"
using testing::Eq;
using testing::Return;
using testing::ReturnRef;
using testing::Mock;
class SaveCommandVisitorTest : public testing::Test {

};
TEST_F(SaveCommandVisitorTest, shouldVisitSave) {
  SaveCommandVisitor visitor;
  auto service = std::make_shared<CoreAPIMock>();
  std::string fileName = "lol";
  EXPECT_CALL(service.operator*(), save(fileName)).Times(1).WillOnce(Return(true));
  SaveCommand command(service, fileName);
  ASSERT_NO_THROW(visitor.visitSaveCommand(command));
}