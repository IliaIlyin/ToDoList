//
// Created by illia.ilin on 8/31/2020.
//

#include "ShowDueDateByDateCommand.h"
ShowDueDateByDateCommand::ShowDueDateByDateCommand(std::shared_ptr<TaskService> service, boost::gregorian::date date)
    : service_(service), date_(date) {
}
std::vector<TaskDTO> ShowDueDateByDateCommand::execute() {
  return service_->showDueDateByDate(date_);
}
void ShowDueDateByDateCommand::accept(std::shared_ptr<Visitor> v) {
  v->visitShowDueDateByDateCommand(*this);
}
