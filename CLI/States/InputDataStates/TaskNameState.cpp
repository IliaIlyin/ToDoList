//
// Created by illia.ilin on 8/25/2020.
//

#include "TaskNameState.h"

GeneralInputValidator::InputToken TaskNameState::read() {
  std::string s;
  std::getline(std::cin,s);
  if (validator_->validate(s) == GeneralInputValidator::InputToken::CORRECT)
    this->name_ = s;
  return validator_->validate(s);
}

std::shared_ptr<InputState> TaskNameState::changeState() {
  std::shared_ptr<DateValidator> validator=std::make_shared<DateValidator>();
  return std::make_shared<TaskDateState<TaskPriorityState, PriorityValidator>>(TaskDateState<TaskPriorityState,
                                                                                             PriorityValidator>(
      validator));
}

InputContext TaskNameState::fillContext(const InputContext &context) {
  InputContext input_context(context);
  input_context.setName(name_);
  return input_context;
}

TaskNameState::TaskNameState(std::shared_ptr<Validator<GeneralInputValidator::InputToken>> validator) : validator_(
    validator) {

}

