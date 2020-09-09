//
// Created by illia.ilin on 8/20/2020.
//

#ifndef TODOLIST_CLI_BASESTATE_H_
#define TODOLIST_CLI_BASESTATE_H_
#include "State.h"
#include "Validators/Validator.h"
#include "CommandFactory.h"
#include "Tokenizer.h"
#include <memory>
#include "AddTaskState.h"


class BaseState : public State {

 public:
  Tokenizer::CommandToken read() override;
  std::unique_ptr<State> changeState() override;
  void execute(Context &context, std::shared_ptr<Visitor> visitor) override;
  void print() override;

 private:
  std::unique_ptr<State> next_state_;
  std::unique_ptr<Validator> validator_;
  std::unique_ptr<Tokenizer> tokenizer_;
  std::unique_ptr<CommandFactory> command_factory_;
};

#endif //TODOLIST_CLI_BASESTATE_H_
