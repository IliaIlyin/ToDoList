//
// Created by ilya on 19.10.20.
//

#include "States/InputDataStates/ExitState.h"
#include "Validators/InputValidators/ExitValidator.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "CLI/Mocks/IOStreamMock.h"

using testing::Eq;
using testing::Return;
using testing::ReturnRef;
using testing::Mock;

class ExitStateTest : public ::testing::Test {

};

TEST_F(ExitStateTest, shouldRead) {
  auto inputer = std::make_shared<IOStreamMock>();
  EXPECT_CALL(inputer.operator*(), print("Finishing")).Times(1);
  auto validator = std::make_shared<ExitValidator>();
  ExitState base(validator);
  ASSERT_EQ(base.read(inputer), GeneralInputValidator::InputToken::SUCCESS);
}
TEST_F(ExitStateTest, shouldChangeState) {
  auto validator = std::make_shared<ExitValidator>();
  ExitState base(validator);
  ASSERT_EQ(base.changeState().get(), nullptr);
}
TEST_F(ExitStateTest, shouldFillContext) {
  auto validator = std::make_shared<ExitValidator>();
  InputContext context;
  ExitState base(validator);
  ASSERT_EQ(base.fillContext(context), context);
}