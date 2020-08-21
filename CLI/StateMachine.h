//
// Created by illia.ilin on 8/20/2020.
//

#ifndef TODOLIST_CLI_STATEMACHINE_H_
#define TODOLIST_CLI_STATEMACHINE_H_

#include "Context.h"
#include "BaseState.h"
class StateMachine {

 public:
  StateMachine();

 public:
  void run();

  const Context &GetContext() const;
 private:
  std::unique_ptr<State> state_;
  Context context_;
};

#endif //TODOLIST_CLI_STATEMACHINE_H_
