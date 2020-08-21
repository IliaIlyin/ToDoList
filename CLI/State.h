//
// Created by illia.ilin on 8/19/2020.
//

#ifndef TODOLIST_CLI_STATE_H_
#define TODOLIST_CLI_STATE_H_
#include <memory>
#include "Context.h"
class State{

 public:
  virtual void read(Context& context)=0;
  virtual std::unique_ptr<State> changeState()=0;
  virtual void execute(Context& context)=0;
  virtual void print()=0;

 public:
  virtual ~State()=default;
};
#endif //TODOLIST_CLI_STATE_H_
