//
// Created by ilya on 18.10.20.
//


#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "Builders/Show/ShowAll/ShowAllByLabelCommandBuilder.h"
#include "Core/Mocks/CoreAPIMock.h"
using testing::Eq;
using testing::Return;
using testing::ReturnRef;
using testing::Mock;



class ShowAllByLabelCommandBuilderTest : public testing::Test {

};

TEST_F(ShowAllByLabelCommandBuilderTest, shouldCreateShowAllByLabelCommand) {
  auto service =  std::make_shared<CoreAPIMock>();
  ShowAllByLabelCommandBuilder builder;
  auto res = builder.buildCommand(service);
  ASSERT_NE(res.get(),nullptr);
}
