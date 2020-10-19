//
// Created by ilya on 18.10.20.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Visitors/Get/GetSubTaskCommandVisitor.h"
#include "Core/Mocks/CoreAPIMock.h"
#include "Contexts/Context.h"
using testing::Eq;
using testing::Return;
using testing::ReturnRef;
using testing::Mock;
class GetSubTaskCommandVisitorTest : public testing::Test {

};
TEST_F(GetSubTaskCommandVisitorTest, shouldVisitGetSubTask) {
  auto context = std::make_shared<Context>();
  GetSubTaskCommandVisitor visitor(context);
  auto service = std::make_shared<CoreAPIMock>();
  TaskID id(1);
  TaskID id2(0);
  std::vector<TaskDTO> vec;
  Task parent = Task::createTask("Elon", boost::gregorian::date{2000, 11, 11}, Task::Priority::FIRST, "label");
  TaskDTO dto(parent,id,false);
  vec.push_back(dto);
  EXPECT_CALL(service.operator*(), getSubTasks(id2)).Times(1).WillOnce(Return(vec));
  GetSubTaskCommand command(service, id2);
  ASSERT_NO_THROW(visitor.visitGetSubTaskCommand(command));
  ASSERT_EQ(vec,context->GetDtos());
  ASSERT_EQ(context->GetDto(),std::nullopt);
}