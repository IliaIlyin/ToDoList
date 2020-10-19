//
// Created by ilya on 18.10.20.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Visitors/Add/AddTaskCommandVisitor.h"
#include "Core/Mocks/CoreAPIMock.h"
using testing::Eq;
using testing::Return;
using testing::ReturnRef;
using testing::Mock;
class AddTaskCommandVisitorTest : public testing::Test {

};
TEST_F(AddTaskCommandVisitorTest, shouldVisitAddTask) {
  AddTaskCommandVisitor visitor;
  auto service = std::make_shared<CoreAPIMock>();
  Task task = Task::createTask("Elon", boost::gregorian::date{2000, 11, 11}, Task::Priority::FIRST, "label");
  EXPECT_CALL(service.operator*(), addTask(task)).Times(1).WillOnce(Return(true));
  AddTaskCommand command(service, task);
  ASSERT_NO_THROW(visitor.visitAddTaskCommand(command));
}