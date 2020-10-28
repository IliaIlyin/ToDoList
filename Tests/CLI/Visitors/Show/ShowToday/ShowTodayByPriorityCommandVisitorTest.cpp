//
// Created by ilya on 18.10.20.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Visitors/Show/ShowToday/ShowTodayByPriorityCommandVisitor.h"
#include "Core/Mocks/CoreAPIMock.h"
#include "Contexts/Context.h"
using testing::Eq;
using testing::Return;
using testing::ReturnRef;
using testing::Mock;
class ShowTodayByPriorityCommandVisitorTest : public testing::Test {

};
TEST_F(ShowTodayByPriorityCommandVisitorTest, shouldVisitShowTodayByPriority) {
  auto context = std::make_shared<Context>();
  ShowTodayByPriorityCommandVisitor visitor(context);
  auto service = std::make_shared<CoreAPIMock>();
  TaskID id(1);
  std::vector<TaskDTO> vec;
  Task parent = Task::createTask("Elon", boost::gregorian::date{2000, 11, 11}, Task::Priority::FIRST, "label");
  TaskDTO dto(parent, id, false);
  vec.push_back(dto);
  EXPECT_CALL(service.operator*(), showTodayByPriority()).Times(1).WillOnce(Return(vec));
  ShowTodayByPriorityCommand command(service);
  ASSERT_NO_THROW(visitor.visitShowTodayPriorityCommand(command));
  ASSERT_EQ(vec, context->GetDtos());
  ASSERT_EQ(context->GetDto(), std::nullopt);
}