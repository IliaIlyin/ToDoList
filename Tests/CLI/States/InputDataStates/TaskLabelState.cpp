//
// Created by ilya on 19.10.20.
//

#include "States/InputDataStates/TaskLabelState.h"
#include "States/InputDataStates/ExitState.h"
#include "Validators/InputValidators/ExitValidator.h"
#include "Validators/InputValidators/LabelValidator.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "CLI/Mocks/IOStreamMock.h"

using testing::Eq;
using testing::Return;
using testing::ReturnRef;
using testing::Mock;

class TaskLabelStateTest : public ::testing::Test {

};

TEST_F(TaskLabelStateTest, shouldReadCorrectLabel) {
  auto validator = std::make_shared<LabelValidator>();
  auto inputer = std::make_shared<IOStreamMock>();
  EXPECT_CALL(inputer.operator*(),
              print("TestLabel")).Times(1);
  EXPECT_CALL(inputer.operator*(),
              input()).Times(1).WillOnce(Return("label"));
  TaskLabelState base(validator, "TestLabel");
  ASSERT_EQ(base.read(inputer), GeneralInputValidator::InputToken::CORRECT);
}
TEST_F(TaskLabelStateTest, shouldReadIncorrectLabel) {
  auto validator = std::make_shared<LabelValidator>();
  auto inputer = std::make_shared<IOStreamMock>();
  EXPECT_CALL(inputer.operator*(),
              print("TestLabel")).Times(1);
  EXPECT_CALL(inputer.operator*(),
              input()).Times(1).WillOnce(Return(""));
  TaskLabelState base(validator, "TestLabel");
  ASSERT_EQ(base.read(inputer), GeneralInputValidator::InputToken::INCORRECT_INPUT_LABEL);
}
TEST_F(TaskLabelStateTest, shouldReadCancelCommand) {
  auto validator = std::make_shared<LabelValidator>();
  auto inputer = std::make_shared<IOStreamMock>();
  EXPECT_CALL(inputer.operator*(),
              print("TestLabel")).Times(1);
  EXPECT_CALL(inputer.operator*(),
              input()).Times(1).WillOnce(Return("cancel command"));
  TaskLabelState base(validator, "TestLabel");
  ASSERT_EQ(base.read(inputer), GeneralInputValidator::InputToken::CANCEL_COMMAND);
}
TEST_F(TaskLabelStateTest, shouldChangeState) {
  auto validator = std::make_shared<LabelValidator>();
  TaskLabelState base(validator, "TestLabel");
  ASSERT_NE(base.changeState().get(), nullptr);
}
TEST_F(TaskLabelStateTest, shouldFillContext) {
  auto validator = std::make_shared<LabelValidator>();
  InputContext context;
  auto inputer = std::make_shared<IOStreamMock>();
  EXPECT_CALL(inputer.operator*(),
              print("TestLabel")).Times(1);
  EXPECT_CALL(inputer.operator*(),
              input()).Times(1).WillOnce(Return("label"));
  TaskLabelState base(validator, "TestLabel");
  base.read(inputer);
  ASSERT_EQ(base.fillContext(context).getLabel(), "label");
}