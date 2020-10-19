//
// Created by illia.ilin on 9/3/2020.
//

#ifndef TODOLIST_CLI_COMMANDS_SHOW_SHOWTODAY_SHOWTODAYBYLABELCOMMAND_H_
#define TODOLIST_CLI_COMMANDS_SHOW_SHOWTODAY_SHOWTODAYBYLABELCOMMAND_H_

#include "Command.h"
#include "API/CoreAPIInterface.h"
#include <boost/date_time/gregorian/gregorian.hpp>
#include <memory>
#include <vector>
#include "Visitor.h"

class ShowTodayByLabelCommand : public Command {
 public:
  ShowTodayByLabelCommand(std::shared_ptr<CoreAPIInterface> service);
  void execute() override;
  void accept(std::shared_ptr<Visitor> v) override;
  std::vector<TaskDTO> getCommandResult();

 private:
  std::shared_ptr<CoreAPIInterface> service_;

 private:
  std::vector<TaskDTO> commandResult_;
};

#endif //TODOLIST_CLI_COMMANDS_SHOW_SHOWTODAY_SHOWTODAYBYLABELCOMMAND_H_
