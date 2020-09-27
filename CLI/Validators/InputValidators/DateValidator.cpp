//
// Created by illia.ilin on 8/25/2020.
//

#include "DateValidator.h"

GeneralInputValidator::InputToken DateValidator::validate(const std::string &str) {
  return GeneralInputValidator::validateDate(str);
}
