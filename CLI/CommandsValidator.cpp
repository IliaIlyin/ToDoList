//
// Created by illia.ilin on 8/20/2020.
//

#include "CommandsValidator.h"

CommandsValidator::ValidateResult CommandsValidator::validateShowAll(const std::string& s) {
  std::string f = "show all";
  if (s == f) {
    return ValidateResult::CORRECT;
  }
  return ValidateResult::INCORRECT_COMMAND;
}

CommandsValidator::ValidateResult CommandsValidator::validateShowToday(const std::string& s) {
  std::string f = "show today";
  if (s == f) {
    return ValidateResult::CORRECT;
  }
  std::string f2 = "show today sort priority";
  if (s == f2) {
    return ValidateResult::CORRECT;
  } else {
    return ValidateResult::INCORRECT_COMMAND;
  }
}

CommandsValidator::ValidateResult CommandsValidator::validateShowLabel(const std::string& s) {
  std::string f = "show label";
  if (s == f) {
      return ValidateResult::CORRECT;
  }
  return ValidateResult::INCORRECT_COMMAND;
}

CommandsValidator::ValidateResult CommandsValidator::validateShowDueDate(const std::string& s) {
  std::string f = "show due date";
  if (s == f) {
    return ValidateResult::CORRECT;
  }
  return ValidateResult::INCORRECT_COMMAND;
}

CommandsValidator::ValidateResult CommandsValidator::validateAddTask(const std::string& s) {
  std::string f="Add task";
  if(s==f)
    return ValidateResult::CORRECT;
  return ValidateResult::INCORRECT_COMMAND;
}

CommandsValidator::ValidateResult CommandsValidator::validateName(const std::string& s) {
  if(s!="")
    return ValidateResult::CORRECT;
  return ValidateResult::INCORRECT_INPUT_NAME;
}

CommandsValidator::ValidateResult CommandsValidator::validateDate(const std::string& s) {
  try {
    boost::gregorian::from_string(s);
    return ValidateResult::CORRECT;
  }
  catch (...) {
    return ValidateResult::INCORRECT_INPUT_DATE;
  }
}

CommandsValidator::ValidateResult CommandsValidator::validatePriority(const std::string &s) {
  if(s=="NONE" || s=="FIRST" || s=="SECOND" || s=="THIRD")
    return ValidateResult::CORRECT;
  return ValidateResult::INCORRECT_INPUT_PRIORITY;
}

CommandsValidator::ValidateResult CommandsValidator::validateLabel(const std::string &s) {
  if(s!="")
    return ValidateResult::CORRECT;
  return ValidateResult::INCORRECT_INPUT_LABEL;
}

CommandsValidator::ValidateResult CommandsValidator::validateAddSubTask(const std::string &s) {
  std::string f="Add subtask";
  if(s==f)
    return ValidateResult::CORRECT;
  return ValidateResult::INCORRECT_COMMAND;
}

CommandsValidator::ValidateResult CommandsValidator::validateGetTask(const std::string &s) {
  std::string f="get task";
  if(s==f)
    return ValidateResult::CORRECT;
  return ValidateResult::INCORRECT_COMMAND;
}

CommandsValidator::ValidateResult CommandsValidator::validateGetSubTasks(const std::string &s) {
  std::string f="get subtasks";
  if(s==f)
    return ValidateResult::CORRECT;
  return ValidateResult::INCORRECT_COMMAND;
}
CommandsValidator::ValidateResult CommandsValidator::validatePostponeTask(const std::string &s) {
  std::string f="postpone task";
  if(s==f)
    return ValidateResult::CORRECT;
  return ValidateResult::INCORRECT_COMMAND;
}

CommandsValidator::ValidateResult CommandsValidator::validateCompleteTask(const std::string &s) {
  std::string f="complete task";
  if(s==f)
    return ValidateResult::CORRECT;
  return ValidateResult::INCORRECT_COMMAND;
}

CommandsValidator::ValidateResult CommandsValidator::validateDeleteTask(const std::string &s) {
  std::string f="delete task";
  if(s==f)
    return ValidateResult::CORRECT;
  return ValidateResult::INCORRECT_COMMAND;
}

CommandsValidator::ValidateResult CommandsValidator::validateId(const std::string& s) {
  int num = std::stoi(s);
  if(s==std::to_string(num))
    return ValidateResult::CORRECT;
  return ValidateResult::INCORRECT_INPUT_ID;
}
std::string CommandsValidator::interpretResult(CommandsValidator::ValidateResult result) {
  std::string str;
  switch(result){
    case ValidateResult::CORRECT:
      str="correct";
      break;
    case ValidateResult::INCORRECT_INPUT_NAME:
      str="incorrect input name";
      break;
    case ValidateResult::INCORRECT_COMMAND:
      str="incorrect input command";
      break;
    case ValidateResult::INCORRECT_INPUT_LABEL:
      str="incorrect input result";
      break;
    case ValidateResult::INCORRECT_INPUT_PRIORITY:
      str="incorrect input priority";
      break;
    case ValidateResult::INCORRECT_INPUT_DATE:
      str="incorrect input date";
      break;
    case ValidateResult::INCORRECT_INPUT_ID:
      str="not an id";
      break;
  }
  return str;
}
