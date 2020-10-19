//
// Created by ilya on 18.10.20.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Visitors/Get/GetTaskCommandVisitor.h"
#include "Core/Mocks/CoreAPIMock.h"
#include "Contexts/Context.h"
using testing::Eq;
using testing::Return;
using testing::ReturnRef;
using testing::Mock;
class GetTaskCommandVisitorTest : public testing::Test {

};
TEST_F(GetTaskCommandVisitorTest, shouldVisitGetTask) {
  auto context = std::make_shared<Context>();
  GetTaskCommandVisitor visitor(context);
  auto service = std::make_shared<CoreAPIMock>();
  TaskID id(1);
  Task parent = Task::createTask("Elon", boost::gregorian::date{2000, 11, 11}, Task::Priority::FIRST, "label");
  TaskDTO dto(parent,id,false);
  EXPECT_CALL(service.operator*(), getTask(id)).Times(1).WillOnce(Return(dto));
  GetTaskCommand command(service, id);
  ASSERT_NO_THROW(visitor.visitGetTaskCommand(command));
  ASSERT_EQ(std::nullopt,context->GetDtos());
  ASSERT_EQ(context->GetDto(),dto);
}