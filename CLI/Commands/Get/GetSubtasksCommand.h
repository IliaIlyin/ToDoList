//
// Created by illia.ilin on 8/31/2020.
//

#ifndef TODOLIST_CLI_COMMANDS_GETSUBTASKSCOMMAND_H_
#define TODOLIST_CLI_COMMANDS_GETSUBTASKSCOMMAND_H_
#include "API/TaskService.h"
#include "Command.h"
#include <optional>
#include <vector>

class GetSubTaskCommand : public Command<std::optional<std::vector<TaskDTO>>> {
 public:
  GetSubTaskCommand(std::shared_ptr<TaskService> service, const TaskID &id);
  std::optional<std::vector<TaskDTO>> execute() override;
  void accept(std::shared_ptr<Visitor> v) override;

 private:
  std::shared_ptr<TaskService> service_;
  TaskID id_;
};

#endif //TODOLIST_CLI_COMMANDS_GETSUBTASKSCOMMAND_H_
