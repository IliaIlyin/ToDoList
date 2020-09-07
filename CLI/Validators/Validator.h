//
// Created by illia.ilin on 8/25/2020.
//

#ifndef TODOLIST_CLI_VALIDATORS_VALIDATOR_H_
#define TODOLIST_CLI_VALIDATORS_VALIDATOR_H_

#include "CommandsValidator.h"

class Validator{

 public:
  virtual CommandsValidator::ValidateResult validate(const std::string&)=0;
};

#endif //TODOLIST_CLI_VALIDATORS_VALIDATOR_H_
