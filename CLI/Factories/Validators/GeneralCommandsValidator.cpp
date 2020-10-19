//
// Created by illia.ilin on 8/20/2020.
//

#include "GeneralCommandsValidator.h"

GeneralCommandsValidator::CommandToken GeneralCommandsValidator::validateShowAll(const std::string &s) {
  std::string f = "show all sort priority";
  std::string f2 = "show all sort label";
  std::string f3 = "show all sort date";
  if (s == f)
    return CommandToken::SHOW_ALL_SORT_PRIORITY;
  if (s == f2)
    return CommandToken::SHOW_ALL_SORT_LABEL;
  if (s == f3)
    return CommandToken::SHOW_ALL_SORT_DATE;
  return CommandToken::INCORRECT_COMMAND;
}

GeneralCommandsValidator::CommandToken GeneralCommandsValidator::validateShowToday(const std::string &s) {
  std::string f = "show today sort label";
  if (s == f) {
    return CommandToken::SHOW_TODAY_SORT_LABEL;
  }
  std::string f2 = "show today sort priority";
  if (s == f2) {
    return CommandToken::SHOW_TODAY_SORT_PRIORITY;
  } else {
    return CommandToken::INCORRECT_COMMAND;
  }
}

GeneralCommandsValidator::CommandToken GeneralCommandsValidator::validateShowDueDate(const std::string &s) {
  std::string f = "show due date sort date";
  std::string f2 = "show due date sort label";
  std::string f3 = "show due date sort priority";
  if (s == f)
    return CommandToken::SHOW_DUE_DATE_SORT_DATE;
  if (s == f2)
    return CommandToken::SHOW_DUE_DATE_SORT_LABEL;
  if (s == f3)
    return CommandToken::SHOW_DUE_DATE_SORT_PRIORITY;
  return CommandToken::INCORRECT_COMMAND;
}

GeneralCommandsValidator::CommandToken GeneralCommandsValidator::validateAddTask(const std::string &s) {
  std::string f = "Add task";
  if (s == f)
    return CommandToken::ADD_TASK;
  return CommandToken::INCORRECT_COMMAND;
}

GeneralCommandsValidator::CommandToken GeneralCommandsValidator::validateAddSubTask(const std::string &s) {
  std::string f = "Add subTask";
  if (s == f)
    return CommandToken::ADD_SUBTASK;
  return CommandToken::INCORRECT_COMMAND;
}

GeneralCommandsValidator::CommandToken GeneralCommandsValidator::validateGetTask(const std::string &s) {
  std::string f = "get task";
  if (s == f)
    return CommandToken::GET_TASK;
  return CommandToken::INCORRECT_COMMAND;
}

GeneralCommandsValidator::CommandToken GeneralCommandsValidator::validateGetSubTasks(const std::string &s) {
  std::string f = "get subTasks";
  if (s == f)
    return CommandToken::GET_SUBTASK;
  return CommandToken::INCORRECT_COMMAND;
}
GeneralCommandsValidator::CommandToken GeneralCommandsValidator::validatePostponeTask(const std::string &s) {
  std::string f = "postpone task";
  if (s == f)
    return CommandToken::POSTPONE_TASK;
  return CommandToken::INCORRECT_COMMAND;
}

GeneralCommandsValidator::CommandToken GeneralCommandsValidator::validateCompleteTask(const std::string &s) {
  std::string f = "complete task";
  if (s == f)
    return CommandToken::COMPLETE_TASK;
  return CommandToken::INCORRECT_COMMAND;
}

GeneralCommandsValidator::CommandToken GeneralCommandsValidator::validateDeleteTask(const std::string &s) {
  std::string f = "delete task";
  if (s == f)
    return CommandToken::DELETE_TASK;
  return CommandToken::INCORRECT_COMMAND;
}

std::string GeneralCommandsValidator::interpretResult(GeneralCommandsValidator::CommandToken result) {
  switch (result) {
    case CommandToken::COMPLETE_TASK:return "Completing task";
    case CommandToken::DELETE_TASK:return "Deleting task";
    case CommandToken::GET_TASK:return "Getting task";
    case CommandToken::POSTPONE_TASK:return "Postponing task";
    case CommandToken::SHOW_DUE_DATE_SORT_PRIORITY:return "Showing all due date by priority";
    case CommandToken::SHOW_DUE_DATE_SORT_LABEL:return "Showing all due date by label in lex order";
    case CommandToken::SHOW_DUE_DATE_SORT_DATE:return "Showing all due date by date";
    case CommandToken::SHOW_TODAY_SORT_LABEL:return "Showing today by label";
    case CommandToken::SHOW_TODAY_SORT_PRIORITY:return "Showing today by priority";
    case CommandToken::SHOW_ALL_SORT_LABEL:return "Showing all by label";
    case CommandToken::SHOW_ALL_SORT_PRIORITY:return "Showing all by priority";
    case CommandToken::SHOW_ALL_SORT_DATE:return "Showing all by date";
    case CommandToken::ADD_SUBTASK:return "Adding subTask";
    case CommandToken::ADD_TASK:return "Adding task";
    case CommandToken::GET_SUBTASK:return "Getting subTasks";
    case CommandToken::INCORRECT_COMMAND:return "Incorrect input command";
    case CommandToken::SAVE:return "Saving";
    case CommandToken::LOAD:return "Loading";
    case CommandToken::EXIT:return "Exiting. Thanks for using!";
  }
}
GeneralCommandsValidator::CommandToken GeneralCommandsValidator::validateExit(const std::string &s) {
  if (s == "exit")
    return CommandToken::EXIT;
  return CommandToken::INCORRECT_COMMAND;
}
GeneralCommandsValidator::CommandToken GeneralCommandsValidator::validateSave(const std::string &s) {
  std::string f = "save";
  if (s == f)
    return CommandToken::SAVE;
  return CommandToken::INCORRECT_COMMAND;
}
GeneralCommandsValidator::CommandToken GeneralCommandsValidator::validateLoad(const std::string &s) {
  std::string f = "load";
  if (s == f)
    return CommandToken::LOAD;
  return CommandToken::INCORRECT_COMMAND;
}
