//
// Created by illia.ilin on 8/31/2020.
//

#ifndef TODOLIST_CLI_COMMANDS_COMPLETETASKCOMMAND_H_
#define TODOLIST_CLI_COMMANDS_COMPLETETASKCOMMAND_H_

#include "API/TaskService.h"
#include "Command.h"
#include "Visitor.h"
#include <memory>

class CompleteTaskCommand : public Command {
 public:
  CompleteTaskCommand(std::shared_ptr<TaskService> service, const TaskID &id);
  void execute() override;
  void accept(std::shared_ptr<Visitor> v) override;

  bool getCompleteTaskCommandResult() const;
 private:
  std::shared_ptr<TaskService> service_;
  TaskID task_id_;

 private:
  bool completeTaskCommandResult_;
};

#endif //TODOLIST_CLI_COMMANDS_COMPLETETASKCOMMAND_H_
