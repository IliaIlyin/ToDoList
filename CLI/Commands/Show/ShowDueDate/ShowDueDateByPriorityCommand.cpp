//
// Created by illia.ilin on 9/3/2020.
//

#include "ShowDueDateByPriorityCommand.h"

ShowDueDateByPriorityCommand::ShowDueDateByPriorityCommand(std::shared_ptr<TaskService> service,
                                                           boost::gregorian::date date)
    : service_(service), date_(date) {
}
void ShowDueDateByPriorityCommand::execute() {
  commandResult_=service_->showDueDateByPriority();

}
void ShowDueDateByPriorityCommand::accept(std::shared_ptr<Visitor> v) {
  v->visitShowDueDateByPriorityCommand(*this);
}
std::vector<TaskDTO> ShowDueDateByPriorityCommand::getCommandResult() {
  return commandResult_;
}
