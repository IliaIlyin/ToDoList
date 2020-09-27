//
// Created by illia.ilin on 8/31/2020.
//

#include "ShowDueDateByDateCommand.h"
ShowDueDateByDateCommand::ShowDueDateByDateCommand(std::shared_ptr<TaskService> service, boost::gregorian::date date)
    : service_(service), date_(date) {
}
void ShowDueDateByDateCommand::execute() {
  commandResult_=service_->showDueDateByDate();

}
void ShowDueDateByDateCommand::accept(std::shared_ptr<Visitor> v) {
v->visitShowDueDateByDateCommand(*this);
}
std::vector<TaskDTO> ShowDueDateByDateCommand::getCommandResult() {
  return commandResult_;
}

