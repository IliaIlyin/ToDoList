//
// Created by illia.ilin on 8/31/2020.
//

#ifndef TODOLIST_CLI_COMMANDS_SHOWDUEDATEBYDATECOMMAND_H_
#define TODOLIST_CLI_COMMANDS_SHOWDUEDATEBYDATECOMMAND_H_
#include "Command.h"
#include "API/CoreAPIInterface.h"
#include <boost/date_time/gregorian/gregorian.hpp>
#include <memory>
#include <vector>
#include "Visitor.h"

class ShowDueDateByDateCommand : public Command {
 public:
  ShowDueDateByDateCommand(std::shared_ptr<CoreAPIInterface> service, boost::gregorian::date date);
  void execute() override;
  void accept(std::shared_ptr<Visitor> v) override;
  std::vector<TaskDTO> getCommandResult();

 private:
  std::shared_ptr<CoreAPIInterface> service_;
  boost::gregorian::date date_;

 private:
  std::vector<TaskDTO> commandResult_;
};

#endif //TODOLIST_CLI_COMMANDS_SHOWDUEDATEBYDATECOMMAND_H_
