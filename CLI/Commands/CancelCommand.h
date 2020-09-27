//
// Created by Ilya on 9/15/2020.
//

#ifndef TODOLIST_CLI_COMMANDS_CANCELCOMMAND_H_
#define TODOLIST_CLI_COMMANDS_CANCELCOMMAND_H_

#include "Command.h"
#include <iostream>
class CancelCommand : public Command {
 public:
  void execute() override;
  void accept(std::shared_ptr<Visitor> v) override;

};

#endif //TODOLIST_CLI_COMMANDS_CANCELCOMMAND_H_
