//
// Created by illia.ilin on 9/3/2020.
//

#include "ShowDueDateByLabelCommand.h"

ShowDueDateByLabelCommand::ShowDueDateByLabelCommand(std::shared_ptr<TaskService> service, boost::gregorian::date date)
    : service_(service), date_(date) {
}
std::vector<TaskDTO> ShowDueDateByLabelCommand::execute() {
  return service_->showDueDateByLabel(date_);
}
void ShowDueDateByLabelCommand::accept(std::shared_ptr<Visitor> v) {
v->visitShowDueDateByLabelCommand(*this);
}
