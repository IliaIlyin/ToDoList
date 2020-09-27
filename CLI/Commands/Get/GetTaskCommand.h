//
// Created by illia.ilin on 8/28/2020.
//

#ifndef TODOLIST_CLI_COMMANDS_GETTASKCOMMAND_H_
#define TODOLIST_CLI_COMMANDS_GETTASKCOMMAND_H_

#include "API/TaskService.h"
#include "Command.h"
#include "Visitor.h"
#include <optional>
class GetTaskCommand : public Command {

 public:
  GetTaskCommand(std::shared_ptr<TaskService> service, const TaskID &id);

 public:
  void execute() override;
  void accept(std::shared_ptr<Visitor> v) override;

  const std::optional<TaskDTO> &GetGetTaskCommandResult() const;
 private:
  std::shared_ptr<TaskService> service_;
  TaskID id_;

 private:
  std::optional<TaskDTO> getTaskCommandResult_;
};

#endif //TODOLIST_CLI_COMMANDS_GETTASKCOMMAND_H_
