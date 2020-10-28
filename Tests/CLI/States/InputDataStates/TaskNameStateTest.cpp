//
// Created by ilya on 19.10.20.
//

#include "States/InputDataStates/TaskNameState.h"
#include "States/InputDataStates/ExitState.h"
#include "Validators/InputValidators/ExitValidator.h"
#include "Validators/InputValidators/TaskNameValidator.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "CLI/Mocks/IOStreamMock.h"

using testing::Eq;
using testing::Return;
using testing::ReturnRef;
using testing::Mock;

class TaskNameStateTest : public ::testing::Test {

};

TEST_F(TaskNameStateTest, shouldReadCorrectLabel) {
  auto validator = std::make_shared<TaskNameValidator>();
  auto inputer = std::make_shared<IOStreamMock>();
  EXPECT_CALL(inputer.operator*(),
              print("Input task name or write cancel command to cancel command")).Times(1);
  EXPECT_CALL(inputer.operator*(),
              input()).Times(1).WillOnce(Return("name"));
  TaskNameState base(validator);
  ASSERT_EQ(base.read(inputer), GeneralInputValidator::InputToken::CORRECT);
}
TEST_F(TaskNameStateTest, shouldReadIncorrectLabel) {
  auto validator = std::make_shared<TaskNameValidator>();
  auto inputer = std::make_shared<IOStreamMock>();
  EXPECT_CALL(inputer.operator*(),
              print("Input task name or write cancel command to cancel command")).Times(1);
  EXPECT_CALL(inputer.operator*(),
              input()).Times(1).WillOnce(Return(""));
  TaskNameState base(validator);
  ASSERT_EQ(base.read(inputer), GeneralInputValidator::InputToken::INCORRECT_INPUT_NAME);
}
TEST_F(TaskNameStateTest, shouldReadCancelCommand) {
  auto validator = std::make_shared<TaskNameValidator>();
  auto inputer = std::make_shared<IOStreamMock>();
  EXPECT_CALL(inputer.operator*(),
              print("Input task name or write cancel command to cancel command")).Times(1);
  EXPECT_CALL(inputer.operator*(),
              input()).Times(1).WillOnce(Return("cancel command"));
  TaskNameState base(validator);
  ASSERT_EQ(base.read(inputer), GeneralInputValidator::InputToken::CANCEL_COMMAND);
}
TEST_F(TaskNameStateTest, shouldChangeState) {
  auto validator = std::make_shared<TaskNameValidator>();
  TaskNameState base(validator);
  ASSERT_NE(base.changeState().get(), nullptr);
}
TEST_F(TaskNameStateTest, shouldFillContext) {
  auto validator = std::make_shared<TaskNameValidator>();
  InputContext context;
  auto inputer = std::make_shared<IOStreamMock>();
  EXPECT_CALL(inputer.operator*(),
              print("Input task name or write cancel command to cancel command")).Times(1);
  EXPECT_CALL(inputer.operator*(),
              input()).Times(1).WillOnce(Return("name"));
  TaskNameState base(validator);
  base.read(inputer);
  ASSERT_EQ(base.fillContext(context).getName(), "name");
}