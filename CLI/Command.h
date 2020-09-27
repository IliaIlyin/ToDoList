//
// Created by illia.ilin on 8/28/2020.
//

#ifndef TODOLIST_CLI_VALIDATORS_COMMAND_H_
#define TODOLIST_CLI_VALIDATORS_COMMAND_H_

#include <memory>
class Visitor;
/*
 * class for users' commands
 */
class Command {
 public:
  /*
   * method that executes command
   *
   * @return void
   */
  virtual void execute()=0;
  /*
   * method that accepts visitor
   *
   * @input pointer to the visitor to accept
   *
   * @return void
   */
  virtual void accept(std::shared_ptr<Visitor> v)=0;
};
#endif //TODOLIST_CLI_VALIDATORS_COMMAND_H_
