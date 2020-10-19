//
// Created by Ilya on 9/22/2020.
//

#ifndef TODOLIST_CLI_VALIDATORS_INPUTVALIDATORS_EXITVALIDATOR_H_
#define TODOLIST_CLI_VALIDATORS_INPUTVALIDATORS_EXITVALIDATOR_H_
#include "Validators/Validator.h"
#include "Factories/Validators/GeneralInputValidator.h"
/*
 * class that validates exit
 */
class ExitValidator : public Validator<GeneralInputValidator::InputToken> {
 public:
  GeneralInputValidator::InputToken validate(const std::string &str) override;

};

#endif //TODOLIST_CLI_VALIDATORS_INPUTVALIDATORS_EXITVALIDATOR_H_
