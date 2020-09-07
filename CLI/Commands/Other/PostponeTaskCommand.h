//
// Created by illia.ilin on 8/31/2020.
//

#ifndef TODOLIST_CLI_COMMANDS_POSTPONETASKCOMMAND_H_
#define TODOLIST_CLI_COMMANDS_POSTPONETASKCOMMAND_H_

#include "Command.h"
#include "API/TaskService.h"
#include <boost/date_time/gregorian/gregorian.hpp>
#include <memory>
class PostponeTaskCommand : public Command<bool> {
 public:
  PostponeTaskCommand(std::shared_ptr<TaskService> service,const TaskID& id, const boost::gregorian::date & date);
  bool execute() override;
  void accept(std::shared_ptr<Visitor> v) override;
 private:
  std::shared_ptr<TaskService> service_;
  TaskID id_;
  boost::gregorian::date date_;
};

#endif //TODOLIST_CLI_COMMANDS_POSTPONETASKCOMMAND_H_
