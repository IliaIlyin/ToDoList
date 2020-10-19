//
// Created by illia.ilin on 8/25/2020.
//

#include "LabelValidator.h"
GeneralInputValidator::InputToken LabelValidator::validate(const std::string &str) {
  return GeneralInputValidator::validateLabel(str);
}
