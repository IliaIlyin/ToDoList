//
// Created by illia.ilin on 9/3/2020.
//

#include "ShowTodayByPriorityCommand.h"
ShowTodayByPriorityCommand::ShowTodayByPriorityCommand(std::shared_ptr<TaskService> service)
    : service_(service) {
}
std::vector<TaskDTO> ShowTodayByPriorityCommand::execute() {
  return service_->showTodayByPriority();
}
void ShowTodayByPriorityCommand::accept(std::shared_ptr<Visitor> v) {
v->visitShowTodayPriorityCommand(*this);
}
