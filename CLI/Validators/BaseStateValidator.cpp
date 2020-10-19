//
// Created by Ilya on 9/21/2020.
//

#include "BaseStateValidator.h"

GeneralCommandsValidator::CommandToken BaseStateValidator::validate(const std::string &s) {
  if (GeneralCommandsValidator::validateAddSubTask(s) == GeneralCommandsValidator::CommandToken::ADD_SUBTASK)
    return GeneralCommandsValidator::CommandToken::ADD_SUBTASK;
  if (GeneralCommandsValidator::validateAddTask(s) == GeneralCommandsValidator::CommandToken::ADD_TASK)
    return GeneralCommandsValidator::CommandToken::ADD_TASK;
  if (GeneralCommandsValidator::validateCompleteTask(s) == GeneralCommandsValidator::CommandToken::COMPLETE_TASK)
    return GeneralCommandsValidator::CommandToken::COMPLETE_TASK;
  if (GeneralCommandsValidator::validateExit(s) == GeneralCommandsValidator::CommandToken::EXIT)
    return GeneralCommandsValidator::CommandToken::EXIT;
  if (GeneralCommandsValidator::validateDeleteTask(s) == GeneralCommandsValidator::CommandToken::DELETE_TASK)
    return GeneralCommandsValidator::CommandToken::DELETE_TASK;
  if (GeneralCommandsValidator::validatePostponeTask(s) == GeneralCommandsValidator::CommandToken::POSTPONE_TASK)
    return GeneralCommandsValidator::CommandToken::POSTPONE_TASK;
  if (GeneralCommandsValidator::validateGetTask(s) == GeneralCommandsValidator::CommandToken::GET_TASK)
    return GeneralCommandsValidator::CommandToken::GET_TASK;
  if (GeneralCommandsValidator::validateGetSubTasks(s) == GeneralCommandsValidator::CommandToken::GET_SUBTASK)
    return GeneralCommandsValidator::CommandToken::GET_SUBTASK;
  if (GeneralCommandsValidator::validateShowAll(s) == GeneralCommandsValidator::CommandToken::SHOW_ALL_SORT_DATE)
    return GeneralCommandsValidator::CommandToken::SHOW_ALL_SORT_DATE;
  if (GeneralCommandsValidator::validateShowAll(s) == GeneralCommandsValidator::CommandToken::SHOW_ALL_SORT_LABEL)
    return GeneralCommandsValidator::CommandToken::SHOW_ALL_SORT_LABEL;
  if (GeneralCommandsValidator::validateShowAll(s) == GeneralCommandsValidator::CommandToken::SHOW_ALL_SORT_PRIORITY)
    return GeneralCommandsValidator::CommandToken::SHOW_ALL_SORT_PRIORITY;
  if (GeneralCommandsValidator::validateShowDueDate(s)
      == GeneralCommandsValidator::CommandToken::SHOW_DUE_DATE_SORT_DATE)
    return GeneralCommandsValidator::CommandToken::SHOW_DUE_DATE_SORT_DATE;
  if (GeneralCommandsValidator::validateShowDueDate(s)
      == GeneralCommandsValidator::CommandToken::SHOW_DUE_DATE_SORT_LABEL)
    return GeneralCommandsValidator::CommandToken::SHOW_DUE_DATE_SORT_LABEL;
  if (GeneralCommandsValidator::validateShowDueDate(s)
      == GeneralCommandsValidator::CommandToken::SHOW_DUE_DATE_SORT_PRIORITY)
    return GeneralCommandsValidator::CommandToken::SHOW_DUE_DATE_SORT_PRIORITY;
  if (GeneralCommandsValidator::validateShowToday(s)
      == GeneralCommandsValidator::CommandToken::SHOW_TODAY_SORT_PRIORITY)
    return GeneralCommandsValidator::CommandToken::SHOW_TODAY_SORT_PRIORITY;
  if (GeneralCommandsValidator::validateShowToday(s) == GeneralCommandsValidator::CommandToken::SHOW_TODAY_SORT_LABEL)
    return GeneralCommandsValidator::CommandToken::SHOW_TODAY_SORT_LABEL;
  if (GeneralCommandsValidator::validateSave(s) == GeneralCommandsValidator::CommandToken::SAVE)
    return GeneralCommandsValidator::CommandToken::SAVE;
  if (GeneralCommandsValidator::validateLoad(s) == GeneralCommandsValidator::CommandToken::LOAD)
    return GeneralCommandsValidator::CommandToken::LOAD;
  return GeneralCommandsValidator::CommandToken::INCORRECT_COMMAND;
}
