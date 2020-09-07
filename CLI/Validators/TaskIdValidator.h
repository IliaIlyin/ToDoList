//
// Created by illia.ilin on 8/27/2020.
//

#ifndef TODOLIST_CLI_VALIDATORS_TASKIDVALIDATOR_H_
#define TODOLIST_CLI_VALIDATORS_TASKIDVALIDATOR_H_

#include "Validator.h"

class TaskIdValidator : public Validator {
  CommandsValidator::ValidateResult validate(const std::string & str) override;

};


#endif //TODOLIST_CLI_VALIDATORS_TASKIDVALIDATOR_H_
