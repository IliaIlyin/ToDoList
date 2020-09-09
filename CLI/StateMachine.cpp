//
// Created by illia.ilin on 8/20/2020.
//

#include "StateMachine.h"

[[noreturn]] void StateMachine::run() {
  for (;;) {
    auto token=state_->read();
    auto cmd = command_factory_->create(token);
    state_->execute(context_);
    state_ = std::move(state_->changeState());
  }
}
const std::shared_ptr<Context> &StateMachine::GetContext() const {
  return context_;
}
StateMachine::StateMachine(std::unique_ptr<State> state, std::shared_ptr<Context> context)
    : state_(std::move(state)), context_(context) {
}
