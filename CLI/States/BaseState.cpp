//
// Created by illia.ilin on 8/20/2020.
//

#include "BaseState.h"
Tokenizer::CommandToken BaseState::read() {
  std::string cmd;
  std::cin >> cmd;
  auto token = tokenizer_->tokenize(cmd);
  switch(token){
    case Tokenizer::CommandToken::ADD_TASK:
      next_state_ = std::make_unique<AddTaskState<BaseState,BaseState>();
  }
  return token;
}

void BaseState::print() {
  std::string input = "Welcome User! Available commands: "
                      "Add task TaskName [due date, priority, label ]"
                      "show all [sort priority]"
                      "show today [sort priority]"
                      "show due date <date>"
                      "show label <label>";
  std::cout<<input<<std::endl;
}

void BaseState::execute(Context &context, std::unique_ptr<Command> cmd) {
cmd->execute();
}

std::unique_ptr<State> BaseState::changeState() {
  return std::move(next_state_);
}


