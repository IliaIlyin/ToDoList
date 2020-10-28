//
// Created by ilya on 18.10.20.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <CLI/Mocks/IOStreamMock.h>
#include "Visitors/Other/PostponeTaskCommandVisitor.h"
#include "Core/Mocks/CoreAPIMock.h"
using testing::Eq;
using testing::Return;
using testing::ReturnRef;
using testing::Mock;
class PostponeTaskCommandVisitorTest : public testing::Test {

};
TEST_F(PostponeTaskCommandVisitorTest, shouldVisitPostponeTask) {
  std::shared_ptr<IOStreamInterface> inputer = std::make_shared<IOStreamMock>();
  PostponeTaskCommandVisitor visitor(inputer);
  boost::gregorian::date date{2000, 11, 11};
  auto service = std::make_shared<CoreAPIMock>();
  TaskID id(1);
  EXPECT_CALL(service.operator*(), postponeTask(id, date)).Times(1).WillOnce(Return(true));
  PostponeTaskCommand command(service, id, date);
  ASSERT_NO_THROW(visitor.visitPostponeTaskCommand(command));
}