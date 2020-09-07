//
// Created by illia.ilin on 8/25/2020.
//

#include "TaskNameValidator.h"
CommandsValidator::ValidateResult TaskNameValidator::validate(const std::string & str) {
  return CommandsValidator::validateName(str);
}
