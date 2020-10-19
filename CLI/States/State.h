//
// Created by illia.ilin on 8/19/2020.
//

#ifndef TODOLIST_CLI_STATE_H_
#define TODOLIST_CLI_STATE_H_
#include <memory>
#include "Factories/Validators/GeneralCommandsValidator.h"
class Command;
class Visitor;
#include "Contexts/Context.h"

/*
 * class that represent states that operate users' commands
 */
class State {

 public:
  /*
   * method to read users' input and represent the input as token
   *
   * @return GeneralCommandsValidator::CommandToken corresponding to the input
   */
  virtual GeneralCommandsValidator::CommandToken read() = 0;
  /*
   * method that changes current state
   *
   * @return pointer to the next state
   */
  virtual std::shared_ptr<State> changeState() = 0;
  /*
   * method to execute command
   *
   * @input pointer to the command need to be executed
   * @input pointer to the visitor to visit the command
   *
   * @return void
   */
  virtual void execute(std::shared_ptr<Command> command, std::shared_ptr<Visitor> visitor) = 0;
  /*
   * method to print the context
   *
   * @input pointer to the context po print
   *
   * @return void
   */
  virtual void print(std::shared_ptr<Context> context) = 0;

 public:
  virtual ~State() = default;
};
#endif //TODOLIST_CLI_STATE_H_
