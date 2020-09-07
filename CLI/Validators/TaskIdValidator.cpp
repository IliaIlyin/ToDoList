//
// Created by illia.ilin on 8/27/2020.
//

#include "TaskIdValidator.h"
CommandsValidator::ValidateResult TaskIdValidator::validate(const std::string &str) {
  return CommandsValidator::validateId(str);
}
