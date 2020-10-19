//
// Created by illia.ilin on 8/27/2020.
//

#ifndef TODOLIST_CLI_VALIDATORS_TASKIDVALIDATOR_H_
#define TODOLIST_CLI_VALIDATORS_TASKIDVALIDATOR_H_

#include "Validators/Validator.h"
#include "Factories/Validators/GeneralInputValidator.h"
/*
 * class that validates task id
 */
class TaskIdValidator : public Validator<GeneralInputValidator::InputToken> {
 public:
  GeneralInputValidator::InputToken validate(const std::string &str) override;
};

#endif //TODOLIST_CLI_VALIDATORS_TASKIDVALIDATOR_H_
