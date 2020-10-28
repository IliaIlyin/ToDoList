//
// Created by illia.ilin on 8/25/2020.
//

#ifndef TODOLIST_CLI_STATES_TASKPRIORITYSTATE_H_
#define TODOLIST_CLI_STATES_TASKPRIORITYSTATE_H_

#include "States/InputState.h"
#include "Validators/Validator.h"
#include "TaskLabelState.h"
#include "Validators/InputValidators/LabelValidator.h"
#include <memory>
/*
 * class to input task priority
 *
 * @author Ilya Ilyin
 */
class TaskPriorityState : public InputState {

 public:
  TaskPriorityState(std::shared_ptr<Validator<GeneralInputValidator::InputToken>> validator);

 public:
  GeneralInputValidator::InputToken read(std::shared_ptr<IOStreamInterface> inputer) override;
  std::shared_ptr<InputState> changeState() override;
  InputContext fillContext(const InputContext &context) override;

 private:
  std::shared_ptr<Validator<GeneralInputValidator::InputToken>> validator_;
  Task::Priority priority_;
};

#endif //TODOLIST_CLI_STATES_TASKPRIORITYSTATE_H_
