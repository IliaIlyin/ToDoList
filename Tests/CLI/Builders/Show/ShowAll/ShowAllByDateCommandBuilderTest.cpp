//
// Created by ilya on 18.10.20.
//

//
// Created by ilya on 18.10.20.
//

//
// Created by ilya on 18.10.20.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "Builders/Show/ShowAll/ShowAllByDateCommandBuilder.h"
#include "Core/Mocks/CoreAPIMock.h"
using testing::Eq;
using testing::Return;
using testing::ReturnRef;
using testing::Mock;

class ShowAllByDateCommandBuilderTest : public testing::Test {

};

TEST_F(ShowAllByDateCommandBuilderTest, shouldCreateShowAllByDateCommand) {
  auto service = std::make_shared<CoreAPIMock>();
  ShowAllByDateCommandBuilder builder;
  auto res = builder.buildCommand(service);
  ASSERT_NE(res.get(), nullptr);
}
