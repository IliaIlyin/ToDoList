//
// Created by Ilya on 7/26/2020.
//
#include<gtest/gtest.h>
#include<gmock/gmock.h>

#include "../Model/IdGenerator.h"
#include "../Model/TaskID.h"

using testing::Eq;

    class IdGeneratorTest : public ::testing::Test {

    };


TEST_F(IdGeneratorTest,shouldReturn3){
    IdGenerator idGenerator(3);
    TaskID id =idGenerator.generateId();
    ASSERT_EQ(3,id.getId());
    ASSERT_EQ(4,idGenerator.generateId().getId());
}

TEST_F(IdGeneratorTest,shouldReturn0){
    IdGenerator idGenerator;
    TaskID id = idGenerator.generateId();
    ASSERT_EQ(0,id.getId());
    TaskID id2 = idGenerator.generateId();
    ASSERT_EQ(1,id2.getId());
}
