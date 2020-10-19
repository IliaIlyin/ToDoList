//
// Created by ilya on 18.10.20.
//
#include <gtest/gtest.h>
#include "Contexts/Context.h"
class ContextTest : public testing::Test {

};
TEST_F(ContextTest, shouldConstructContext){
  Context context;
  ASSERT_EQ(context.GetDtos(),std::nullopt);
  ASSERT_EQ(context.GetDto(),std::nullopt);
}
TEST_F(ContextTest, shouldSetWithEmplace){
  Context context;
  std::vector<TaskDTO> vec;
  TaskID id(1);
  Task parent = Task::createTask("Elon", boost::gregorian::date{2000, 11, 11}, Task::Priority::FIRST, "label");
  TaskDTO dto(parent,id,false);
  vec.push_back(dto);
  context.SetDto(dto);
  ASSERT_EQ(context.GetDto(),dto);
  ASSERT_EQ(context.GetDtos(),std::nullopt);
  context.SetDtos(vec);
  ASSERT_EQ(context.GetDtos(),vec);
  ASSERT_EQ(context.GetDto(),std::nullopt);
  context.SetDto(dto);
  ASSERT_EQ(context.GetDto(),dto);
  ASSERT_EQ(context.GetDtos(),std::nullopt);
}

