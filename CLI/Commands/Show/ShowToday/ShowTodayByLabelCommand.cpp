//
// Created by illia.ilin on 9/3/2020.
//

#include "ShowTodayByLabelCommand.h"
ShowTodayByLabelCommand::ShowTodayByLabelCommand(std::shared_ptr<TaskService> service)
    : service_(service) {
}
void ShowTodayByLabelCommand::execute() {
  commandResult_=service_->showTodayByLabel();

}
void ShowTodayByLabelCommand::accept(std::shared_ptr<Visitor> v) {
  v->visitShowTodayByLabelCommand(*this);
}
std::vector<TaskDTO> ShowTodayByLabelCommand::getCommandResult() {
  return commandResult_;
}

