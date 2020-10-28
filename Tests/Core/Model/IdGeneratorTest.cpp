//
// Created by Ilya on 7/26/2020.
//

#include "gtest/gtest.h"
#include "Model/IdGenerator.h"
#include "API/TaskID.h"
class IdGeneratorTest : public ::testing::Test {

};

TEST_F(IdGeneratorTest, shouldReturn3) {
  IdGenerator idGenerator(3);
  TaskID id = idGenerator.generateId();
  TaskID id2(3);
  TaskID id3(4);
  ASSERT_EQ(id2, id);
  ASSERT_EQ(3, id.getId());
  ASSERT_EQ(id3, idGenerator.generateId());
}

TEST_F(IdGeneratorTest, shouldReturn0) {
  IdGenerator idGenerator;
  TaskID id = idGenerator.generateId();
  ASSERT_EQ(0, id.getId());
  TaskID id2 = idGenerator.generateId();
  ASSERT_EQ(1, id2.getId());
}
