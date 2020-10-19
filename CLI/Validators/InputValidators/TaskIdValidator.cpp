//
// Created by illia.ilin on 8/27/2020.
//

#include "TaskIdValidator.h"
GeneralInputValidator::InputToken TaskIdValidator::validate(const std::string &str) {
  return GeneralInputValidator::validateId(str);
}
