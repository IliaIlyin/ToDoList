//
// Created by illia.ilin on 9/3/2020.
//

#include "ShowAllByPriorityCommand.h"
ShowAllByPriorityCommand::ShowAllByPriorityCommand(std::shared_ptr<TaskService> service) : service_(service){

}

void ShowAllByPriorityCommand::execute() {
  commandResult_=service_->showAllByPriority();

}
void ShowAllByPriorityCommand::accept(std::shared_ptr<Visitor> v) {
v->visitShowAllByPriorityCommand(*this);
}
std::vector<TaskDTO> ShowAllByPriorityCommand::getCommandResult() {
  return commandResult_;
}

