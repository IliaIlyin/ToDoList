//
// Created by ilya on 18.10.20.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <CLI/Mocks/IOStreamMock.h>
#include "Visitors/Other/CompleteTaskCommandVisitor.h"
#include "Core/Mocks/CoreAPIMock.h"
using testing::Eq;
using testing::Return;
using testing::ReturnRef;
using testing::Mock;
class CompleteTaskCommandVisitorTest : public testing::Test {

};
TEST_F(CompleteTaskCommandVisitorTest, shouldVisitCompleteTask) {
  std::shared_ptr<IOStreamInterface> inputer = std::make_shared<IOStreamMock>();
  CompleteTaskCommandVisitor visitor(inputer);
  auto service = std::make_shared<CoreAPIMock>();
  TaskID id(1);
  EXPECT_CALL(service.operator*(), completeTask(id)).Times(1).WillOnce(Return(true));
  CompleteTaskCommand command(service, id);
  ASSERT_NO_THROW(visitor.visitCompleteTaskCommand(command));
}