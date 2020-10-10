//
// Created by illia.ilin on 9/3/2020.
//

#include "ShowDueDateByLabelCommand.h"

ShowDueDateByLabelCommand::ShowDueDateByLabelCommand(std::shared_ptr<CoreAPIInterface> service, boost::gregorian::date date)
    : service_(service), date_(date) {
}
void ShowDueDateByLabelCommand::execute() {
  commandResult_=service_->showDueDateByLabel();

}
void ShowDueDateByLabelCommand::accept(std::shared_ptr<Visitor> v) {
v->visitShowDueDateByLabelCommand(*this);
}
std::vector<TaskDTO> ShowDueDateByLabelCommand::getCommandResult() {
  return commandResult_;
}
