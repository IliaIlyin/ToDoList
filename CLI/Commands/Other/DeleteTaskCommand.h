//
// Created by illia.ilin on 8/31/2020.
//

#ifndef TODOLIST_CLI_COMMANDS_DELETETASKCOMMAND_H_
#define TODOLIST_CLI_COMMANDS_DELETETASKCOMMAND_H_

#include "API/TaskService.h"
#include "Command.h"
#include <memory>

class DeleteTaskCommand : public Command<bool> {
 public:
  DeleteTaskCommand(std::shared_ptr<TaskService> service,const TaskID& id);
  bool execute() override;
  void accept(std::shared_ptr<Visitor> v) override;

 private:
  std::shared_ptr<TaskService> service_;
  TaskID id_;
};

#endif //TODOLIST_CLI_COMMANDS_DELETETASKCOMMAND_H_
