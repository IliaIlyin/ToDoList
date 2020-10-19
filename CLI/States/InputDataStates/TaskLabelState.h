//
// Created by illia.ilin on 8/25/2020.
//

#ifndef TODOLIST_CLI_STATES_TASKLABELSTATE_H_
#define TODOLIST_CLI_STATES_TASKLABELSTATE_H_

#include "States/InputState.h"
#include "Validators/Validator.h"
#include "Validators/InputValidators/ExitValidator.h"
#include "ExitState.h"
#include <memory>
/*
 * class to input task label
 *
 * * @author Ilya Ilyin
 */
class TaskLabelState : public InputState {

 public:
  TaskLabelState(std::shared_ptr<Validator<GeneralInputValidator::InputToken>> validator, std::string print_line);

 public:
  GeneralInputValidator::InputToken read() override;
  std::shared_ptr<InputState> changeState() override;
  InputContext fillContext(const InputContext &context) override;

 private:
  std::shared_ptr<Validator<GeneralInputValidator::InputToken>> validator_;
  std::string label_;
  std::string print_line_;
};

#endif //TODOLIST_CLI_STATES_TASKLABELSTATE_H_
