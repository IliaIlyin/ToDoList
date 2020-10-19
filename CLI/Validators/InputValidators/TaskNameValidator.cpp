//
// Created by illia.ilin on 8/25/2020.
//

#include "TaskNameValidator.h"
GeneralInputValidator::InputToken TaskNameValidator::validate(const std::string &str) {
  return GeneralInputValidator::validateName(str);
}
