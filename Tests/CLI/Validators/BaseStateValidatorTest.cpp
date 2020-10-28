//
// Created by ilya on 19.10.20.
//

#include <gtest/gtest.h>
#include "Validators/BaseStateValidator.h"
class BaseStateValidatorTest : public testing::Test {

};
TEST_F(BaseStateValidatorTest, shouldValidateAddTask) {
  std::string str = "Add task";
  BaseStateValidator validator;
  ASSERT_EQ(validator.validate(str), GeneralCommandsValidator::CommandToken::ADD_TASK);
}
TEST_F(BaseStateValidatorTest, shouldValidateAddSubTask) {
  std::string str = "Add subTask";
  BaseStateValidator validator;
  ASSERT_EQ(validator.validate(str), GeneralCommandsValidator::CommandToken::ADD_SUBTASK);
}
TEST_F(BaseStateValidatorTest, shouldValidateGetTask) {
  std::string str = "get task";
  BaseStateValidator validator;
  ASSERT_EQ(validator.validate(str), GeneralCommandsValidator::CommandToken::GET_TASK);
}
TEST_F(BaseStateValidatorTest, shouldValidateCompleteTask) {
  std::string str = "complete task";
  BaseStateValidator validator;
  ASSERT_EQ(validator.validate(str), GeneralCommandsValidator::CommandToken::COMPLETE_TASK);
}
TEST_F(BaseStateValidatorTest, shouldValidateGetSubTask) {
  std::string str = "get subTasks";
  BaseStateValidator validator;
  ASSERT_EQ(validator.validate(str), GeneralCommandsValidator::CommandToken::GET_SUBTASK);
}
TEST_F(BaseStateValidatorTest, shouldValidateDeleteTask) {
  std::string str = "delete task";
  BaseStateValidator validator;
  ASSERT_EQ(validator.validate(str), GeneralCommandsValidator::CommandToken::DELETE_TASK);
}
TEST_F(BaseStateValidatorTest, shouldValidatePostponeTask) {
  std::string str = "postpone task";
  BaseStateValidator validator;
  ASSERT_EQ(validator.validate(str), GeneralCommandsValidator::CommandToken::POSTPONE_TASK);
}
TEST_F(BaseStateValidatorTest, shouldValidateSave) {
  std::string str = "save";
  BaseStateValidator validator;
  ASSERT_EQ(validator.validate(str), GeneralCommandsValidator::CommandToken::SAVE);
}
TEST_F(BaseStateValidatorTest, shouldValidateLoad) {
  std::string str = "load";
  BaseStateValidator validator;
  ASSERT_EQ(validator.validate(str), GeneralCommandsValidator::CommandToken::LOAD);
}
TEST_F(BaseStateValidatorTest, shouldValidateShowAllSortDate) {
  std::string str = "show all sort date";
  BaseStateValidator validator;
  ASSERT_EQ(validator.validate(str), GeneralCommandsValidator::CommandToken::SHOW_ALL_SORT_DATE);
}
TEST_F(BaseStateValidatorTest, shouldValidateShowAllSortLabel) {
  std::string str = "show all sort label";
  BaseStateValidator validator;
  ASSERT_EQ(validator.validate(str), GeneralCommandsValidator::CommandToken::SHOW_ALL_SORT_LABEL);
}
TEST_F(BaseStateValidatorTest, shouldValidateShowAllSortPriority) {
  std::string str = "show all sort priority";
  BaseStateValidator validator;
  ASSERT_EQ(validator.validate(str), GeneralCommandsValidator::CommandToken::SHOW_ALL_SORT_PRIORITY);
}

TEST_F(BaseStateValidatorTest, shouldValidateShowTodaySortPriority) {
  std::string str = "show today sort priority";
  BaseStateValidator validator;
  ASSERT_EQ(validator.validate(str), GeneralCommandsValidator::CommandToken::SHOW_TODAY_SORT_PRIORITY);
}

TEST_F(BaseStateValidatorTest, shouldValidateShowTodaySortLabel) {
  std::string str = "show today sort label";
  BaseStateValidator validator;
  ASSERT_EQ(validator.validate(str), GeneralCommandsValidator::CommandToken::SHOW_TODAY_SORT_LABEL);
}
TEST_F(BaseStateValidatorTest, shouldValidateShowDueDateSortDate) {
  std::string str = "show due date sort date";
  BaseStateValidator validator;
  ASSERT_EQ(validator.validate(str), GeneralCommandsValidator::CommandToken::SHOW_DUE_DATE_SORT_DATE);
}
TEST_F(BaseStateValidatorTest, shouldValidateShowDueDateSortPriority) {
  std::string str = "show due date sort priority";
  BaseStateValidator validator;
  ASSERT_EQ(validator.validate(str), GeneralCommandsValidator::CommandToken::SHOW_DUE_DATE_SORT_PRIORITY);
}
TEST_F(BaseStateValidatorTest, shouldValidateShowDueDateSortLabel) {
  std::string str = "show due date sort label";
  BaseStateValidator validator;
  ASSERT_EQ(validator.validate(str), GeneralCommandsValidator::CommandToken::SHOW_DUE_DATE_SORT_LABEL);
}