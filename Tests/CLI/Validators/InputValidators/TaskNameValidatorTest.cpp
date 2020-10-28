//
// Created by ilya on 19.10.20.
//

#include <gtest/gtest.h>
#include "Validators/InputValidators/TaskNameValidator.h"
class TaskNameValidatorTest : public testing::Test {

};
TEST_F(TaskNameValidatorTest, shouldValidateInput) {
  TaskNameValidator validator;
  std::string f = "FDSFDS";
  std::string f2 = "2000/11/11";
  std::string f3 = "";
  std::string f4 = "cancel command";
  ASSERT_EQ(validator.validate(f), GeneralInputValidator::InputToken::CORRECT);
  ASSERT_EQ(validator.validate(f2), GeneralInputValidator::InputToken::CORRECT);
  ASSERT_EQ(validator.validate(f3), GeneralInputValidator::InputToken::INCORRECT_INPUT_NAME);
  ASSERT_EQ(validator.validate(f4), GeneralInputValidator::InputToken::CANCEL_COMMAND);

}