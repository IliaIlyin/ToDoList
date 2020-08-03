//
// Created by Ilya on 8/4/2020.
//


#include<gtest/gtest.h>
#include<gmock/gmock.h>

#include "../Model/TaskID.h"
using testing::Eq;

class TaskIdTest : public ::testing::Test {

};
bool operator!=(const TaskID &id1, const TaskID &id2) {
  return !(id1 == id2);
}
TEST_F(TaskIdTest, shouldCreateTaskID) {
  TaskID id(1);
  ASSERT_EQ(1, id.getId());
}
TEST_F(TaskIdTest, testEqualityOperator) {
  TaskID id(8);
  TaskID id2(8);
  ASSERT_EQ(id, id2);
  TaskID id3(9);
  ASSERT_NE(id, id3);
}
TEST_F(TaskIdTest, testLessOperator) {
  TaskID id(8);
  TaskID id3(9);
  ASSERT_LT(id, id3);
}

