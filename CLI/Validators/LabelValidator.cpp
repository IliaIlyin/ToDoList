//
// Created by illia.ilin on 8/25/2020.
//

#include "LabelValidator.h"
CommandsValidator::ValidateResult LabelValidator::validate(const std::string & str) {
  return CommandsValidator::validateLabel(str);
}
