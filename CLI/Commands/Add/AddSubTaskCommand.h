//
// Created by illia.ilin on 8/28/2020.
//

#ifndef TODOLIST_CLI_COMMANDS_ADDSUBTASKCOMMAND_H_
#define TODOLIST_CLI_COMMANDS_ADDSUBTASKCOMMAND_H_

#include "API/TaskService.h"
#include "Command.h"
#include "Visitor.h"
#include <memory>
class AddSubTaskCommand : public Command<bool> {

 public:
  AddSubTaskCommand(std::shared_ptr<TaskService> service, const TaskID &parent, const Task &child);
  bool execute() override;
  void accept(std::shared_ptr<Visitor> v) override;
 private:
  std::shared_ptr<TaskService> service_;
  TaskID parent_;
  Task child_;
};

#endif //TODOLIST_CLI_COMMANDS_ADDSUBTASKCOMMAND_H_
