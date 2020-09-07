//
// Created by illia.ilin on 9/3/2020.
//

#ifndef TODOLIST_CLI_COMMANDS_SHOWDUEDATEBYPRIORITYCOMMAND_H_
#define TODOLIST_CLI_COMMANDS_SHOWDUEDATEBYPRIORITYCOMMAND_H_

#include "Command.h"
#include "API/TaskService.h"
#include <boost/date_time/gregorian/gregorian.hpp>
#include <memory>
#include <vector>

class ShowDueDateByPriorityCommand: public Command<std::vector<TaskDTO>> {
 public:
  ShowDueDateByPriorityCommand(std::shared_ptr<TaskService> service,boost::gregorian::date date);
  std::vector<TaskDTO> execute() override;
  void accept(std::shared_ptr<Visitor> v) override;

 private:
  std::shared_ptr<TaskService> service_;
  boost::gregorian::date date_;
};


#endif //TODOLIST_CLI_COMMANDS_SHOWDUEDATEBYPRIORITYCOMMAND_H_
