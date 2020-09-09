//
// Created by illia.ilin on 9/3/2020.
//

#include "ShowDueDateByPriorityCommand.h"

ShowDueDateByPriorityCommand::ShowDueDateByPriorityCommand(std::shared_ptr<TaskService> service, boost::gregorian::date date)
    : service_(service), date_(date) {
}

std::vector<TaskDTO> ShowDueDateByPriorityCommand::execute() {
  return service_->showDueDateByPriority(date_);
}
void ShowDueDateByPriorityCommand::accept(std::shared_ptr<Visitor> v) {
v->visitShowDueDateByPriorityCommand(*this);
}
