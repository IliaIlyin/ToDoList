//
// Created by ilya on 19.10.20.
//

#include <gtest/gtest.h>
#include "Validators/InputValidators/TaskIdValidator.h"
class TaskIdValidatorTest : public testing::Test {

};

TEST_F(TaskIdValidatorTest, shouldValidateInput) {
  TaskIdValidator validator;
  std::string f = "0";
  std::string f5 = "-11";
  std::string f6 = "100";
  std::string f2 = "ggfdgdsfg";
  std::string f3 = "";
  std::string f4 = "cancel command";
  ASSERT_EQ(validator.validate(f), GeneralInputValidator::InputToken::CORRECT);
  ASSERT_EQ(validator.validate(f2), GeneralInputValidator::InputToken::INCORRECT_INPUT_ID);
  ASSERT_EQ(validator.validate(f3), GeneralInputValidator::InputToken::INCORRECT_INPUT_ID);
  ASSERT_EQ(validator.validate(f4), GeneralInputValidator::InputToken::CANCEL_COMMAND);
  ASSERT_EQ(validator.validate(f5), GeneralInputValidator::InputToken::CORRECT);
  ASSERT_EQ(validator.validate(f6), GeneralInputValidator::InputToken::CORRECT);

}