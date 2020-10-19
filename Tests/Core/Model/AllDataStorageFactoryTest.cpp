//
// Created by ilya on 10.10.20.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <Model/AllDataStorageFactory.h>

using testing::Eq;
using testing::Return;
using testing::ReturnRef;
using testing::Mock;
class AllDataStorageFactoryTest : public ::testing::Test {

};

TEST_F(AllDataStorageFactoryTest,shouldCreateAllDataStorage){
  AllDataStorageFactory factory;
  auto result = factory.create();
  ASSERT_NE(result.get(),nullptr);
}
