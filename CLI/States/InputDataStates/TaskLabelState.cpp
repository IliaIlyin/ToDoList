//
// Created by illia.ilin on 8/25/2020.
//

#include "TaskLabelState.h"
GeneralInputValidator::InputToken TaskLabelState::read(std::shared_ptr<IOStreamInterface> inputer) {
  std::string s;
  inputer->print(print_line_);
  s = inputer->input();
  if (validator_->validate(s) == GeneralInputValidator::InputToken::CORRECT)
    this->label_ = s;
  return validator_->validate(s);
}

std::shared_ptr<InputState> TaskLabelState::changeState() {
  return std::make_shared<ExitState>(ExitState(std::make_shared<ExitValidator>()));
}

InputContext TaskLabelState::fillContext(const InputContext &context) {
  InputContext input_context(context);
  input_context.setLabel(label_);
  return input_context;
}

TaskLabelState::TaskLabelState(std::shared_ptr<Validator<GeneralInputValidator::InputToken>> validator,
                               std::string print_line) : validator_(
    validator), print_line_(print_line) {

}