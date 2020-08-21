//
// Created by illia.ilin on 8/20/2020.
//

#ifndef TODOLIST_CLI_BASESTATE_H_
#define TODOLIST_CLI_BASESTATE_H_
#include "State.h"
class BaseState : public State {

 public:
  void read(Context &context) override;
  std::unique_ptr<State> changeState() override;
  void execute(Context &context) override;
  void print() override;

};

#endif //TODOLIST_CLI_BASESTATE_H_
