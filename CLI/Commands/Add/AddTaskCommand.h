//
// Created by illia.ilin on 8/28/2020.
//

#ifndef TODOLIST_CLI_COMMANDS_ADDTASKCOMMAND_H_
#define TODOLIST_CLI_COMMANDS_ADDTASKCOMMAND_H_

#include "API/TaskService.h"
#include "Command.h"
#include "Visitor.h"
#include <memory>
class AddTaskCommand : public Command<bool> {

 public:
  AddTaskCommand(std::shared_ptr<TaskService> service, const Task &parent);
  bool execute() override;
  void accept(std::shared_ptr<Visitor> v) override;

 private:
  std::shared_ptr<TaskService> service_;
  Task parent_;
};

#endif //TODOLIST_CLI_COMMANDS_ADDTASKCOMMAND_H_
