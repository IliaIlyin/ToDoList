//
// Created by illia.ilin on 8/25/2020.
//

#ifndef TODOLIST_CLI_VALIDATORS_TASKNAMEVALIDATOR_H_
#define TODOLIST_CLI_VALIDATORS_TASKNAMEVALIDATOR_H_
#include "Validator.h"
class TaskNameValidator : public Validator {
  
  CommandsValidator::ValidateResult validate(const std::string & str) override;

};

#endif //TODOLIST_CLI_VALIDATORS_TASKNAMEVALIDATOR_H_
