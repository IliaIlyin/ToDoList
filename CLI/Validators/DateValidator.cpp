//
// Created by illia.ilin on 8/25/2020.
//

#include "DateValidator.h"

CommandsValidator::ValidateResult DateValidator::validate(const std::string & str) {
    return CommandsValidator::validateDate(str);
}
