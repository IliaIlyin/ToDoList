//
// Created by ilya on 19.10.20.
//

#include "States/InputDataStates/TaskDateState.h"
#include "States/InputDataStates/ExitState.h"
#include "Validators/InputValidators/ExitValidator.h"
#include "Validators/InputValidators/DateValidator.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "CLI/Mocks/IOStreamMock.h"

using testing::Eq;
using testing::Return;
using testing::ReturnRef;
using testing::Mock;

class TaskDateStateTest : public ::testing::Test {

};

TEST_F(TaskDateStateTest, shouldReadCorrectDate) {
  auto validator = std::make_shared<DateValidator>();
  auto inputer = std::make_shared<IOStreamMock>();
  EXPECT_CALL(inputer.operator*(),
              print("Input task date or write cancel command to cancel command")).Times(1);
  EXPECT_CALL(inputer.operator*(),
              input()).Times(1).WillOnce(Return("2000/11/11"));
  TaskDateState<ExitState, ExitValidator> base(validator);
  ASSERT_EQ(base.read(inputer), GeneralInputValidator::InputToken::CORRECT);
}
TEST_F(TaskDateStateTest, shouldReadIncorrectDate) {
  auto validator = std::make_shared<DateValidator>();
  auto inputer = std::make_shared<IOStreamMock>();
  EXPECT_CALL(inputer.operator*(),
              print("Input task date or write cancel command to cancel command")).Times(1);
  EXPECT_CALL(inputer.operator*(),
              input()).Times(1).WillOnce(Return("fadsasfd"));
  TaskDateState<ExitState, ExitValidator> base(validator);
  ASSERT_EQ(base.read(inputer), GeneralInputValidator::InputToken::INCORRECT_INPUT_DATE);
}
TEST_F(TaskDateStateTest, shouldReadCancelCommand) {
  auto validator = std::make_shared<DateValidator>();
  auto inputer = std::make_shared<IOStreamMock>();
  EXPECT_CALL(inputer.operator*(),
              print("Input task date or write cancel command to cancel command")).Times(1);
  EXPECT_CALL(inputer.operator*(),
              input()).Times(1).WillOnce(Return("cancel command"));
  TaskDateState<ExitState, ExitValidator> base(validator);
  ASSERT_EQ(base.read(inputer), GeneralInputValidator::InputToken::CANCEL_COMMAND);
}
TEST_F(TaskDateStateTest, shouldChangeState) {
  auto validator = std::make_shared<DateValidator>();
  TaskDateState<ExitState, ExitValidator> base(validator);
  ASSERT_NE(base.changeState().get(), nullptr);
}
TEST_F(TaskDateStateTest, shouldFillContext) {
  auto validator = std::make_shared<DateValidator>();
  InputContext context;
  auto inputer = std::make_shared<IOStreamMock>();
  EXPECT_CALL(inputer.operator*(),
              print("Input task date or write cancel command to cancel command")).Times(1);
  EXPECT_CALL(inputer.operator*(),
              input()).Times(1).WillOnce(Return("2000/11/11"));
  TaskDateState<ExitState, ExitValidator> base(validator);
  base.read(inputer);
  auto date = boost::gregorian::date{2000, 11, 11};
  ASSERT_EQ(base.fillContext(context).getDate(), date);
}