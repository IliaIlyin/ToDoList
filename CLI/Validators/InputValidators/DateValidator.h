//
// Created by illia.ilin on 8/25/2020.
//

#ifndef TODOLIST_CLI_VALIDATORS_DATEVALIDATOR_H_
#define TODOLIST_CLI_VALIDATORS_DATEVALIDATOR_H_

#include "Validators/Validator.h"
#include "Factories/Validators/GeneralInputValidator.h"
/*
 * class that validates task dates
 */
class DateValidator : public Validator<GeneralInputValidator::InputToken> {
 public:
  GeneralInputValidator::InputToken validate(const std::string &str) override;
};

#endif //TODOLIST_CLI_VALIDATORS_DATEVALIDATOR_H_
