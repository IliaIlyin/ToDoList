//
// Created by illia.ilin on 8/31/2020.
//

#ifndef TODOLIST_CLI_COMMANDS_SHOWALLBYLABELCOMMAND_H_
#define TODOLIST_CLI_COMMANDS_SHOWALLBYLABELCOMMAND_H_

#include "Command.h"
#include "ClientInterface.h"
#include <memory>
#include <vector>
#include "API/TaskDTO.h"
#include "Visitor.h"

class ShowAllByLabelCommand : public Command {

 public:
  ShowAllByLabelCommand(std::shared_ptr<ClientInterface> service);
  void execute() override;
  void accept(std::shared_ptr<Visitor> v) override;

  std::vector<TaskDTO> getCommandResult();

 private:
  std::shared_ptr<ClientInterface> service_;

 private:
  std::vector<TaskDTO> commandResult_;
};
#endif //TODOLIST_CLI_COMMANDS_SHOWALLBYLABELCOMMAND_H_
