//
// Created by illia.ilin on 8/20/2020.
//

#include "StateMachine.h"

void StateMachine::run() {
  for(;;){
    state_->read(context_);
    state_->execute(context_);
    state_ = std::move(state_->changeState());
  }
}
StateMachine::StateMachine() {
  BaseState base_state;
  state_ = std::make_unique<BaseState>(base_state);
}
const Context &StateMachine::GetContext() const {
  return context_;
}
