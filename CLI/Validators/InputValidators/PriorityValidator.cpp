//
// Created by illia.ilin on 8/25/2020.
//

#include "PriorityValidator.h"

GeneralInputValidator::InputToken PriorityValidator::validate(const std::string &str) {
  return GeneralInputValidator::validatePriority(str);
}
