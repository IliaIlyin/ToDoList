//
// Created by illia.ilin on 8/25/2020.
//

#ifndef TODOLIST_CLI_VALIDATORS_LABELVALIDATOR_H_
#define TODOLIST_CLI_VALIDATORS_LABELVALIDATOR_H_

#include "Validator.h"

class LabelValidator:public Validator {

  CommandsValidator::ValidateResult validate(const std::string & str) override;

};

#endif //TODOLIST_CLI_VALIDATORS_LABELVALIDATOR_H_
