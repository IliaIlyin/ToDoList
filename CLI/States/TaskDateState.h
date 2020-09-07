//
// Created by illia.ilin on 8/25/2020.
//

#ifndef TODOLIST_CLI_STATES_TASKDATESTATE_H_
#define TODOLIST_CLI_STATES_TASKDATESTATE_H_

#include "State.h"
#include "Validators/Validator.h"
#include <memory>

class TaskDate : public State {

 public:
  void read() override ;
  std::unique_ptr<State> changeState() override;
  void execute(Context &context) override;
  void print() override;

 private:
  std::unique_ptr<Validator> validator_;
};

#endif //TODOLIST_CLI_STATES_TASKDATESTATE_H_
