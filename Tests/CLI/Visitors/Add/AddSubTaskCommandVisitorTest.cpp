//
// Created by ilya on 18.10.20.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <CLI/Mocks/IOStreamMock.h>
#include "Visitors/Add/AddSubTaskCommandVisitor.h"
#include "Core/Mocks/CoreAPIMock.h"
using testing::Eq;
using testing::Return;
using testing::ReturnRef;
using testing::Mock;
class AddSubTaskCommandVisitorTest : public testing::Test {

};
TEST_F(AddSubTaskCommandVisitorTest, shouldVisitAddSubTask) {
  std::shared_ptr<IOStreamInterface> inputer = std::make_shared<IOStreamMock>();
  AddSubTaskCommandVisitor visitor(inputer);
  auto service = std::make_shared<CoreAPIMock>();
  TaskID id(0);
  Task task = Task::createTask("Elon", boost::gregorian::date{2000, 11, 11}, Task::Priority::FIRST, "label");
  EXPECT_CALL(service.operator*(), addSubTaskToParent(id, task)).Times(1).WillOnce(Return(true));
  AddSubTaskCommand command(service, id, task);
  ASSERT_NO_THROW(visitor.visitAddSubTaskCommand(command));
}