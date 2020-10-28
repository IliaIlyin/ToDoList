//
// Created by ilya on 19.10.20.
//

#include "States/InputDataStates/TaskIdState.h"
#include "States/InputDataStates/ExitState.h"
#include "Validators/InputValidators/ExitValidator.h"
#include "Validators/InputValidators/TaskIdValidator.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "CLI/Mocks/IOStreamMock.h"

using testing::Eq;
using testing::Return;
using testing::ReturnRef;
using testing::Mock;

class TaskIdStateTest : public ::testing::Test {

};

TEST_F(TaskIdStateTest, shouldReadCorrectId) {
  auto validator = std::make_shared<TaskIdValidator>();
  auto inputer = std::make_shared<IOStreamMock>();
  EXPECT_CALL(inputer.operator*(),
              print("Input task id or write cancel command to cancel command")).Times(1);
  EXPECT_CALL(inputer.operator*(),
              input()).Times(1).WillOnce(Return("18"));
  TaskIdState<ExitState, ExitValidator> base(validator);
  ASSERT_EQ(base.read(inputer), GeneralInputValidator::InputToken::CORRECT);
}
TEST_F(TaskIdStateTest, shouldReadIncorrectId) {
  auto validator = std::make_shared<TaskIdValidator>();
  auto inputer = std::make_shared<IOStreamMock>();
  EXPECT_CALL(inputer.operator*(),
              print("Input task id or write cancel command to cancel command")).Times(1);
  EXPECT_CALL(inputer.operator*(),
              input()).Times(1).WillOnce(Return("fadsasfd"));
  TaskIdState<ExitState, ExitValidator> base(validator);
  ASSERT_EQ(base.read(inputer), GeneralInputValidator::InputToken::INCORRECT_INPUT_ID);
}
TEST_F(TaskIdStateTest, shouldReadCancelCommand) {
  auto validator = std::make_shared<TaskIdValidator>();
  auto inputer = std::make_shared<IOStreamMock>();
  EXPECT_CALL(inputer.operator*(),
              print("Input task id or write cancel command to cancel command")).Times(1);
  EXPECT_CALL(inputer.operator*(),
              input()).Times(1).WillOnce(Return("cancel command"));
  TaskIdState<ExitState, ExitValidator> base(validator);
  ASSERT_EQ(base.read(inputer), GeneralInputValidator::InputToken::CANCEL_COMMAND);
}
TEST_F(TaskIdStateTest, shouldChangeState) {
  auto validator = std::make_shared<TaskIdValidator>();
  TaskIdState<ExitState, ExitValidator> base(validator);
  ASSERT_NE(base.changeState().get(), nullptr);
}
TEST_F(TaskIdStateTest, shouldFillContext) {
  auto validator = std::make_shared<TaskIdValidator>();
  InputContext context;
  auto inputer = std::make_shared<IOStreamMock>();
  EXPECT_CALL(inputer.operator*(),
              print("Input task id or write cancel command to cancel command")).Times(1);
  EXPECT_CALL(inputer.operator*(),
              input()).Times(1).WillOnce(Return("19"));
  TaskIdState<ExitState, ExitValidator> base(validator);
  base.read(inputer);
  TaskID id(19);
  ASSERT_EQ(base.fillContext(context).getId(), id);
}