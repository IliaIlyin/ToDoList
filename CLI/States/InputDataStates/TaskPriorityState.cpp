//
// Created by illia.ilin on 8/25/2020.
//

#include "TaskPriorityState.h"

GeneralInputValidator::InputToken TaskPriorityState::read(std::shared_ptr<IOStreamInterface> inputer) {
  std::string s;
  inputer->print("Input task priority or write cancel command to cancel command");
  s = inputer->input();
  if (validator_->validate(s) == GeneralInputValidator::InputToken::CORRECT)
    this->priority_ = getPriorityFromString(s);
  return validator_->validate(s);
}

std::shared_ptr<InputState> TaskPriorityState::changeState() {
  std::shared_ptr<LabelValidator> validator = std::make_shared<LabelValidator>();
  return std::make_shared<TaskLabelState>(TaskLabelState(validator,
                                                         "Input task label or write cancel command to cancel command"));
}

InputContext TaskPriorityState::fillContext(const InputContext &context) {
  InputContext input_context(context);
  input_context.setPriority(priority_);
  return input_context;
}

TaskPriorityState::TaskPriorityState(std::shared_ptr<Validator<GeneralInputValidator::InputToken>> validator)
    : validator_(
    validator) {

}