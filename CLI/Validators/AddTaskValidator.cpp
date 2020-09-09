//
// Created by illia.ilin on 8/25/2020.
//

#include "AddTaskValidator.h"
CommandsValidator::ValidateResult AddTaskValidator::validate(const std::string &) {
  return CommandsValidator::ValidateResult::CORRECT;
}
