//
// Created by Ilya on 9/14/2020.
//

#include "InputStateMachine.h"
GeneralInputValidator::InputToken InputStateMachine::run() {
  auto result = GeneralInputValidator::InputToken::CORRECT;
  while (result != GeneralInputValidator::InputToken::CANCEL_COMMAND
      && result != GeneralInputValidator::InputToken::SUCCESS) {
    result = begin_->read();
    if (result != GeneralInputValidator::InputToken::CORRECT && result != GeneralInputValidator::InputToken::SUCCESS) {
      std::cout << GeneralInputValidator::interpretResult(result) << std::endl;
      continue;
    }
    context_ = begin_->fillContext(context_);
    begin_ = begin_->changeState();
  }
  return result;
}
InputStateMachine::InputStateMachine(const std::shared_ptr<InputState> &begin, InputContext &context)
    : begin_(begin), context_(context) {}

InputContext InputStateMachine::GetContext() const {
  return context_;
}

