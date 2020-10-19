//
// Created by ilya on 18.10.20.
//

#include <gtest/gtest.h>
#include "Factories/Validators/GeneralCommandsValidator.h"
class GeneralCommandsValidatorTest : public testing::Test {

};
TEST_F(GeneralCommandsValidatorTest, shouldValidateShowAll) {
  std::string f = "show all sort priority";
  std::string f2 = "show all sort label";
  std::string f3 = "show all sort date";
  std::string f4 = "kek";
  ASSERT_EQ(GeneralCommandsValidator::validateShowAll(f),
            GeneralCommandsValidator::CommandToken::SHOW_ALL_SORT_PRIORITY);
  ASSERT_EQ(GeneralCommandsValidator::validateShowAll(f2),
            GeneralCommandsValidator::CommandToken::SHOW_ALL_SORT_LABEL);
  ASSERT_EQ(GeneralCommandsValidator::validateShowAll(f3),
            GeneralCommandsValidator::CommandToken::SHOW_ALL_SORT_DATE);
  ASSERT_EQ(GeneralCommandsValidator::validateShowAll(f4),
            GeneralCommandsValidator::CommandToken::INCORRECT_COMMAND);
}

TEST_F(GeneralCommandsValidatorTest, shouldValidateShowToday) {
  std::string f = "show today sort label";
  std::string f2 = "show today sort priority";
  std::string f3 = "kek";
  ASSERT_EQ(GeneralCommandsValidator::validateShowToday(f2),
            GeneralCommandsValidator::CommandToken::SHOW_TODAY_SORT_PRIORITY);
  ASSERT_EQ(GeneralCommandsValidator::validateShowToday(f),
            GeneralCommandsValidator::CommandToken::SHOW_TODAY_SORT_LABEL);
  ASSERT_EQ(GeneralCommandsValidator::validateShowToday(f3),
            GeneralCommandsValidator::CommandToken::INCORRECT_COMMAND);
}

TEST_F(GeneralCommandsValidatorTest, shouldValidateShowDueDate) {
  std::string f = "show due date sort date";
  std::string f2 = "show due date sort label";
  std::string f3 = "show due date sort priority";
  std::string f4 = "kek";
  ASSERT_EQ(GeneralCommandsValidator::validateShowDueDate(f3),
            GeneralCommandsValidator::CommandToken::SHOW_DUE_DATE_SORT_PRIORITY);
  ASSERT_EQ(GeneralCommandsValidator::validateShowDueDate(f2),
            GeneralCommandsValidator::CommandToken::SHOW_DUE_DATE_SORT_LABEL);
  ASSERT_EQ(GeneralCommandsValidator::validateShowDueDate(f),
            GeneralCommandsValidator::CommandToken::SHOW_DUE_DATE_SORT_DATE);
  ASSERT_EQ(GeneralCommandsValidator::validateShowDueDate(f4),
            GeneralCommandsValidator::CommandToken::INCORRECT_COMMAND);
}
TEST_F(GeneralCommandsValidatorTest, shouldValidateAddTask) {
  std::string f = "Add task";
  std::string f2 = "kek";
  ASSERT_EQ(GeneralCommandsValidator::validateAddTask(f),
            GeneralCommandsValidator::CommandToken::ADD_TASK);
  ASSERT_EQ(GeneralCommandsValidator::validateAddTask(f2),
            GeneralCommandsValidator::CommandToken::INCORRECT_COMMAND);
}
TEST_F(GeneralCommandsValidatorTest, shouldValidateAddSubTask) {
  std::string f = "Add subTask";
  std::string f2 = "kek";
  ASSERT_EQ(GeneralCommandsValidator::validateAddSubTask(f),
            GeneralCommandsValidator::CommandToken::ADD_SUBTASK);
  ASSERT_EQ(GeneralCommandsValidator::validateAddSubTask(f2),
            GeneralCommandsValidator::CommandToken::INCORRECT_COMMAND);
}
TEST_F(GeneralCommandsValidatorTest, shouldValidateGetask) {
  std::string f = "get task";
  std::string f2 = "kek";
  ASSERT_EQ(GeneralCommandsValidator::validateGetTask(f),
            GeneralCommandsValidator::CommandToken::GET_TASK);
  ASSERT_EQ(GeneralCommandsValidator::validateGetTask(f2),
            GeneralCommandsValidator::CommandToken::INCORRECT_COMMAND);
}
TEST_F(GeneralCommandsValidatorTest, shouldValidateGetSubTasks) {
  std::string f = "get subTasks";
  std::string f2 = "kek";
  ASSERT_EQ(GeneralCommandsValidator::validateGetSubTasks(f),
            GeneralCommandsValidator::CommandToken::GET_SUBTASK);
  ASSERT_EQ(GeneralCommandsValidator::validateGetSubTasks(f2),
            GeneralCommandsValidator::CommandToken::INCORRECT_COMMAND);
}
TEST_F(GeneralCommandsValidatorTest, shouldValidatePostponeTask) {
  std::string f = "postpone task";
  std::string f2 = "kek";
  ASSERT_EQ(GeneralCommandsValidator::validatePostponeTask(f),
            GeneralCommandsValidator::CommandToken::POSTPONE_TASK);
  ASSERT_EQ(GeneralCommandsValidator::validatePostponeTask(f2),
            GeneralCommandsValidator::CommandToken::INCORRECT_COMMAND);
}
TEST_F(GeneralCommandsValidatorTest, shouldValidateCompleteTask) {
  std::string f = "complete task";
  std::string f2 = "kek";
  ASSERT_EQ(GeneralCommandsValidator::validateCompleteTask(f),
            GeneralCommandsValidator::CommandToken::COMPLETE_TASK);
  ASSERT_EQ(GeneralCommandsValidator::validateCompleteTask(f2),
            GeneralCommandsValidator::CommandToken::INCORRECT_COMMAND);
}
TEST_F(GeneralCommandsValidatorTest, shouldValidateDeleteTask) {
  std::string f = "delete task";
  std::string f2 = "kek";
  ASSERT_EQ(GeneralCommandsValidator::validateDeleteTask(f),
            GeneralCommandsValidator::CommandToken::DELETE_TASK);
  ASSERT_EQ(GeneralCommandsValidator::validateDeleteTask(f2),
            GeneralCommandsValidator::CommandToken::INCORRECT_COMMAND);
}
TEST_F(GeneralCommandsValidatorTest, shouldValidateExit) {
  std::string f = "exit";
  std::string f2 = "kek";
  ASSERT_EQ(GeneralCommandsValidator::validateExit(f),
            GeneralCommandsValidator::CommandToken::EXIT);
  ASSERT_EQ(GeneralCommandsValidator::validateExit(f2),
            GeneralCommandsValidator::CommandToken::INCORRECT_COMMAND);
}
TEST_F(GeneralCommandsValidatorTest, shouldValidateSave) {
  std::string f = "save";
  std::string f2 = "kek";
  ASSERT_EQ(GeneralCommandsValidator::validateSave(f),
            GeneralCommandsValidator::CommandToken::SAVE);
  ASSERT_EQ(GeneralCommandsValidator::validateLoad(f2),
            GeneralCommandsValidator::CommandToken::INCORRECT_COMMAND);
}
TEST_F(GeneralCommandsValidatorTest, shouldValidateLoad) {
  std::string f = "load";
  std::string f2 = "kek";
  ASSERT_EQ(GeneralCommandsValidator::validateLoad(f),
            GeneralCommandsValidator::CommandToken::LOAD);
  ASSERT_EQ(GeneralCommandsValidator::validateLoad(f2),
            GeneralCommandsValidator::CommandToken::INCORRECT_COMMAND);
}
