//
// Created by illia.ilin on 8/25/2020.
//

#ifndef TODOLIST_CLI_STATES_TASKNAMESTATE_H_
#define TODOLIST_CLI_STATES_TASKNAMESTATE_H_

#include "States/InputState.h"
#include "Validators/Validator.h"
#include "Validators/InputValidators/DateValidator.h"
#include "Validators/InputValidators/PriorityValidator.h"
#include "TaskPriorityState.h"
#include "ExitState.h"
#include "TaskDateState.h"
#include <memory>
#include <string>
/*
 * class to input task name
 *
 * @author Ilya Ilyin
 */
class TaskNameState : public InputState {

 public:
  TaskNameState(std::shared_ptr<Validator<GeneralInputValidator::InputToken>> validator);

 public:
  GeneralInputValidator::InputToken read(std::shared_ptr<IOStreamInterface> inputer) override;
  std::shared_ptr<InputState> changeState() override;
  InputContext fillContext(const InputContext &context) override;

 private:
  std::shared_ptr<Validator<GeneralInputValidator::InputToken>> validator_;
  std::string name_;
};
#endif //TODOLIST_CLI_STATES_TASKNAMESTATE_H_
