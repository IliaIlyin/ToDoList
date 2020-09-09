//
// Created by illia.ilin on 9/3/2020.
//

#ifndef TODOLIST_CLI_COMMANDS_SHOWALLBYDATECOMMAND_H_
#define TODOLIST_CLI_COMMANDS_SHOWALLBYDATECOMMAND_H_

#include "Command.h"
#include "API/TaskService.h"
#include <memory>
#include <vector>

 class ShowAllByDateCommand: public Command<std::vector<TaskDTO>> {
 public:
  ShowAllByDateCommand(std::shared_ptr<TaskService> service);
  std::vector<TaskDTO> execute() override;
  void accept(std::shared_ptr<Visitor> v) override;

  private:
   std::shared_ptr<TaskService> service_;
};

#endif //TODOLIST_CLI_COMMANDS_SHOWALLBYDATECOMMAND_H_
