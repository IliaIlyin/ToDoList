//
// Created by illia.ilin on 8/28/2020.
//

#ifndef TODOLIST_CLI_VALIDATORS_BASESTATEVALIDATOR_H_
#define TODOLIST_CLI_VALIDATORS_BASESTATEVALIDATOR_H_

#include "Validator.h"

class BaseStateValidator : public Validator {

  CommandsValidator::ValidateResult validate(const std::string & str) override;

};

#endif //TODOLIST_CLI_VALIDATORS_BASESTATEVALIDATOR_H_
