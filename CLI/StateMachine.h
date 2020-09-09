//
// Created by illia.ilin on 8/20/2020.
//

#ifndef TODOLIST_CLI_STATEMACHINE_H_
#define TODOLIST_CLI_STATEMACHINE_H_

#include "Contexts/Context.h"
#include "States/BaseState.h"
#include "CommandFactory.h"
class StateMachine {

 public:
  StateMachine( std::unique_ptr<State> state, std::shared_ptr<Context> context);

 public:
  [[noreturn]] void run();

  const std::shared_ptr<Context> &GetContext() const;

 private:
  std::unique_ptr<State> state_;
  std::shared_ptr<CommandFactory> command_factory_;
  std::shared_ptr<Context> context_;
};

#endif //TODOLIST_CLI_STATEMACHINE_H_
