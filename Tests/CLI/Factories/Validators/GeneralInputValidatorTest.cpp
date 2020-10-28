//
// Created by ilya on 18.10.20.
//

#include <gtest/gtest.h>
#include "Factories/Validators/GeneralInputValidator.h"
class GeneralInputValidatorTest : public testing::Test {

};
TEST_F(GeneralInputValidatorTest, shouldValidateName) {
  std::string f = "";
  std::string f2 = "name";
  std::string f3 = "cancel command";
  ASSERT_EQ(GeneralInputValidator::validateName(f), GeneralInputValidator::InputToken::INCORRECT_INPUT_NAME);
  ASSERT_EQ(GeneralInputValidator::validateName(f2), GeneralInputValidator::InputToken::CORRECT);
  ASSERT_EQ(GeneralInputValidator::validateName(f3), GeneralInputValidator::InputToken::CANCEL_COMMAND);
}
TEST_F(GeneralInputValidatorTest, shouldValidateDate) {
  std::string f = "";
  std::string f2 = "2000/11/11";
  std::string f3 = "cancel command";
  ASSERT_EQ(GeneralInputValidator::validateDate(f), GeneralInputValidator::InputToken::INCORRECT_INPUT_DATE);
  ASSERT_EQ(GeneralInputValidator::validateDate(f2), GeneralInputValidator::InputToken::CORRECT);
  ASSERT_EQ(GeneralInputValidator::validateDate(f3), GeneralInputValidator::InputToken::CANCEL_COMMAND);
}
TEST_F(GeneralInputValidatorTest, shouldValidateLabel) {
  std::string f = "";
  std::string f2 = "2000/11/11";
  std::string f3 = "cancel command";
  ASSERT_EQ(GeneralInputValidator::validateLabel(f), GeneralInputValidator::InputToken::INCORRECT_INPUT_LABEL);
  ASSERT_EQ(GeneralInputValidator::validateLabel(f2), GeneralInputValidator::InputToken::CORRECT);
  ASSERT_EQ(GeneralInputValidator::validateLabel(f3), GeneralInputValidator::InputToken::CANCEL_COMMAND);
}
TEST_F(GeneralInputValidatorTest, shouldValidatePriority) {
  std::string f = "";
  std::string f2 = "FIRST";
  std::string f3 = "cancel command";
  std::string f4 = "SECOND";
  std::string f5 = "THIRD";
  std::string f6 = "NONE";
  ASSERT_EQ(GeneralInputValidator::validatePriority(f), GeneralInputValidator::InputToken::INCORRECT_INPUT_PRIORITY);
  ASSERT_EQ(GeneralInputValidator::validatePriority(f2), GeneralInputValidator::InputToken::CORRECT);
  ASSERT_EQ(GeneralInputValidator::validatePriority(f3), GeneralInputValidator::InputToken::CANCEL_COMMAND);
  ASSERT_EQ(GeneralInputValidator::validatePriority(f4), GeneralInputValidator::InputToken::CORRECT);
  ASSERT_EQ(GeneralInputValidator::validatePriority(f5), GeneralInputValidator::InputToken::CORRECT);
  ASSERT_EQ(GeneralInputValidator::validatePriority(f6), GeneralInputValidator::InputToken::CORRECT);
}
TEST_F(GeneralInputValidatorTest, shouldValidateId) {
  std::string f = "";
  std::string f2 = "1";
  std::string f3 = "cancel command";
  std::string f4 = "0";
  std::string f5 = "-1";
  std::string f6 = "1000";
  ASSERT_EQ(GeneralInputValidator::validateId(f), GeneralInputValidator::InputToken::INCORRECT_INPUT_ID);
  ASSERT_EQ(GeneralInputValidator::validateId(f2), GeneralInputValidator::InputToken::CORRECT);
  ASSERT_EQ(GeneralInputValidator::validateId(f3), GeneralInputValidator::InputToken::CANCEL_COMMAND);
  ASSERT_EQ(GeneralInputValidator::validateId(f4), GeneralInputValidator::InputToken::CORRECT);
  ASSERT_EQ(GeneralInputValidator::validateId(f5), GeneralInputValidator::InputToken::CORRECT);
  ASSERT_EQ(GeneralInputValidator::validateId(f6), GeneralInputValidator::InputToken::CORRECT);
}
TEST_F(GeneralInputValidatorTest, shouldValidateCancelCommand) {
  std::string f = "";
  std::string f3 = "cancel command";
  std::string f4 = "SECOND";
  ASSERT_EQ(GeneralInputValidator::isNotCancelled(f), GeneralInputValidator::InputToken::CORRECT);
  ASSERT_EQ(GeneralInputValidator::isNotCancelled(f3), GeneralInputValidator::InputToken::CANCEL_COMMAND);
  ASSERT_EQ(GeneralInputValidator::isNotCancelled(f4), GeneralInputValidator::InputToken::CORRECT);

}