//
// Created by ilya on 18.10.20.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <CLI/Mocks/IOStreamMock.h>
#include "Visitors/Serialize//LoadCommandVisitor.h"
#include "Core/Mocks/CoreAPIMock.h"
using testing::Eq;
using testing::Return;
using testing::ReturnRef;
using testing::Mock;
class LoadCommandVisitorTest : public testing::Test {

};
TEST_F(LoadCommandVisitorTest, shouldVisitLoad) {
  std::shared_ptr<IOStreamInterface> inputer = std::make_shared<IOStreamMock>();
  LoadCommandVisitor visitor(inputer);
  auto service = std::make_shared<CoreAPIMock>();
  std::string fileName = "lol";
  EXPECT_CALL(service.operator*(), load(fileName)).Times(1).WillOnce(Return(true));
  LoadCommand command(service, fileName);
  ASSERT_NO_THROW(visitor.visitLoadCommand(command));
}