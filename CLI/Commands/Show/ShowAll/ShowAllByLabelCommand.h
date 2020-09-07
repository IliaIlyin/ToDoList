//
// Created by illia.ilin on 8/31/2020.
//

#ifndef TODOLIST_CLI_COMMANDS_SHOWALLBYLABELCOMMAND_H_
#define TODOLIST_CLI_COMMANDS_SHOWALLBYLABELCOMMAND_H_

#include "Command.h"
#include "API/TaskService.h"
#include <memory>
#include <vector>

class ShowAllByLabelCommand: public Command<std::vector<TaskDTO>> {
 public:
  ShowAllByLabelCommand(std::shared_ptr<TaskService> service);
  std::vector<TaskDTO> execute() override;
  void accept(std::shared_ptr<Visitor> v) override;

 private:
  std::shared_ptr<TaskService> service_;
};
#endif //TODOLIST_CLI_COMMANDS_SHOWALLBYLABELCOMMAND_H_
