//
// Created by illia.ilin on 8/19/2020.
//

#ifndef TODOLIST_CLI_STATE_H_
#define TODOLIST_CLI_STATE_H_
#include <memory>
#include <Command.h>
#include "Tokenizer.h"
#include "Contexts/Context.h"

class State{

 public:
  virtual Tokenizer::CommandToken read()=0;
  virtual std::unique_ptr<State> changeState()=0;
  virtual void execute(Context& context, std::unique_ptr<Command> command)=0;
  virtual void print()=0;

 public:
  virtual ~State()=default;
};
#endif //TODOLIST_CLI_STATE_H_
