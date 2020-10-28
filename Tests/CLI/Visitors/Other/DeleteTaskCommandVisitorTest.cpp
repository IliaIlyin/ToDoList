//
// Created by ilya on 18.10.20.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <CLI/Mocks/IOStreamMock.h>
#include "Visitors/Other/DeleteTaskCommandVisitor.h"
#include "Core/Mocks/CoreAPIMock.h"
using testing::Eq;
using testing::Return;
using testing::ReturnRef;
using testing::Mock;
class DeleteTaskCommandVisitorTest : public testing::Test {

};
TEST_F(DeleteTaskCommandVisitorTest, shouldVisitDeleteTask) {
  std::shared_ptr<IOStreamInterface> inputer = std::make_shared<IOStreamMock>();
  DeleteTaskCommandVisitor visitor(inputer);
  auto service = std::make_shared<CoreAPIMock>();
  TaskID id(1);
  EXPECT_CALL(service.operator*(), deleteTask(id)).Times(1).WillOnce(Return(true));
  DeleteTaskCommand command(service, id);
  ASSERT_NO_THROW(visitor.visitDeleteTaskCommand(command));
}