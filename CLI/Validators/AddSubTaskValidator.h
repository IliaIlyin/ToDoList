//
// Created by illia.ilin on 8/25/2020.
//

#ifndef TODOLIST_CLI_VALIDATORS_ADDSUBTASKVALIDATOR_H_
#define TODOLIST_CLI_VALIDATORS_ADDSUBTASKVALIDATOR_H_

#include "Validator.h"
class AddSubTaskValidator: public Validator  {

 CommandsValidator::ValidateResult validate(const std::string &) override;

};

#endif //TODOLIST_CLI_VALIDATORS_ADDSUBTASKVALIDATOR_H_
