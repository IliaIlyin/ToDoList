//
// Created by Ilya on 9/21/2020.
//

#ifndef TODOLIST_CLI_VALIDATORS_BASESTATEVALIDATOR_H_
#define TODOLIST_CLI_VALIDATORS_BASESTATEVALIDATOR_H_
#include "Validator.h"
#include "Factories/Validators/GeneralCommandsValidator.h"
/*
 * class that validates commands
 */
class BaseStateValidator : public Validator<GeneralCommandsValidator::CommandToken> {
 public:
  GeneralCommandsValidator::CommandToken validate(const std::string &s) override;
};

#endif //TODOLIST_CLI_VALIDATORS_BASESTATEVALIDATOR_H_
