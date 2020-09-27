//
// Created by illia.ilin on 9/3/2020.
//

#ifndef TODOLIST_CLI_COMMANDS_SHOW_SHOWTODAY_SHOWTODAYBYPRIORITYCOMMAND_H_
#define TODOLIST_CLI_COMMANDS_SHOW_SHOWTODAY_SHOWTODAYBYPRIORITYCOMMAND_H_

#include "Command.h"
#include "API/TaskService.h"
#include <boost/date_time/gregorian/gregorian.hpp>
#include <memory>
#include <vector>
#include "Visitor.h"

class ShowTodayByPriorityCommand : public Command{
 public:
  ShowTodayByPriorityCommand(std::shared_ptr<TaskService> service);
  void execute() override;
  void accept(std::shared_ptr<Visitor> v) override;
  std::vector<TaskDTO> getCommandResult();

 private:
  std::shared_ptr<TaskService> service_;

 private:
  std::vector<TaskDTO> commandResult_;
};

#endif //TODOLIST_CLI_COMMANDS_SHOW_SHOWTODAY_SHOWTODAYBYPRIORITYCOMMAND_H_
