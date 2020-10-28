//
// Created by ilya on 19.10.20.
//
#include <gtest/gtest.h>
#include "Validators/InputValidators/PriorityValidator.h"
class TaskPriorityValidatorTest : public testing::Test {

};
TEST_F(TaskPriorityValidatorTest, shouldValidateInput) {
  PriorityValidator validator;
  std::string f = "";
  std::string f2 = "FIRST";
  std::string f3 = "cancel command";
  std::string f4 = "SECOND";
  std::string f5 = "THIRD";
  std::string f6 = "NONE";
  std::string f7 = "FOURTH";
  ASSERT_EQ(validator.validate(f), GeneralInputValidator::InputToken::INCORRECT_INPUT_PRIORITY);
  ASSERT_EQ(validator.validate(f2), GeneralInputValidator::InputToken::CORRECT);
  ASSERT_EQ(validator.validate(f3), GeneralInputValidator::InputToken::CANCEL_COMMAND);
  ASSERT_EQ(validator.validate(f4), GeneralInputValidator::InputToken::CORRECT);
  ASSERT_EQ(validator.validate(f5), GeneralInputValidator::InputToken::CORRECT);
  ASSERT_EQ(validator.validate(f6), GeneralInputValidator::InputToken::CORRECT);
  ASSERT_EQ(validator.validate(f7), GeneralInputValidator::InputToken::INCORRECT_INPUT_PRIORITY);
}