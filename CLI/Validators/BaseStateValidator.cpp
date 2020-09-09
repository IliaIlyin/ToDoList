//
// Created by illia.ilin on 8/28/2020.
//

#include "BaseStateValidator.h"
CommandsValidator::ValidateResult BaseStateValidator::validate(const std::string &str) {
  if(CommandsValidator::validateAddTask(str)==CommandsValidator::ValidateResult::CORRECT)
    return CommandsValidator::ValidateResult::CORRECT;
  if(CommandsValidator::validateAddSubTask(str)==CommandsValidator::ValidateResult::CORRECT)
    return CommandsValidator::ValidateResult::CORRECT;
  if(CommandsValidator::validateCompleteTask(str)==CommandsValidator::ValidateResult::CORRECT)
    return CommandsValidator::ValidateResult::CORRECT;
  if(CommandsValidator::validateDeleteTask(str)==CommandsValidator::ValidateResult::CORRECT)
    return CommandsValidator::ValidateResult::CORRECT;
  if(CommandsValidator::validateGetSubTasks(str)==CommandsValidator::ValidateResult::CORRECT)
    return CommandsValidator::ValidateResult::CORRECT;
  if(CommandsValidator::validateShowDueDate(str)==CommandsValidator::ValidateResult::CORRECT)
    return CommandsValidator::ValidateResult::CORRECT;
  if(CommandsValidator::validateGetTask(str)==CommandsValidator::ValidateResult::CORRECT)
    return CommandsValidator::ValidateResult::CORRECT;
  if(CommandsValidator::validatePostponeTask(str)==CommandsValidator::ValidateResult::CORRECT)
    return CommandsValidator::ValidateResult::CORRECT;
  if(CommandsValidator::validateShowAll(str)==CommandsValidator::ValidateResult::CORRECT)
    return CommandsValidator::ValidateResult::CORRECT;
  if(CommandsValidator::validateShowToday(str)==CommandsValidator::ValidateResult::CORRECT)
    return CommandsValidator::ValidateResult::CORRECT;
  if(CommandsValidator::validateShowLabel(str)==CommandsValidator::ValidateResult::CORRECT)
    return CommandsValidator::ValidateResult::CORRECT;
  return CommandsValidator::ValidateResult::INCORRECT_COMMAND;
}
