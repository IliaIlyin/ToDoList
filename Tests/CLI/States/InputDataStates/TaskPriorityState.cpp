//
// Created by ilya on 19.10.20.
//

#include "States/InputDataStates/TaskPriorityState.h"
#include "States/InputDataStates/ExitState.h"
#include "Validators/InputValidators/ExitValidator.h"
#include "Validators/InputValidators/PriorityValidator.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "CLI/Mocks/IOStreamMock.h"

using testing::Eq;
using testing::Return;
using testing::ReturnRef;
using testing::Mock;

class TaskPriorityStateTest : public ::testing::Test {

};

TEST_F(TaskPriorityStateTest, shouldReadCorrectLabel) {
  auto validator = std::make_shared<PriorityValidator>();
  auto inputer = std::make_shared<IOStreamMock>();
  EXPECT_CALL(inputer.operator*(),
              print("Input task priority or write cancel command to cancel command")).Times(1);
  EXPECT_CALL(inputer.operator*(),
              input()).Times(1).WillOnce(Return("FIRST"));
  TaskPriorityState base(validator);
  ASSERT_EQ(base.read(inputer), GeneralInputValidator::InputToken::CORRECT);
}
TEST_F(TaskPriorityStateTest, shouldReadIncorrectLabel) {
  auto validator = std::make_shared<PriorityValidator>();
  auto inputer = std::make_shared<IOStreamMock>();
  EXPECT_CALL(inputer.operator*(),
              print("Input task priority or write cancel command to cancel command")).Times(1);
  EXPECT_CALL(inputer.operator*(),
              input()).Times(1).WillOnce(Return("GDFGD"));
  TaskPriorityState base(validator);
  ASSERT_EQ(base.read(inputer), GeneralInputValidator::InputToken::INCORRECT_INPUT_PRIORITY);
}
TEST_F(TaskPriorityStateTest, shouldReadCancelCommand) {
  auto validator = std::make_shared<PriorityValidator>();
  auto inputer = std::make_shared<IOStreamMock>();
  EXPECT_CALL(inputer.operator*(),
              print("Input task priority or write cancel command to cancel command")).Times(1);
  EXPECT_CALL(inputer.operator*(),
              input()).Times(1).WillOnce(Return("cancel command"));
  TaskPriorityState base(validator);
  ASSERT_EQ(base.read(inputer), GeneralInputValidator::InputToken::CANCEL_COMMAND);
}
TEST_F(TaskPriorityStateTest, shouldChangeState) {
  auto validator = std::make_shared<PriorityValidator>();
  TaskPriorityState base(validator);
  ASSERT_NE(base.changeState().get(), nullptr);
}
TEST_F(TaskPriorityStateTest, shouldFillContext) {
  auto validator = std::make_shared<PriorityValidator>();
  InputContext context;
  auto inputer = std::make_shared<IOStreamMock>();
  EXPECT_CALL(inputer.operator*(),
              print("Input task priority or write cancel command to cancel command")).Times(1);
  EXPECT_CALL(inputer.operator*(),
              input()).Times(1).WillOnce(Return("FIRST"));
  TaskPriorityState base(validator);
  base.read(inputer);
  ASSERT_EQ(base.fillContext(context).getPriority(), Task::Priority::FIRST);
}