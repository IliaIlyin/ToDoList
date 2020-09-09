//
// Created by illia.ilin on 8/20/2020.
//

#ifndef TODOLIST_CLI_EXITSTATE_H_
#define TODOLIST_CLI_EXITSTATE_H_
#include "State.h"
#include "Validators/Validator.h"
#include <memory>

class ExitState : public State {

 public:
  void read() override ;
  std::unique_ptr<State> changeState() override;
  void execute(Context &context) override;
  void print() override;

 private:
  std::unique_ptr<Validator> validator_;
};
#endif //TODOLIST_CLI_EXITSTATE_H_
