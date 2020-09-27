//
// Created by illia.ilin on 8/25/2020.
//

#ifndef TODOLIST_CLI_VALIDATORS_TASKNAMEVALIDATOR_H_
#define TODOLIST_CLI_VALIDATORS_TASKNAMEVALIDATOR_H_

#include "Validators/Validator.h"
#include "Factories/Validators/GeneralInputValidator.h"
/*
 * class that validate task names
 */
class TaskNameValidator : public Validator<GeneralInputValidator::InputToken>{

  GeneralInputValidator::InputToken validate(const std::string & str) override;

};

#endif //TODOLIST_CLI_VALIDATORS_TASKNAMEVALIDATOR_H_
