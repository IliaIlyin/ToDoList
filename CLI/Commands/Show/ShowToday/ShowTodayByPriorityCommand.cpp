//
// Created by illia.ilin on 9/3/2020.
//

#include "ShowTodayByPriorityCommand.h"
ShowTodayByPriorityCommand::ShowTodayByPriorityCommand(std::shared_ptr<ClientInterface> service)
    : service_(service) {
}
void ShowTodayByPriorityCommand::execute() {
  commandResult_ = service_->showTodayByPriority();

}
void ShowTodayByPriorityCommand::accept(std::shared_ptr<Visitor> v) {
  v->visitShowTodayPriorityCommand(*this);
}
std::vector<TaskDTO> ShowTodayByPriorityCommand::getCommandResult() {
  return commandResult_;
}

